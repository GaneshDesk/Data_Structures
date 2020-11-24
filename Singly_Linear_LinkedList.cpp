//////////////////////////////////////////////////////////////////////////////////////////
//
//			Singly Linear Linked List
//
//////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

//
// This is linked list struct node
//
struct node
{
	int		Data;
	struct node	*Next;
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	Display
//
//	Description:
//		This function displays Singly Linear Linked List.
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
		printf("|%d| -> ",Head -> Data);
		Head = Head -> Next;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	CountNode
//
//	Description:
//		This function counts nodes in Singly Linear Linked List.
//
//	Returns:
//		int
//		Number of nodes in generic list
//
///////////////////////////////////////////////////////////////////////////////////////////

int CountNode ( 
				struct node * Head
			   )
{
	// Variable for maintaining number of nodes
	int Count = 0;

	// Traverse the linked lisstruct nodetill end
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
//		This function search perticular data in Singly Linear Linked List.
//		and return the position astruct nodewhich data is found.
//
//	Returns:
//		int
//		Position astruct nodewhich data is found in generic list
//
///////////////////////////////////////////////////////////////////////////
int SearchFirstOccurance(
							struct node *Head,
							int no
						)
{
	int Count = 0;

	// Traverse the linked lisstruct nodetill end
	while( Head != NULL )
	{
		++Count;

		// If data matches with the inpustruct nodevalue
		if(Head -> Data == no)
		{
			// Break the loop as we gestruct nodethe firsstruct nodeoccurance
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
//		This function search perticular data in Singly Linear Linked List.
//		and return number of occurances of thastruct nodedata.
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

	// Traverse the linked lisstruct nodetill end
	while( Head!= NULL )
	{
		// If data matches with the inpustruct nodevalue
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
//	Function Name			:	AddFirst
//
//	Description:
//		This function adds node to Singly Linear Linked List.
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
	NewNode -> Next = NULL;
	NewNode -> Data = no;

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
		*Head = NewNode;
	}

	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	AddLast
//
//	Description:
//		This function appends node inn Singly Linear Linked List
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////

int AddLast(
				struct node **Head,
				int no
				)
{
	struct node *NewNode;
	struct node *Temp;

	Temp = *Head;

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
	if (NULL == *Head)
	{
		*Head = NewNode;
	}
	else
	{
		while(Temp -> Next != NULL)
		{
			Temp = Temp -> Next;
		}

		Temp -> Next = NewNode;
	}

	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	InsertAtPosition
//
//	Description:
//		This function adds node astruct nodespecified position in Singly Linear Linked List.
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////

int InsertAtPosition( 
						struct node ** Head,
						int no,
						int pos
													)
{
	int i = 1;
	
	struct node *temp = NULL;
	struct node *NewNode = NULL;
	
	// If linked lisstruct nodeis empty
	if( *Head == NULL  && pos != 1) 
	{ 
		return 0;
	}
	else if( pos == 1 )
	{
		AddFirst(Head , no); 
	}
	else if(pos == (CountNode(*Head)) + 1)
	{
		AddLast(Head , no); 
	}
	else if( (pos > CountNode(*Head) + 1))
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
		NewNode -> Next = NULL;
		NewNode -> Data = no;

		while(i < pos - 1)
		{
			temp = temp -> Next;
			++i;
		}

		NewNode -> Next = temp -> Next;
		temp -> Next = NewNode;
	}

	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteFirst
//
//	Description:
//		This function removes firsstruct node from Singly Linear Linked List.
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
	struct node *temp;
	temp = *Head;

	// If linked lisstruct nodeis empty
	if(*Head == NULL)
	{
		return 0;
	}
	else
	{
		*Head = temp -> Next;
		free(temp);
	}
	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteLast
//
//	Description:
//		This function removes last node from Singly Linear Linked List.
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////

int DeleteLast(
				struct node **Head
			   )
{
	struct node *temp1,*temp2;
	temp1 = temp2 = *Head;

	// If linked lisstruct nodeis empty
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
//		This function deletes node from specified position in Singly Linear Linked List.
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
		struct node *temp = *Head,*t = *Head;

		for(i = 1; i < pos - 1; i++)
		{	
			t = t -> Next;
			temp = t -> Next;
		}
		t -> Next = temp -> Next;
		free( temp );
	}

	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	ReverseList
//	Description:
//		This function reverse Singly Linear Linked List.
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////

int ReverseList( struct node ** Head )
{
	struct node *prev = NULL;
	struct node *current = *Head;
	struct node *next = NULL;

	// If linked list is empty
	if(*Head == NULL)
	{
		return 0;
	}

	while(current != NULL)
	{
		next = current -> Next;
		current -> Next = prev;
		prev = current;
		current = next;
	}
	*Head = prev;

	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	Middle_Element
//	Description:
//		This function Middle element from Singly Linear Linked List.
//
//	Returns:
//		int
//		If the function succeeds, the return data of middle element.
//		If the function fails, the return value is 0.
//
///////////////////////////////////////////////////////////////////////////////////////////

int Middle_Element(struct node *Head)
{
	struct node *temp = Head ->Next;

	if(Head == NULL)
	{
		return 0;
	}
	while(temp != NULL && temp -> Next != NULL) 
	{
		temp = temp -> Next -> Next;
		Head = Head -> Next;
	}

	return Head -> Data;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Entry poinstruct nodefunction
//
///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	struct node *first = NULL;

	printf("\n-------------------------------------------------------------\n");
	printf("\t\tLinear Singly Linked List");
	printf("\n-------------------------------------------------------------\n");

	int no=10;

	printf("Add element at first position \n");
	Display(first);
	printf("\n");
	AddFirst(&first,no);
	no++;
	
	printf("Add element at first position \n");
	Display(first);
	printf("\n");
	AddFirst(&first,no);
	no++;
	
	printf("Add element at first position \n");
	Display(first);
	printf("\n");
	AddFirst(&first,no);
	no++;
	
	printf("Add element at first position \n");
	Display(first);
	printf("\n");
	AddFirst(&first,no);

	AddLast(&first,50);
	printf("Add element at last position \n");
	Display(first);
	printf("\n");

	AddLast(&first,60);
	printf("Add element at last position \n");
	Display(first);
	printf("\n");

	printf("\nOccurance of 10 is %d number of times\n",SearchAllOccurance(first,10));

	printf("\nFirst Occurance of 10 is at %d\n",SearchFirstOccurance(first,10));


	InsertAtPosition(&first,55,3);
	printf("Insert position at position 3\n");
	Display(first);
	printf("\n");
	

	DeleteFirst(&first);
	printf("Delete first element\n");
	Display(first);
	printf("\n");

	DeleteLast(&first);
	printf("Delete last element\n");
	Display(first);
	printf("\n");
	
	DeleteAtPosition(&first,3);
	printf("Delete element at position 3\n");
	Display(first);
	printf("\n");
	
	ReverseList(&first);
	printf("\n");
	Display(first);

	return 0;
}