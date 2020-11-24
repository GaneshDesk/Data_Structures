//////////////////////////////////////////////////////////////////////////////////////////
//
//			Doubly Linear Linked List
//
//////////////////////////////////////////////////////////////////////////////////////////


#include<string.h>
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int		Data;
	struct node	*Next,*Prev;
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	AddFirst
//
//	Description:
//		This function adds node to Doubly Linear Linked List.
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////
int AddFirst(
				struct node **Head,
				int no
			)
{
	struct node  *NewNode = NULL;

	//
	//	Allocate new node.
	//
	NewNode = (struct node *)malloc(sizeof(struct node ));
	if (NULL == NewNode)
	{
		return 0;
	}

	//
	//	Fill the node with data.
	//
	NewNode -> Next = NULL;
	NewNode -> Data = no;
	NewNode -> Prev = NULL;

	//
	//	Prepend
	//
	if (NULL == *Head)
	{
		*Head = NewNode;
	}
	else
	{
		NewNode -> Next = *Head;
		(*Head) -> Prev = NewNode;
		*Head = NewNode;
	}

	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	AddLast
//
//	Description:
//		This function appends node in Doubly Linear Linked List.
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////

int AddLast (
				struct node **Head,
				int no
			)
{
	struct node *NewNode = NULL;

	struct node *Temp = NULL;

	Temp = *Head;

	//
	//	Allocate new node.
	//
	NewNode = (struct node *)malloc(sizeof(struct node ));
	if (NULL == NewNode)
	{
		return 0;
	}

	//
	//	Fill the node with data.
	//
	NewNode -> Next = NULL;
	NewNode -> Data = no;
	NewNode ->Prev = NULL;
	//
	//	Append
	//
	if (NULL == *Head)
	{
		*Head = NewNode;
	}
	else
	{
		while(Temp ->Next != NULL)
		{
			Temp = Temp -> Next;
		}
		Temp -> Next = NewNode;
		NewNode ->Prev = Temp;
	}

	return 1;

}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	Display
//
//	Description:
//		This function displays Doubly Linear Linked List.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////

void Display(
				struct node *Head
			)
{
	while(NULL != Head)
	{
		printf("|%d|-> ",Head -> Data);
		Head = Head -> Next;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	CountNode
//
//	Description:
//		This function counts nodes in Doubly Linear Linked List.
//
//	Returns:
//		int
//		Number of nodes in generic list
//
///////////////////////////////////////////////////////////////////////////////////////////

int CountNode (
				struct node *Head
				)
{
	// Variable for maintaining number of nodes
	int Count = 0;


	// Traverse the linked list till end
	while(NULL != Head)
	{
		Count++;
		Head = Head -> Next;
	}
	return Count;
}

////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	SearchFirstOccurance
//
//	Description:
//		This function search perticular data in Doubly Linear Linked List.
//		and return the position at which data is found.
//
//	Returns:
//		int
//		Position at which data is found in generic list
//
///////////////////////////////////////////////////////////////////////////
int SearchFirstOccurance(
							struct node *Head,
							int no						// Data to be searched 
						)
{
	int Count = 0;

	// Traverse the linked list till end
	while( Head != NULL )
	{
		++Count;

		// If data matches with the input value
		if(Head -> Data == no)
		{
			// Break the loop as we get the first occurance
			return Count; 
		}
		Head = Head ->Next;
	}

	return -1;
}

////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	SearchAllOccurance
//
//	Description:
//		This function search perticular data in Doubly Linear Linked List.
//		and return number of occurances of that data.
//
//	Returns:
//		int
//		Number of times data is found in generic list
//
///////////////////////////////////////////////////////////////////////////

int SearchAllOccurance( 
							struct node *Head,
							int no
					 )
{
	int Count = 0;

	// Traverse the linked list till end
	while( Head != NULL )
	{
		// If data matches with the input value
		if(Head -> Data == no)
		{
			++Count; 
		}
		Head = Head -> Next;
	}

	return Count;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	InsertAtPosition
//
//	Description:
//		This function adds node at specified position in Doubly Linear Linked List.
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////

int InsertAtPosition(
						struct node **Head,
						int pos,							// Position at which node is inserted 
						int no								// Data member of the node
					)
{
	int i = 1;
	
	struct node *temp = NULL;
	struct node *NewNode = NULL;
	
	// If linked list is empty
	if( *Head == NULL )
	{ 
		return 0;
	}
	else if( pos == 1 )
	{
		AddFirst(Head,no); 
	}
	else if(pos == (CountNode(*Head)) + 1)
	{
		AddLast(Head,no); 
	}
	else if( (pos > CountNode(*Head)))
	{
		return 0;
	}
	else
	{
		temp = *Head;
		NewNode = (struct node*)malloc(sizeof(struct node));
		if (NULL == NewNode)
		{
			return 0;
		}

		//
		//	Fill the node with data.
		//
		NewNode -> Next = NULL;
		NewNode -> Data = no;
		NewNode -> Prev = NULL;

		while(i < pos - 1)
		{
			temp = temp -> Next;
			++i;
		}
		NewNode -> Next = temp -> Next;
		temp->Next->Prev = NewNode;
		temp -> Next = NewNode;
		NewNode->Prev = temp;
	}

	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteFirst
//
//	Description:
//		This function removes first node from Doubly Linear Linked List.
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////

int DeleteFirst(
					struct node **Head
				)
{
	struct node  *temp = NULL;
	temp = *Head;

	// If linked list is empty
	if(*Head == NULL)
	{
		return 0;
	}
	else
	{
		*Head = temp -> Next;
		(*Head) ->Prev = NULL;
		free(temp);
	}
	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteLast
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//						NONE
//	Description:
//		This function removes last node from Doubly Linear Linked List.
//
//	Returns:
//		intEAN
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////

int DeleteLast( 
				struct node **Head
			   )
{
	struct node  *temp1,*temp2;
	temp1 = temp2 = *Head;

	// If linked list is empty
	if(*Head == NULL)
	{
		return 0;
	}
	else
	{
		while(temp1 -> Next != NULL)
		{
			temp2 = temp2 -> Next;
			temp1 = temp2 -> Next;
		}
		temp2 -> Next = NULL;
		free(temp1);
	}

	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteAtPosition
//
//	Description:
//		This function deletes node from specified position in Doubly Linear Linked List.
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////
int DeleteAtPosition(
						struct node **Head,
						int pos
					)
{
	if(pos > (CountNode(*Head)))
	{
		return 0;
	}
	else if(pos == 1)
	{
		DeleteFirst(Head);
	}
	else if(pos == (CountNode(*Head)))
	{
		DeleteLast(Head);
	}
	else
	{
		int i = 0;
		struct node *temp = *Head,*t;

		for(i = 0; i < pos - 1; i++)
		{
			t = temp;
			temp = temp -> Next;
		}
		t -> Next = temp -> Next;
		temp -> Next ->Prev = t;

		free( temp );
	}
	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DisplayReverse
//
//	Description:
//		Function which display the Doubly Linear Linked List in reverse manner.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////

int DisplayReverse( 
					struct node *Head
				   )
{
	struct node *Temp;

	if(Head == NULL) 
	{
		return 1;
	}

	while(Head->Next != NULL)
	{
		Head = Head ->Next;
	}
	
	Temp = Head;

	while(Temp != NULL)
	{ 
		printf("|%d|<=>",Temp -> Data);
		Temp = Temp -> Prev;
	}

	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Entry point function
//	Function Date			:	07/11/2013
//	Function Author		:	Piyush Khairnar
//	Brief Description	:	
//
///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	struct node *first = NULL;
	AddFirst(&first,10);
	AddFirst(&first,20);
	AddFirst(&first,30);
	AddFirst(&first,40);
	AddFirst(&first,50);
	AddFirst(&first,60);
	AddFirst(&first,70);

	Display(first);

	AddLast(&first,80);
	AddLast(&first,90);
	AddLast(&first,10);
	printf("\n");
	Display(first);

	InsertAtPosition(&first,4,88);
	printf("\n");
	Display(first);

	printf("\n20 is occured %d number of times\n",SearchAllOccurance(first,20));

	printf("\n30 is occuserd at position %d\n",SearchFirstOccurance(first,30));

	DeleteFirst(&first);
	printf("\n");
	Display(first);

	DeleteLast(&first);
	printf("\n");
	Display(first);

	DeleteAtPosition(&first,4);
	printf("\n");
	Display(first);
printf("Linked list inreverse order is \n");
	DisplayReverse(first);
	return 0;
}