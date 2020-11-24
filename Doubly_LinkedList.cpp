#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

//
// This is doubly linked list of type int
//
 
struct node
{
	int						Data;
	node	*pNext,*pPrev;
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	AddToListFirst
//	Function Date			:	08/11/2013
//	Function Author		:	Piyush Khairnar
//	Parameters:
//
//		[IN/OUT] node **ppListHead.
//		Holds head pointer of list.
//
//		[IN] int pNodeData.
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node to list.
//
//	Returns:
//		int EAN
//		If the function succeeds, the return value is  1.
//		If the function fails, the return value is  -1.
//
///////////////////////////////////////////////////////////////////////////////////////////
 
int 
AddToListFirst (
								node **ppListHead,
								int pNodeData
						)
{
	struct node *pNewNode = NULL;

	if ( 0 == pNodeData || NULL == ppListHead )
	{
		return  -1;
	}

	//
	//	Allocate new node.
	//
	pNewNode = (node *)malloc(sizeof(node));
	if (NULL == pNewNode)
	{
		return  -1;
	}

	//
	//	Fill the node with data.
	//
	memset(pNewNode, 0, sizeof(node));
	pNewNode -> pNext = NULL;
	pNewNode -> Data = pNodeData;
	pNewNode -> pPrev = NULL;

	//
	//	Prepend
	//
	if (NULL == *ppListHead)
	{
		*ppListHead = pNewNode;
	}
	else
	{
		pNewNode -> pNext = *ppListHead;
		(*ppListHead) -> pPrev = pNewNode;
		*ppListHead = pNewNode;
	}

	*ppListHead = pNewNode;
	return  1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	AddToListLast
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//
//		[IN/OUT] node **ppListHead.
//		Head pointer of the existing list.
//
//		[IN] node **ppListToBeAppended.
//		List which is to be appended to an existing list.
//
//	Description:
//		This function appends specified   list to
//		specific   list.
//
//	Returns:
//		int EAN
//		If the function succeeds, the return value is  1.
//		If the function fails, the return value is  -1.
//
///////////////////////////////////////////////////////////////////////////////////////////

 
int 
AddToListLast (
							node **ppListHead,
							int pNodeData
				)
{
	struct node *pNewNode = NULL;

	struct node *pTempNode = NULL;

	pTempNode = *ppListHead;

	if (0 == pNodeData || NULL == ppListHead )
	{
		return  -1;
	}

	//
	//	Allocate new node.
	//
	pNewNode = (node *)malloc(sizeof(node));
	if (NULL == pNewNode)
	{
		return  -1;
	}

	//
	//	Fill the node with data.
	//
	memset(pNewNode, 0, sizeof(node));
	pNewNode -> pNext = NULL;
	pNewNode -> Data = pNodeData;
	pNewNode ->pPrev = NULL;
	//
	//	Append
	//
	if (NULL == *ppListHead)
	{
		*ppListHead = pNewNode;
	}
	else
	{
		while(pTempNode -> pNext != NULL)
		{
			pTempNode = pTempNode -> pNext; 
		}
		pTempNode -> pNext = pNewNode;
		pNewNode -> pNext = NULL;
		pNewNode -> pPrev = pTempNode;
	}

	return  1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	FreeList
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//			[IN] node *pListHead.
//			Holds head pointer of list.
//
//	Description:
//		This function frees   list.
//
//	Returns:
//		int EAN
//		If the function succeeds, the return value is  1.
//		If the function fails, the return value is  -1.
//
///////////////////////////////////////////////////////////////////////////////////////////

 
int 
FreeList(
					node *pListHead
			)
{
	struct node *pTemp;
	struct node *pNavigate;

	if (NULL == pListHead)
	{
		return  -1;
	}

	pNavigate = pListHead;
	while (NULL != pNavigate)
	{
		pTemp = pNavigate->pNext;
		free(pNavigate);
		pNavigate = pTemp;
	}

	return  1;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DisplayList
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//			[IN] node *pListHead.
//			Holds head pointer of list.
//
//	Description:
//		This function displays   list.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////

 
void
DisplayList(
						node *pListHead
			)
{
	while(NULL != pListHead)
	{
		printf("|%d|-> ",pListHead -> Data);
		pListHead = pListHead -> pNext;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	CountListNode
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//			[IN] node *pListHead.
//			Holds head pointer of list.
//
//	Description:
//		This function counts nodes in   list.
//
//	Returns:
//		int
//		Number of nodes in   list
//
///////////////////////////////////////////////////////////////////////////////////////////

 
int CountListNode (
							node *pListHead
					   )
{
	// Variable for maintaining number of nodes
	int CountNode = 0;

	// Traverse the linked list till end
	while(NULL != pListHead)
	{
		CountNode++;
		pListHead = pListHead -> pNext;
	}
	return CountNode;
}

////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	SearchFirstOccurance
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//			[IN] node *pListHead.
//			Holds head pointer of list.
//
//			[IN] node data.
//			Holds head data to be searched.
//
//	Description:
//		This function search perticular data in   list.
//		and return the position at which data is found.
//
//	Returns:
//		int
//		Position at which data is found in   list
//
///////////////////////////////////////////////////////////////////////////
 
int SearchFirstOccurance(
										node *pListHead,
										int data						// Data to be searched 
								)
{
	int CountNode = 0;

	// Traverse the linked list till end
	while( pListHead != NULL )
	{
		++CountNode;

		// If data matches with the input value
		if(memcmp(&(pListHead -> Data), &data, sizeof(data) ) == 0)
		{
			// Break the loop as we get the first occurance
			return CountNode; 
		}
		pListHead = pListHead ->pNext;
	}

	return -1;
}

////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	SearchAllOccurance
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//			[IN] node *pListHead.
//			Holds head pointer of list.
//
//			[IN] int data.
//			Holds head data to be searched.
//
//	Description:
//		This function search perticular data in   list.
//		and return number of occurances of that data.
//
//	Returns:
//		int
//		Number of times data is found in   list
//
///////////////////////////////////////////////////////////////////////////

 
int SearchAllOccurance( 
									node *pListHead,
									int data
								)
{
	int CountNode = 0;

	// Traverse the linked list till end
	while( pListHead!= NULL )
	{
		// If data matches with the input value
		if((pListHead -> Data)== data)
		{
			++CountNode; 
		}
		pListHead = pListHead -> pNext;
	}

	return CountNode;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	InsertAtPosition
//	Function Date			:	08/11/2013
//	Function Author		:	Piyush Khairnar
//	Parameters:
//
//		[IN/OUT] node **ppListHead.
//		Holds head pointer of list.
//
//		[IN] int pos.
//		Holds the the position.
//
//		[IN] int pNodeData.
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node at specified position in   list.
//
//	Returns:
//		int EAN
//		If the function succeeds, the return value is  1.
//		If the function fails, the return value is  -1.
//
///////////////////////////////////////////////////////////////////////////////////////////

 
int  InsertAtPosition( 
									node **head, 
									int pos,							// Position at which node is inserted 
									int pNodeData								// Data member of the node
								)
{
	int i = 1;
	
	struct node *temp = NULL;
	struct node *pNewNode = NULL;
	
	// If linked list is empty
	if( *head == NULL )
	{ 
		return  -1;
	}
	
	else if( pos == 1 )
	{
		AddToListFirst( head, pNodeData ); 
	}
	else if(pos == (CountListNode( *head )) + 1)
	{
		AddToListLast( head, pNodeData ); 
	}
	else if( (pos > CountListNode(*head)))
	{
		return  -1;
	}
	else
	{
		temp = ( *head );
		pNewNode = (node *)malloc(sizeof(node ));
		if (NULL == pNewNode)
		{
			return  -1;
		}

		//
		//	Fill the node with data.
		//
		memset(pNewNode, 0, sizeof(node));
		pNewNode -> pNext = NULL;
		pNewNode -> Data = pNodeData;
		pNewNode -> pPrev = NULL;

		while(i < pos - 1)
		{
			temp = temp -> pNext;
			++i;
		}
		pNewNode -> pNext = temp -> pNext;
		temp->pNext->pPrev = pNewNode;
		temp -> pNext = pNewNode;
		pNewNode->pPrev = temp;
	}

	return  1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteFromListFirst
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//
//	Parameters:
//
//		[IN/OUT] node **ppListHead.
//		Head pointer of the existing list.
//
//	Description:
//		This function removes first node from   list
//
//	Returns:
//		int EAN
//		If the function succeeds, the return value is  1.
//		If the function fails, the return value is  -1.
//
///////////////////////////////////////////////////////////////////////////////////////////

 
int  DeleteFromListFirst(
											node **head
							)
{
	struct node *temp = NULL;
	temp = ( *head );

	// If linked list is empty
	if((*head) == NULL)
	{
		return  -1;
	}
	else
	{
		(*head) = temp -> pNext;
		(*head)->pPrev = NULL;
		free(temp);
	}
	return  1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteFromListLast
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//
//		[IN/OUT] node **ppListHead.
//		Head pointer of the existing list.
//
//	Description:
//		This function removes last node from   list
//
//	Returns:
//		int EAN
//		If the function succeeds, the return value is  1.
//		If the function fails, the return value is  -1.
//
///////////////////////////////////////////////////////////////////////////////////////////

 
int  DeleteFromListLast(
											node **head
								)
{
	struct node *temp1,*temp2;
	temp1 = temp2 = ( *head );

	// If linked list is empty
	if((*head) == NULL)
	{
		return  -1;
	}
	else
	{
		while(temp1 -> pNext != NULL)
		{
			temp2 = temp2 -> pNext;
			temp1 = temp2 -> pNext;
		}
		temp2 -> pNext = NULL;
		free(temp1);
	}

	return  1;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteAtPosition
//	Function Date			:	08/11/2013
//	Function Author		:	Piyush Khairnar
//	Parameters:
//
//		[IN/OUT] node **ppListHead.
//		Holds head pointer of list.
//
//		[IN] int pos.
//		Holds the the position.
//
//	Description:
//		This function deletes node from specified position in list.
//
//	Returns:
//		int EAN
//		If the function succeeds, the return value is  1.
//		If the function fails, the return value is  -1.
//
///////////////////////////////////////////////////////////////////////////////////////////

 
int  DeleteAtPosition(
									node **head,
									int pos
							)
{
	if(pos > (CountListNode(*head)))
	{
		return  -1;
	}
	else if(pos == 1)
	{
		DeleteFromListFirst( head );
	}
	else if(pos == (CountListNode( *head )))
	{
		DeleteFromListLast( head );
	}
	else
	{
		int i = 0;
		node *temp = *head,*t;

		for(i = 0; i < pos - 1; i++)
		{
			t = temp;
			temp = temp -> pNext;
		}
		t -> pNext = temp -> pNext;
		temp -> pNext ->pPrev = t;

		free( temp );
	}
	return  1;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DisplayListReverse
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//			[IN] node *pListHead.
//			Holds head pointer of list.
//
//	Description:
//		Function which display the list in reverse manner.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////

 
int 
DisplayListReverse(
								node *head
							)
{
	if(head == NULL) 
	{
		return  1;
	}
	else
	{
		while(head -> pNext != NULL)
		{ 
			head = head -> pNext; 
		}
		while(head !=NULL)
		{
			printf("|%d|<=>",head -> Data);
			head = head -> pPrev;
		}
	}
	return  -1;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	Entry point function
//	Function Date			:	08/11/2013
//	Function Author		:	Piyush Khairnar
//	Brief Description	:	
//
///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	int no = 10;
	int  bRet;
	node *pHead = NULL;

	bRet = AddToListFirst(&pHead,no);
	no++;
	bRet = AddToListFirst(&pHead,no);
	no++;
	bRet = AddToListFirst(&pHead,no);
	no = 20;
	bRet = AddToListLast(&pHead,no);
	no = 30;
	bRet = AddToListLast(&pHead,no);

	DisplayList(pHead);
	printf("\n");

	printf("\n");

	DeleteFromListFirst(&pHead);
	DisplayList(pHead);
	printf("\n");

	DeleteFromListLast(&pHead);
	DisplayList(pHead);
	printf("\n");

	no = 20;
	printf("\nElement 20 is found at position %d\n",SearchFirstOccurance(pHead,no));
	no = 45;
	DisplayList(pHead);
	printf("\n");
	InsertAtPosition(&pHead,2,no);
	DisplayList(pHead);
	printf("\n");

	printf("\n");
	DeleteAtPosition(&pHead,2);
	DisplayList(pHead);
	printf("\n");

	DisplayListReverse(pHead);
	FreeList(pHead);
	getch();
	return 0;
}
