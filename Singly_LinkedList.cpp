#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//
//	This is a library of linked singly linked list
//

struct node
{
	int data;
	struct node*next;
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertFirst
//	Parameters:
//
//		[IN/OUT] struct node **first.
//		Holds head pointer of list.
//
//		[IN]int no.
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node to list.
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is -1.
//
///////////////////////////////////////////////////////////////////////////////////////////

int
InsertFirst (
								struct node **first,		// Address of first node
								int no							// it is data element
						)
{
	struct node *newnode;

	//
	//	Allocate new node.


	//
	newnode = (struct node *)malloc(sizeof(struct node));
	if (NULL == newnode)
	{
		return -1;
	}

	//
	//	Fill the node with data.
	//
	memset(newnode, 0, sizeof(struct node));
	newnode->next = NULL;
	newnode->data = no;

	//
	//	Prepend
	//
	if (NULL == *first)
	{
		*first = newnode;
	}
	else
	{
		newnode -> next = *first;
		*first = newnode;
	}

	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	InsertLast
//	Parameters:
//
//		[IN/OUT] struct node **first.
//		Head pointer of the existing list.
//
//		[IN] int no
//		Number is to be appended to an existing list.
//
//	Description:
//		This function appends specified linked list to
//		specific linked list.
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is -1.
//
///////////////////////////////////////////////////////////////////////////////////////////


int
InsertLast (
							struct node **first,
							int no
				)
{
	struct node *newnode;

	struct node *pTempNode;
	pTempNode = *first;



	//
	//	Allocate new node.
	//
	newnode = (struct node *)malloc(sizeof(struct node));
	if (NULL == newnode)
	{
		return -1;
	}

	//
	//	Fill the node with data.
	//
	memset(newnode, 0, sizeof(struct node));
	newnode -> next = NULL;
	newnode -> data = no;

	//
	//	Append
	//
	if (NULL == *first)
	{
		*first = newnode;
	}
	else
	{
		while(pTempNode -> next != NULL)
		{
			pTempNode = pTempNode -> next; 
		}
		pTempNode -> next = newnode;
	}

	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DisplayGenList
//	Parameters:
//			[IN] struct node *first.
//			Holds head pointer of list.
//
//	Description:
//		This function displays linked list.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////


void
DisplayGenList(
						struct node *first
			)
{
	while(NULL != first)
	{
		printf("| %d |->",first->data);
		first = first -> next;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	CountNode
//	Parameters:
//			[IN] struct node *first.
//			Holds head pointer of list.
//
//	Description:
//		This function counts nodes in linked list.
//
//	Returns:
//		int
//		Number of nodes in linked list
//
///////////////////////////////////////////////////////////////////////////////////////////


int CountNode (
							struct node *first
					   )
{
	// Variable for maintaining number of nodes
	int CountNode = 0;

	// Traverse the linked list till end
	while(NULL != first)
	{
		CountNode++;
		first = first -> next;
	}
	return CountNode;
}

////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	SearchFirstOccurance
//	Parameters:
//			[IN] struct node *first.
//			Holds head pointer of list.
//
//			[IN] struct node data.
//			Holds head data to be searched.
//
//	Description:
//		This function search perticular data in linked list.
//		and return the position at which data is found.
//
//	Returns:
//		int
//		Position at which data is found in linked list
//
///////////////////////////////////////////////////////////////////////////

int SearchFirstOccurance(
										struct node *first,
										int data						// Data to be searched 
								)
{
	int CountNode = 0;
	 int pos = -1;

	// Traverse the linked list till end
	while( first != NULL )
	{
		++CountNode;

		// If data matches with the input value
		if(first -> data == data)
		{
			// Break the loop as we get the first occurance
			
			 pos = CountNode;
		}
		first = first ->next;
	}

	return pos;
}

////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	SearchAllOccurance
//	Parameters:
//			[IN] struct node *first.
//			Holds head pointer of list.
//
//			[IN] int data.
//			Holds head data to be searched.
//
//	Description:
//		This function search perticular data in linked list.
//		and return number of occurances of that data.
//
//	Returns:
//		int
//		Number of times data is found in linked list
//
///////////////////////////////////////////////////////////////////////////


int SearchAllOccurance( 
									struct node *first,
									int data
								)
{
	int CountNode = 0;

	// Traverse the linked list till end
	while( first!= NULL )
	{
		// If data matches with the input value
		if(first -> data == data)
		{ 
			++CountNode; 
		}
		first = first -> next;
	}

	return CountNode;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	InsertAtPosition
//	Parameters:
//
//		[IN/OUT] struct node **first.
//		Holds head pointer of list.
//
//		[IN] int pos.
//		Holds the the position.
//
//		[IN] int no.
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node at specified position in linked list.
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is -1.
//
///////////////////////////////////////////////////////////////////////////////////////////


int InsertAtPosition( 
									struct node **head, 
									int pos,							// Position at which node is inserted 
									int no								// Data member of the node
								)
{
	int i = 1;
	
	struct node *temp = NULL;
	struct node *newnode = NULL;
	
	// If linked list is empty
	if( *head == NULL )
	{ 
		return -1;
	}
	
	else if( pos == 1 )
	{
		InsertFirst( head, no ); 
	}
	else if(pos == (CountNode( *head )) + 1)
	{
		InsertLast( head, no ); 
	}
	else if( (pos > CountNode(*head) + 1))
	{
		return -1;
	}
	else
	{
		temp = ( *head );			// 
		newnode = (struct node *)malloc(sizeof(struct node ));
		if (NULL == newnode)
		{
			return -1;
		}

		//
		//	Fill the node with data.
		//
		memset(newnode, 0, sizeof(struct node));
		newnode -> next = NULL;
		newnode -> data = no;

		while(i < pos - 1)
		{
			temp = temp -> next;
			++i;
		}
		newnode -> next = temp -> next;
		temp -> next = newnode;
	}

	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteFirst
//
//	Parameters:
//
//		[IN/OUT] struct node **first.
//		Head pointer of the existing list.
//
//	Description:
//		This function removes first node from linked list
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is -1.
//
///////////////////////////////////////////////////////////////////////////////////////////


int DeleteFirst(
											struct node **first
							)
{
	struct node *temp;
	temp = ( *first);

	// If linked list is empty
	if((*first) == NULL)
	{
		return -1;
	}
	else
	{
		(*first) = temp -> next;
		free(temp);
	}
	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteLast
//	Parameters:
//
//		[IN/OUT] struct node **first.
//		Head pointer of the existing list.
//
//	Description:
//		This function removes last node from linked list
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is -1.
//
///////////////////////////////////////////////////////////////////////////////////////////


int DeleteLast(
											struct node **first
								)
{
	struct node *temp1,*temp2;
	temp1 = temp2 = ( *first );

	// If linked list is empty
	if((*first) == NULL)
	{
		return -1;
	}
	else
	{
		while(temp1 -> next != NULL)
		{
			temp2 = temp2 -> next;
			temp1 = temp2 -> next;
		}
		temp2 -> next = NULL;
		free(temp1);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	RemoveAtPosition
//	Parameters:
//
//		[IN/OUT] struct node **first.
//		Holds head pointer of list.
//
//		[IN] int pos.
//		Holds the the position.
//
//	Description:
//		This function deletes node from specified position in linked list.
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is -1.
//
///////////////////////////////////////////////////////////////////////////////////////////


int RemoveAtPosition(
									struct node **head,
									int pos
							)
{
	if(pos > (CountNode(*head)))
	{
		return -1;
	}
	else if(pos == 1)
	{
		DeleteFirst( head );
	}
	else if(pos == (CountNode( *head )))
	{
		DeleteLast( head );
	}
	else
	{
		int i = 0;
		struct node *temp = *head,*t;

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
//	Function Name		:	ReverseList
//	Parameters:
//
//		[IN/OUT] struct node **first.
//		Holds head pointer of list.
//
//	Description:
//		This function reverse linked list.
//
//	Returns:
//		int
//		If the function succeeds, the return value is 1.
//		If the function fails, the return value is -1.
//
///////////////////////////////////////////////////////////////////////////////////////////


int ReverseList(
							struct node **head
						)
{
	struct node *prev = NULL;
	struct node *current =*head;
	struct node *next = NULL;

	// If linked list is empty
	if(*head == NULL)
	{
		return -1;
	}

	while(current != NULL)
	{
		next = current -> next;
		current -> next = prev;
		prev = current;
		current = next;
	}
	*head = prev;

	return 1;
}

int main()
{
struct node *head = NULL;


InsertFirst(&head,10);
InsertFirst(&head,20);

InsertFirst(&head,30);
InsertFirst(&head,30);

InsertFirst(&head,30);

InsertFirst(&head,30);
InsertFirst(&head,30);



InsertFirst(&head,40);
InsertFirst(&head,30);


DisplayGenList(head);

printf("\nElements in linked lista re %d\n",CountNode(head));

printf("\nElements 20 AT POSITION  %d\n",SearchFirstOccurance(head,80));

printf("\nElements 30    %d\n",SearchAllOccurance(head,30));

return 0;
}
