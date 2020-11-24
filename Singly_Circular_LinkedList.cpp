//////////////////////////////////////////////////////////////////////////////////////////
//
//			Singly circular Linked List
//
//////////////////////////////////////////////////////////////////////////////////////////

//
//		File inclusion
//
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int	Data;
	struct node	*next;
};


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	AddToFirst
//
//	Description:
//		This function adds node to Singly Circular Linked List.
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////

int AddToFirst (
				struct node **Head,
				struct node **Tail,
				int data
				)
{
	struct node *NewNode;

	//
	//	Allocate new node.
	//
	NewNode = (struct node *)malloc(sizeof(struct node));
	if (NULL == NewNode)
	{
		return 0;
	}

	//
	//	Fill the node with data.
	//
	NewNode -> next = NULL;
	NewNode -> Data = data;

	//
	//	Prepend
	//
	if (NULL == *Head && *Tail == NULL)
	{

		*Head = NewNode;
		*Tail = NewNode;
		(*Tail) -> next = *Head;
	}
	else
	{
		NewNode -> next = *Head;
		*Head = NewNode;
		(*Tail) ->next = NewNode; 
	}

	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	Display
//
//	Description:
//		This function displays Singly Circular Linked List.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////

void Display(
				struct node *Head,
				struct node *Tail
			)
{
	do
	{
		printf("|%d| -> ",Head->Data);
		Head = Head -> next;
	}while(Head != Tail -> next);
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	AddToLast
//
//	Description:
//		This function appends in Singly Circular Linked List.
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////

int AddToLast (
				struct node **Head,
				struct node **Tail,
				int no
				)
{
	struct node *NewNode;

	struct node *pTempNode;
	pTempNode = *Head;

	//
	//	Allocate new node.
	//
	NewNode = (struct node *)malloc(sizeof(struct node));
	if (NULL == NewNode)
	{
		return 0;
	}

	//
	//	Fill the node with data.
	//
	NewNode -> next = NULL;
	NewNode -> Data = no;

	//
	//	Append
	//
	if (NULL == *Head && *Tail == NULL)
	{
		*Head = NewNode;
		*Tail = NewNode;
		(*Tail) -> next = *Head;
	}
	else
	{
		(*Tail) -> next = NewNode;
		*Tail = NewNode;
		(*Tail) -> next = *Head;
	}

	return 1;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	CountNode
//
//	Description:
//		This function counts nodes in Singly Circular Linked List.
//
//	Returns:
//		int
//		Number of nodes in generic list
//
///////////////////////////////////////////////////////////////////////////////////////////

int CountNode ( 
				struct node *Head,
				struct node *Tail
			)
{
	// Variable for maintaining number of nodes
	int CountNode = 0;

	do
	{
		CountNode++;
		Head = Head -> next;
	}while(Head != Tail -> next);

	return CountNode;
}

////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	SearchFirstOccurance
//
//	Description:
//		This function search perticular data in Singly Circular Linked List.
//		and return the position at which data is found.
//
//	Returns:
//		int
//		Position at which data is found in generic list
//
///////////////////////////////////////////////////////////////////////////
int SearchFirstOccurance(
							struct node *Head,
							struct node *Tail,
							int no
														)
{
	int CountNode = 0;

	// Traverse the linked list till end
	do
	{
		CountNode++;
		if(Head -> Data == no)
		{
			// Break the loop as we get the first occurance
			return CountNode; 
		}
		Head = Head -> next;
	}while(Head != Tail->next);

	return -1;
}

////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	SearchAllOccurance
//
//	Description:
//		This function search perticular data in Singly Circular Linked List.
//		and return number of occurances of that data.
//
//	Returns:
//		int
//		Number of times data is found in generic list
//
///////////////////////////////////////////////////////////////////////////
int SearchAllOccurance(
						struct node *Head,
						struct node *Tail,
						int no
						)
{
	int CountNode = 0;

	// Traverse the linked list till end
	do
	{
		if(Head -> Data == no)
		{
			CountNode++; 
		}
		Head = Head -> next;
	}while(Head != Tail->next);

	return CountNode;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	InsertAtPosition
//
//	Description:
//		This function adds node at specified position in Singly Circular Linked List.
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////

int InsertAtPosition( 
						struct node ** Head,
						struct node ** Tail,
						int pos,
						int no
					)
{
	int i = 1;
	
	struct node *temp = NULL;
	struct node *NewNode = NULL;
	
	// If linked list is empty
	if( *Head == NULL && *Tail == NULL)
	{ 
		return 0;
	}
	
	else if( pos == 1 )
	{
		AddToFirst(Head,Tail,no); 
	}
	else if(pos == (CountNode(*Head,*Tail)) + 1)
	{
		AddToLast(Head,Tail,no); 
	}
	else if( (pos > CountNode(*Head,*Tail)))
	{
		return 0;
	}
	else
	{
		temp = *Head;
		NewNode = (struct node *)malloc(sizeof(struct node ));
		if (NULL == NewNode)
		{
			return 0;
		}

		//
		//	Fill the node with data.
		//
		NewNode -> next = NULL;
		NewNode -> Data = no;

		while(i < pos - 1)
		{
			temp = temp -> next;
			++i;
		}
		NewNode -> next = temp -> next;
		temp -> next = NewNode;
	}

	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteFromFirst
//
//	Returns:
//		intEAN
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////

int DeleteFromFirst(
						struct node **Head,
						struct node **Tail	
					)
{
	struct node *temp;
	temp = *Head;

	// If linked list is empty
	if(*Head == NULL)
	{
		return 0;
	}
	else
	{
		(*Head) = temp -> next;
		free(temp);
	}
	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteFromLast
//
//	Description:
//		This function removes last node from Singly Circular Linked List.
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////

int DeleteFromLast(
					struct node ** Head,
					struct node ** Tail
				   )
{
	struct node *temp1,*temp2;
	temp1 = *Head;
	temp2 = *Tail;

	// If linked list is empty
	if(*Head == NULL && *Tail == NULL)
	{
		return 0;
	}
	else
	{
		while(temp1 -> next != temp2)
		{
			temp1 = temp1 -> next;
		}

		free(temp2);
		*Tail = temp1;
		temp1 -> next = *Head;
	}

	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteAtPosition
//
//	Description:
//		This function deletes node from specified position in Singly Circular Linked List.
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////

int DeleteAtPosition(
						struct node ** Head,
						struct node ** Tail,
						int pos
					)
{
	if(pos > (CountNode(*Head,*Tail)))
	{
		return 0;
	}
	else if(pos == 1)
	{
		DeleteFromFirst(Head,Tail);
	}
	else if(pos == (CountNode(*Head,*Tail)))
	{
		DeleteFromLast(Head,Tail);
	}
	else
	{
		int i = 0;
		struct node *temp = *Head,*t;

		for(i = 0; i < pos - 1; i++)
		{
			t = temp;
			temp = temp -> next;
		}
		t -> next = temp -> next;
		temp -> next = NULL;
		free( temp );
	}

	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Entry point function
//
///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	int bRet;

	struct node *first = NULL;
	struct node *last = NULL;

	int no;

	printf("\n-------------------------------------------------------------\n");
	printf("\t\tCircular Singly Linked List");
	printf("\n-------------------------------------------------------------\n");
	no = 25;
	AddToLast(&first,&last,10);
	AddToLast(&first,&last,20);
	AddToLast(&first,&last,30);
	AddToLast(&first,&last,40);


	Display(first,last);
	printf("\n");

	no = 10;
	AddToFirst(&first,&last,no);
	no++;

	Display(first,last);
	printf("\n");

	AddToFirst(&first,&last,no);
	no++;
	Display(first,last);
	printf("\n");

	AddToFirst(&first,&last,no);
	no++;
	AddToFirst(&first,&last,no);
	no++;

	Display(first,last);
	printf("\n");

	no = 25;
	AddToLast(&first,&last,no);
	Display(first,last);
	printf("\n");

	no = 11;
	printf("\nNumber of node in linked list are %d",CountNode(first,last));

	printf("\nElement 11 is fount at position ",SearchFirstOccurance(first,last,no));
	no = 25;
	printf("\nElement 11 is fount at position ",SearchAllOccurance(first,last,no));

	DeleteFromFirst(&first,&last);
	Display(first,last);
	printf("\n");

	DeleteFromLast(&first,&last);
	Display(first,last);
	printf("\n");

	InsertAtPosition(&first,&last,3,27);
	printf("\n\nafter insertion\n");
	Display(first,last);
	printf("\n");

	DeleteAtPosition(&first,&last,3);
	printf("\n\nafter insertion\n");
	Display(first,last);
	printf("\n");

	return 0;
}