//////////////////////////////////////////////////////////////////////////////////////////
//
//			Doubly Circular Linked List
//
//////////////////////////////////////////////////////////////////////////////////////////


#include<string.h>
#include<iostream>

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
//		This function adds node to Doubly Circular Linked List.
//
//	Returns:
//		intEAN
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////
int AddFirst (
				struct node **Head,
				struct node **Tail,
				int no
			)
{
	struct node *NewNode = NULL;

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
	NewNode->Next = NULL;
	NewNode->Data = no;

	//
	//	Prepend
	//
	if (NULL == *Head && *Tail == NULL)
	{
		*Head = NewNode;
		*Tail = NewNode;
		(*Tail) -> Next = *Head;
	}
	else
	{
		NewNode -> Next = *Head;
		*Head = NewNode;
		(*Tail) ->Next = NewNode; 
	}

	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	AddLast
//
//	Description:
//		This function appends node to Doubly Circular Linked List.
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////

int AddLast (
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
	NewNode -> Next = NULL;
	NewNode -> Data = no;

	//
	//	Append
	//
	if (NULL == *Head && *Tail == NULL)
	{
		*Head = NewNode;
		*Tail = NewNode;
		(*Tail) ->Next = *Head;
	}
	else
	{
		(*Tail) -> Next = NewNode;
		NewNode ->Prev = (*Tail);
		*Tail = NewNode;
		(*Tail) -> Next = *Head;
	}

	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	CountNode
//
//	Description:
//		This function counts nodes in Doubly Circular Linked List.
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

	int Count = 0;

	do
	{
		Count++;
		Head = Head -> Next;
	}while(Head != Tail->Next);

	return Count;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	Display
//
//	Description:
//		This function displays Doubly Circular Linked List.
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
		printf("|%d| -> ",Head -> Data);
		Head = Head -> Next;
	}while(Head != Tail->Next);
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	InsertAtPosition
//
//	Description:
//		This function adds node at specified position in Doubly Circular Linked List.
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////
int InsertAtPosition(
						struct node **Head,
						struct node **Tail,
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
		AddFirst(Head,Tail,no); 
	}
	else if(pos == (CountNode(*Head,*Tail)) + 1)
	{
		AddLast(Head,Tail,no); 
	}
	else if( (pos > CountNode(*Head,*Tail)))
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
//		This function removes first node from Doubly Circular Linked List
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////
int DeleteFirst(
					struct node **Head,
					struct node **Tail
				)
{
	struct node *temp = NULL;
	temp = *Head;

	// If linked list is empty
	if(*Head == NULL)
	{
		return 0;
	}
	else
	{
		*Head = temp -> Next;
		(*Tail)->Next = *Head;
		(*Head) ->Prev = *Tail;
		free(temp);
	}
	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteLast
//
//	Description:
//		This function removes last node from Doubly Circular Linked List
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////

int DeleteLast(
							struct node **Head,
							struct node **Tail
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
		while(temp1 -> Next != temp2)
		{
			temp1 = temp1 -> Next;
		}

		free(temp2);
		*Tail = temp1;
		temp1 -> Next = *Head;

	}

	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteAtPosition
//
//	Description:
//		This function deletes node from specified position in Doubly Circular Linked List.
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////

int DeleteAtPosition(
						struct node **Head,
						struct node **Tail,
						int pos
					)
{
	if(pos > (CountNode(*Head,*Tail)))
	{
		return 0;
	}
	else if(pos == 1)
	{
		DeleteFirst(Head,Tail);
	}
	else if(pos == (CountNode(*Head,*Tail)))
	{
		DeleteLast(Head,Tail);
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
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//						NONE
//	Description:
//		Function which display the list in reverse manner.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////

int DisplayReverse(
					struct node *Head,
					struct node *Tail
 				   )
{
	struct node *temp = Tail;

	if(Head == NULL) 
	{
		return 1;
	}
	else
	{
		do
		{
			printf("|%d|<=>",temp -> Data);
			temp = temp -> Prev;
		}while(temp != (Head) -> Prev);
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	SearchFirstOccurance
//
//	Description:
//		This function search perticular data in Doubly Circular Linked List.
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
	int Count = 0;

	// Traverse the linked list till end
	do
	{
		Count++;
		if(Head -> Data == no)
		{
			// Break the loop as we get the first occurance
			return Count; 
		}
		Head = Head -> Next;
	}while(Head != Tail->Next);

	return -1;
}

////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	SearchAllOccurance
//
//	Description:
//		This function search perticular data in Doubly Circular Linked List.
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
	int Count = 0;

	// Traverse the linked list till end
	do
	{
		if(Head -> Data == no)
		{
			Count++; 
		}
		Head = Head -> Next;
	}while(Head != Tail->Next);

	return Count;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Entry point function
//
///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	struct node *first = NULL;
	struct node *last = NULL;

	AddFirst(&first,&last,10);
	AddFirst(&first,&last,10);
	AddFirst(&first,&last,10);

	Display(first,last);
	printf("\n");

	AddLast(&first,&last,20);
	AddLast(&first,&last,30);
	AddLast(&first,&last,40);


	Display(first,last);
	printf("\n");

	printf("10 occurs %d number of times \n",SearchAllOccurance(first,last,10));
	printf("20 occurs at %d\n",SearchFirstOccurance(first,last,20));

	InsertAtPosition(&first,&last,3,88);
	Display(first,last);
	printf("\n");

	DeleteFirst(&first,&last);
	Display(first,last);
	printf("\n");

	DeleteLast(&first,&last);
	Display(first,last);
	printf("\n");

	DeleteAtPosition(&first,&last,3);
	Display(first,last);
	printf("\n");

	DisplayReverse(first,last);

	return 0;
}