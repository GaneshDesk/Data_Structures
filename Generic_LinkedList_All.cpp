//
// This program contains generic code for all types of linked list as
//	1. Singly linked list
//	2. Singly circular linked list
//	3. Doubly linked list
//	4. Doubly circular linked list
//


#include<string.h>
#include<iostream>

using namespace std;

#define TRUE 1
#define FALSE 0

//
//		New data types
//
typedef int                 BOOL;
typedef unsigned char       BYTE;

//
// This is generic linked list of type T
//
template <typename T>
struct GEN_LIST
{
	T		Data;
	GEN_LIST	*pNext;
};

//
// This is generic doubly linked list of type T
//
template <typename T>
struct GEN_DLIST
{
	T		Data;
	GEN_DLIST	*pNext,*pPrev;
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Class Name			:	Singly_linkedList
//	Description			:	This class represents singly linear lined list
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Singly_linkedList
{
	public:
	GEN_LIST<T> *pHead;			// Pointing at start of linked list
	GEN_LIST<T> *pTail;			// Pointing at end of linked list

	Singly_linkedList();

	~Singly_linkedList();

	BOOL AddToGenListFirst (
								T *pNodeData
							);

	void DisplayGenList( );

	BOOL AddToGenListLast (
								T *pNodeData
							);

	BOOL FreeGenList( );

	int CountGenListNode ( );

	int SearchFirstOccurance(
								T data
							);

	int SearchAllOccurance(
								T data
							);

	BOOL InsertAtPosition( 
								int pos,
								T* pNodeData
							);

	BOOL DeleteFromGenListFirst( );

	BOOL DeleteAtPosition(
							int pos
						);

	BOOL DeleteFromGenListLast( );

	BOOL ReverseList( );

};


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Class Name			:	Doubly_linkedList
//	Description			:	This class represents doubly linear lined list
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Doubly_linkedList
{
	public:
	GEN_DLIST<T> *pHead;			// Pointing at start of linked list
	GEN_DLIST<T> *pTail;				// Pointing at end of linked list

	Doubly_linkedList();

	~Doubly_linkedList();

	BOOL AddToGenListFirst (
								T *pNodeData
							);

	void DisplayGenList( );

	BOOL AddToGenListLast (
										T *pNodeData
									);

	int CountGenListNode ( );

	BOOL FreeGenList( );

	int SearchFirstOccurance(
										T data
									);

	int SearchAllOccurance(
										T data
									);

	BOOL InsertAtPosition( 
									int pos,
									T* pNodeData
								);

	BOOL DeleteFromGenListFirst( );

	BOOL DeleteAtPosition(
									int pos
								);

	BOOL DeleteFromGenListLast( );

	BOOL DisplayGenListReverse( );

};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Class Name			:	Singly_linkedList_Circular
//	Description			:	This class represents singly circular lined list
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Singly_linkedList_Circular
{
	public:
	GEN_LIST<T> *pHead;			// Pointing at start of linked list
	GEN_LIST<T> *pTail;			// Pointing at end of linked list

	Singly_linkedList_Circular();

	~Singly_linkedList_Circular();

	BOOL AddToGenListFirst (
										T *pNodeData
									);

	void DisplayGenList( );

	BOOL AddToGenListLast (
										T *pNodeData
									);

	BOOL FreeGenList( );

	int CountGenListNode ( );

	int SearchFirstOccurance(
										T data
									);

	int SearchAllOccurance(
										T data
									);

	BOOL InsertAtPosition( 
									int pos,
									T* pNodeData
									);

	BOOL DeleteFromGenListFirst( );

	BOOL DeleteAtPosition(
									int pos
								);

	BOOL DeleteFromGenListLast( );

	BOOL ReverseList( );

};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Class Name			:	Doubly_linkedList_Circular
//	Description			:	This class represents doubly circular lined list
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Doubly_linkedList_Circular
{
	public:
	GEN_DLIST<T> *pHead;			// Pointing at start of linked list
	GEN_DLIST<T> *pTail;				// Pointing at end of linked list

	Doubly_linkedList_Circular();

	~Doubly_linkedList_Circular();

	BOOL AddToGenListFirst (
										T *pNodeData
									);

	void DisplayGenList( );

	BOOL AddToGenListLast (
										T *pNodeData
									);

	int CountGenListNode ( );

	BOOL FreeGenList( );

	int SearchFirstOccurance(
										T data
									);

	int SearchAllOccurance(
										T data
									);

	BOOL InsertAtPosition( 
									int pos,
									T* pNodeData
								);

	BOOL DeleteFromGenListFirst( );

	BOOL DeleteAtPosition(
									int pos
								);

	BOOL DeleteFromGenListLast( );

	BOOL DisplayGenListReverse( );

};
///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Singly_linkedList
//	Function Date			:	07/11/2013
//	Function Author			:	Piyush Khairnar
//	Parameters:				: NONE
//	Description:
//		This is constructor of class Singly_linkedList
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
Singly_linkedList<T> ::Singly_linkedList ( )
{
	pHead = NULL;
	pTail = NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	~Singly_linkedList
//	Function Date			:	07/11/2013
//	Function Author			:	Piyush Khairnar
//	Parameters:				: NONE
//	Description:
//		This is destructor of class Singly_linkedList
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
Singly_linkedList<T> ::~Singly_linkedList ( )
{
	GEN_LIST<T> *pTemp;
	GEN_LIST<T> *pNavigate;

	if (NULL != pHead)
	{
		pNavigate = pHead;
		while (NULL != pNavigate)
		{
			pTemp = pNavigate->pNext;
			free(pNavigate);
			pNavigate = pTemp;
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	AddToGenListFirst
//	Function Date			:	07/11/2013
//	Function Author		:	Piyush Khairnar
//	Parameters:
//
//		[IN] T *pNodeData.
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node to Singly Linear Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
BOOL 
Singly_linkedList<T> ::AddToGenListFirst (
													T *pNodeData
														)
{
	GEN_LIST<T> *pNewNode;

	if ( NULL == pNodeData )
	{
		return FALSE;
	}

	//
	//	Allocate new node.
	//
	pNewNode = (GEN_LIST<T> *)malloc(sizeof(GEN_LIST<T>));
	if (NULL == pNewNode)
	{
		return FALSE;
	}

	//
	//	Fill the node with data.
	//
	memset(pNewNode, 0, sizeof(GEN_LIST<T>));
	pNewNode->pNext = NULL;
	pNewNode->Data = *pNodeData;

	//
	//	Prepend
	//
	if (NULL == pHead)
	{
		pHead = pNewNode;
		pTail = pNewNode;
	}
	else
	{
		pNewNode -> pNext = pHead;
		pHead = pNewNode;
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DisplayGenList
//	Function Date		:	07/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//					NONE
//	Description:
//		This function displays Singly Linear Linked List.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
void 
Singly_linkedList<T>::DisplayGenList()
{
	GEN_LIST<T> *pTempNode;
	pTempNode = pHead;

	while(NULL != pTempNode)
	{
		cout<<pTempNode -> Data<<" -> ";
		pTempNode = pTempNode -> pNext;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	AddToGenListLast
//	Function Date		:	07/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//
//		[IN] GEN_LIST<T> **ppListToBeAppended.
//		List which is to be appended to an existing list.
//
//	Description:
//		This function appends node inn Singly Linear Linked List
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T> 
BOOL
Singly_linkedList<T>::AddToGenListLast (
														T *pNodeData
														)
{
	GEN_LIST<T> *pNewNode;

	GEN_LIST<T> *pTempNode;
	pTempNode = pHead;

	if (NULL == pNodeData)
	{
		return FALSE;
	}

	//
	//	Allocate new node.
	//
	pNewNode = (GEN_LIST<T> *)malloc(sizeof(GEN_LIST<T>));
	if (NULL == pNewNode)
	{
		return FALSE;
	}

	//
	//	Fill the node with data.
	//
	memset(pNewNode, 0, sizeof(GEN_LIST<T>));
	pNewNode -> pNext = NULL;
	pNewNode -> Data = *pNodeData;

	//
	//	Append
	//
	if (NULL == pHead)
	{
		pHead = pNewNode;
		pTail = pNewNode;
	}
	else
	{
		pTail->pNext = pNewNode;
		pTail = pNewNode;
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	FreeGenList
//	Function Date		:	07/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//					NONE
//	Description:
//		This function frees Singly Linear Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL 
Singly_linkedList<T>::FreeGenList( )
{
	GEN_LIST<T> *pTemp;
	GEN_LIST<T> *pNavigate;

	if (NULL == pHead)
	{
		return FALSE;
	}

	pNavigate = pHead;
	while (NULL != pNavigate)
	{
		pTemp = pNavigate->pNext;
		free(pNavigate);
		pNavigate = pTemp;
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	CountGenListNode
//	Function Date		:	07/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//					NONE
//	Description:
//		This function counts nodes in Singly Linear Linked List.
//
//	Returns:
//		int
//		Number of nodes in generic list
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
int 
Singly_linkedList<T>::CountGenListNode ( )
{
	// Variable for maintaining number of nodes
	int CountNode = 0;
	GEN_LIST<T> *pListHead = pHead;

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
//	Function Date		:	07/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//
//			[IN] GEN_LIST<T> data.
//			Holds head data to be searched.
//
//	Description:
//		This function search perticular data in Singly Linear Linked List.
//		and return the position at which data is found.
//
//	Returns:
//		int
//		Position at which data is found in generic list
//
///////////////////////////////////////////////////////////////////////////
template <typename T>
int 
Singly_linkedList<T>::SearchFirstOccurance(
															T data
														)
{
	int CountNode = 0;
	GEN_LIST<T> *pListHead = pHead;

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
//	Function Date		:	07/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//
//			[IN] GEN_LIST<T> data.
//			Holds head data to be searched.
//
//	Description:
//		This function search perticular data in Singly Linear Linked List.
//		and return number of occurances of that data.
//
//	Returns:
//		int
//		Number of times data is found in generic list
//
///////////////////////////////////////////////////////////////////////////

template <typename T>
int 
Singly_linkedList<T>::SearchAllOccurance(
														T data
														)
{
	int CountNode = 0;
	GEN_LIST<T> *pListHead = pHead;

	// Traverse the linked list till end
	while( pListHead!= NULL )
	{
		// If data matches with the input value
		if(memcmp(&(pListHead -> Data), &data, sizeof(data) ) == 0)
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
//	Function Date			:	07/11/2013
//	Function Author		:	Piyush Khairnar
//	Parameters:
//
//		[IN] int pos.
//		Holds the the position.
//
//		[IN] T *pNodeData.
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node at specified position in Singly Linear Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL 
Singly_linkedList<T>::InsertAtPosition( 
														int pos,
														T* pNodeData
													)
{
	int i = 1;
	
	GEN_LIST<T> *temp = NULL;
	GEN_LIST<T> *pNewNode = NULL;
	
	// If linked list is empty
	if( pHead == NULL )
	{ 
		return FALSE;
	}
	
	else if( pos == 1 )
	{
		AddToGenListFirst(pNodeData ); 
	}
	else if(pos == (CountGenListNode( )) + 1)
	{
		AddToGenListLast(pNodeData ); 
	}
	else if( (pos > CountGenListNode()))
	{
		return FALSE;
	}
	else
	{
		temp = pHead;
		pNewNode = (GEN_LIST<T> *)malloc(sizeof(GEN_LIST<T> ));
		if (NULL == pNewNode)
		{
			return FALSE;
		}

		//
		//	Fill the node with data.
		//
		memset(pNewNode, 0, sizeof(GEN_LIST<T>));
		pNewNode -> pNext = NULL;
		pNewNode -> Data = *pNodeData;

		while(i < pos - 1)
		{
			temp = temp -> pNext;
			++i;
		}
		pNewNode -> pNext = temp -> pNext;
		temp -> pNext = pNewNode;
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteFromGenListFirst
//	Function Date		:	07/11/2013
//	Function Author	:	Piyush Khairnar
//
//	Parameters:
//					NONE
//	Description:
//		This function removes first node from Singly Linear Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL 
Singly_linkedList<T>::DeleteFromGenListFirst( )
{
	GEN_LIST <T> *temp;
	temp = pHead;

	// If linked list is empty
	if(pHead == NULL)
	{
		return FALSE;
	}
	else
	{
		pHead = temp -> pNext;
		free(temp);
	}
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteFromGenListLast
//	Function Date		:	07/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//					NONE
//	Description:
//		This function removes last node from Singly Linear Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL Singly_linkedList<T>::DeleteFromGenListLast( )
{
	GEN_LIST<T> *temp1,*temp2;
	temp1 = temp2 = pHead;

	// If linked list is empty
	if(pHead == NULL)
	{
		return FALSE;
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

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteAtPosition
//	Function Date			:	07/11/2013
//	Function Author		:	Piyush Khairnar
//	Parameters:
//					NONE
//		[IN] int pos.
//		Holds the the position.
//
//	Description:
//		This function deletes node from specified position in Singly Linear Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL 
Singly_linkedList<T>::DeleteAtPosition(
														int pos
													)
{
	if(pos > (CountGenListNode()))
	{
		return FALSE;
	}
	else if(pos == 1)
	{
		DeleteFromGenListFirst();
	}
	else if(pos == (CountGenListNode()))
	{
		DeleteFromGenListLast();
	}
	else
	{
		int i = 0;
		GEN_LIST<T> *temp = pHead,*t;

		for(i = 0; i < pos - 1; i++)
		{
			t = temp;
			temp = temp -> pNext;
		}
		t -> pNext = temp -> pNext;
		temp -> pNext = NULL;
		free( temp );
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	ReverseList
//	Function Date			:	07/11/2013
//	Function Author		:	Piyush Khairnar
//	Parameters:
//					NONE
//	Description:
//		This function reverse Singly Linear Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL Singly_linkedList<T>::ReverseList( )
{
	GEN_LIST<T> *prev = NULL;
	GEN_LIST<T> *current = pHead;
	GEN_LIST<T> *next = NULL;

	// If linked list is empty
	if(pHead == NULL)
	{
		return FALSE;
	}

	while(current != NULL)
	{
		next = current -> pNext;
		current -> pNext = prev;
		prev = current;
		current = next;
	}
	pHead = prev;

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Doubly_linkedList
//	Function Date			:	07/11/2013
//	Function Author		:	Piyush Khairnar
//	Parameters:			: NONE
//	Description:
//		This is constructor of class Doubly_linkedList
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
Doubly_linkedList<T> ::Doubly_linkedList ( )
{
	pHead = NULL;
	pTail = NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	~Doubly_linkedList
//	Function Date			:	07/11/2013
//	Function Author		:	Piyush Khairnar
//	Parameters:			: NONE
//	Description:
//		This is destructor of class Doubly_linkedList
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
Doubly_linkedList<T> ::~Doubly_linkedList ( )
{
	GEN_DLIST<T> *pTemp;
	GEN_DLIST<T> *pNavigate;

	if (NULL != pHead)
	{
		pNavigate = pHead;
		while (NULL != pNavigate)
		{
			pTemp = pNavigate->pNext;
			free(pNavigate);
			pNavigate = pTemp;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	AddToGenListFirst
//	Function Date			:	08/11/2013
//	Function Author		:	Piyush Khairnar
//	Parameters:
//
//		[IN] T *pNodeData.
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node to Doubly Linear Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
BOOL
Doubly_linkedList<T>::AddToGenListFirst (
														T *pNodeData
														)
{
	GEN_DLIST<T> *pNewNode = NULL;

	if ( NULL == pNodeData)
	{
		return FALSE;
	}

	//
	//	Allocate new node.
	//
	pNewNode = (GEN_DLIST<T> *)malloc(sizeof(GEN_DLIST<T>));
	if (NULL == pNewNode)
	{
		return FALSE;
	}

	//
	//	Fill the node with data.
	//
	memset(pNewNode, 0, sizeof(GEN_DLIST<T>));
	pNewNode -> pNext = NULL;
	pNewNode -> Data = *pNodeData;
	pNewNode -> pPrev = NULL;

	//
	//	Prepend
	//
	if (NULL == pHead)
	{
		pHead = pNewNode;
		pTail = pNewNode;
	}
	else
	{
		pNewNode -> pNext = pHead;
		(pHead) -> pPrev = pNewNode;
		pHead = pNewNode;
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	AddToGenListLast
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//
//		[IN] GEN_DLIST<T> **ppListToBeAppended.
//		List which is to be appended to an existing list.
//
//	Description:
//		This function appends node in Doubly Linear Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL
Doubly_linkedList<T>::AddToGenListLast (
														T *pNodeData
													)
{
	GEN_DLIST<T> *pNewNode = NULL;

	GEN_DLIST<T> *pTempNode = NULL;

	pTempNode = pHead;

	if (NULL == pNodeData)
	{
		return FALSE;
	}

	//
	//	Allocate new node.
	//
	pNewNode = (GEN_DLIST<T> *)malloc(sizeof(GEN_DLIST<T>));
	if (NULL == pNewNode)
	{
		return FALSE;
	}

	//
	//	Fill the node with data.
	//
	memset(pNewNode, 0, sizeof(GEN_DLIST<T>));
	pNewNode -> pNext = NULL;
	pNewNode -> Data = *pNodeData;
	pNewNode ->pPrev = NULL;
	//
	//	Append
	//
	if (NULL == pHead)
	{
		pHead = pNewNode;
		pTail = pNewNode;
	}
	else
	{
		pNewNode->pPrev = pTail;
		pTail ->pNext = pNewNode;
		pTail = pNewNode;
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	FreeGenList
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//						NONE
//	Description:
//		This function frees Doubly Linear Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL
Doubly_linkedList<T>::FreeGenList( )
{
	GEN_DLIST<T> *pTemp;
	GEN_DLIST<T> *pNavigate;

	if (NULL == pHead)
	{
		return FALSE;
	}

	pNavigate = pHead;
	while (NULL != pNavigate)
	{
		pTemp = pNavigate->pNext;
		free(pNavigate);
		pNavigate = pTemp;
	}

	return TRUE;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DisplayGenList
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//			[IN] GEN_DLIST<T> *pListHead.
//			Holds head pointer of list.
//
//	Description:
//		This function displays Doubly Linear Linked List.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
void
Doubly_linkedList<T>::DisplayGenList()
{
	GEN_DLIST<T> *pTempNode = pHead;

	while(NULL != pTempNode)
	{
		cout<<pTempNode -> Data<<" <==> ";
		pTempNode = pTempNode -> pNext;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	CountGenListNode
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//			[IN] GEN_DLIST<T> *pListHead.
//			Holds head pointer of list.
//
//	Description:
//		This function counts nodes in Doubly Linear Linked List.
//
//	Returns:
//		int
//		Number of nodes in generic list
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
int Doubly_linkedList<T>::CountGenListNode ( )
{
	// Variable for maintaining number of nodes
	int CountNode = 0;
	GEN_DLIST<T> *pTempNode = pHead;

	// Traverse the linked list till end
	while(NULL != pTempNode)
	{
		CountNode++;
		pTempNode = pTempNode -> pNext;
	}
	return CountNode;
}

////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	SearchFirstOccurance
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//
//			[IN] GEN_DLIST<T> data.
//			Holds head data to be searched.
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
template <typename T>
int Doubly_linkedList<T>::SearchFirstOccurance(
													T data						// Data to be searched 
															)
{
	int CountNode = 0;
	GEN_DLIST<T> *pTempNode = pHead;

	// Traverse the linked list till end
	while( pTempNode != NULL )
	{
		++CountNode;

		// If data matches with the input value
		if(memcmp(&(pTempNode -> Data), &data, sizeof(data) ) == 0)
		{
			// Break the loop as we get the first occurance
			return CountNode; 
		}
		pTempNode = pTempNode ->pNext;
	}

	return -1;
}

////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	SearchAllOccurance
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//
//			[IN] GEN_DLIST<T> data.
//			Holds head data to be searched.
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

template <typename T>
int SearchAllOccurance( 
									GEN_DLIST<T> *pListHead,
									T data
								)
{
	int CountNode = 0;
	GEN_DLIST<T> *pTempNode = pHead;

	// Traverse the linked list till end
	while( pTempNode!= NULL )
	{
		// If data matches with the input value
		if(memcmp(&(pTempNode -> Data), &data, sizeof(data) ) == 0)
		{
			++CountNode; 
		}
		pTempNode = pTempNode -> pNext;
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
//		[IN] int pos.
//		Holds the the position.
//
//		[IN] T *pNodeData.
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node at specified position in Doubly Linear Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL Doubly_linkedList<T>::InsertAtPosition(
									int pos,							// Position at which node is inserted 
									T* pNodeData								// Data member of the node
								)
{
	int i = 1;
	
	GEN_DLIST<T> *temp = NULL;
	GEN_DLIST<T> *pNewNode = NULL;
	
	// If linked list is empty
	if( pHead == NULL )
	{ 
		return FALSE;
	}
	
	else if( pos == 1 )
	{
		AddToGenListFirst(pNodeData ); 
	}
	else if(pos == (CountGenListNode()) + 1)
	{
		AddToGenListLast(pNodeData ); 
	}
	else if( (pos > CountGenListNode()))
	{
		return FALSE;
	}
	else
	{
		temp = pHead;
		pNewNode = (GEN_DLIST<T> *)malloc(sizeof(GEN_DLIST<T> ));
		if (NULL == pNewNode)
		{
			return FALSE;
		}

		//
		//	Fill the node with data.
		//
		memset(pNewNode, 0, sizeof(GEN_DLIST<T>));
		pNewNode -> pNext = NULL;
		pNewNode -> Data = *pNodeData;
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

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteFromGenListFirst
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//
//	Parameters:
//						NONE
//	Description:
//		This function removes first node from Doubly Linear Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL Doubly_linkedList<T>::DeleteFromGenListFirst( )
{
	GEN_DLIST <T> *temp = NULL;
	temp = pHead;

	// If linked list is empty
	if(pHead == NULL)
	{
		return FALSE;
	}
	else
	{
		pHead = temp -> pNext;
		pHead ->pPrev = NULL;
		free(temp);
	}
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteFromGenListLast
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//						NONE
//	Description:
//		This function removes last node from Doubly Linear Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL Doubly_linkedList<T>::DeleteFromGenListLast( )
{
	GEN_DLIST<T> *temp1,*temp2;
	temp1 = temp2 = pHead;

	// If linked list is empty
	if(pHead == NULL)
	{
		return FALSE;
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

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteAtPosition
//	Function Date			:	08/11/2013
//	Function Author		:	Piyush Khairnar
//	Parameters:
//
//		[IN] int pos.
//		Holds the the position.
//
//	Description:
//		This function deletes node from specified position in Doubly Linear Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL 
Doubly_linkedList<T>::DeleteAtPosition(
													int pos
											)
{
	if(pos > (CountGenListNode( )))
	{
		return FALSE;
	}
	else if(pos == 1)
	{
		DeleteFromGenListFirst();
	}
	else if(pos == (CountGenListNode()))
	{
		DeleteFromGenListLast();
	}
	else
	{
		int i = 0;
		GEN_DLIST<T> *temp = pHead,*t;

		for(i = 0; i < pos - 1; i++)
		{
			t = temp;
			temp = temp -> pNext;
		}
		t -> pNext = temp -> pNext;
		temp -> pNext ->pPrev = t;

		free( temp );
	}
	return TRUE;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DisplayGenListReverse
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//						NONE
//	Description:
//		Function which display the Doubly Linear Linked List in reverse manner.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL
Doubly_linkedList<T>::DisplayGenListReverse( )
{
	GEN_DLIST<T> *temp = pTail;

	if(pHead == NULL) 
	{
		return TRUE;
	}
	else
	{
		while(temp != NULL)
		{ 
			printf("|%d|<=>",temp -> Data);
			temp = temp -> pPrev;
		}
	}
	return FALSE;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Singly_linkedList_Circular
//	Function Date			:	07/11/2013
//	Function Author		:	Piyush Khairnar
//	Parameters:			: NONE
//	Description:
//		This is constructor of class Singly_linkedList_Circular
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
Singly_linkedList_Circular<T> ::Singly_linkedList_Circular ( )
{
	pHead = NULL;
	pTail = NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	~Singly_linkedList_Circular
//	Function Date			:	07/11/2013
//	Function Author		:	Piyush Khairnar
//	Parameters:			: NONE
//	Description:
//		This is destructor of class Singly_linkedList_Circular
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
Singly_linkedList_Circular<T> ::~Singly_linkedList_Circular ( )
{
/*	GEN_LIST<T> *pTemp;
	GEN_LIST<T> *pNavigate;

	if (NULL != pHead)
	{
		pNavigate = pHead;
		while (NULL != pNavigate)
		{
			pTemp = pNavigate->pNext;
			free(pNavigate);
			pNavigate = pTemp;
		}
	}
*/
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	AddToGenListFirst
//	Function Date			:	07/11/2013
//	Function Author		:	Piyush Khairnar
//	Parameters:
//
//		[IN] T *pNodeData.
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node to Singly Circular Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
BOOL 
Singly_linkedList_Circular<T> ::AddToGenListFirst (
												T *pNodeData
												)
{
	GEN_LIST<T> *pNewNode;

	if ( NULL == pNodeData )
	{
		return FALSE;
	}

	//
	//	Allocate new node.
	//
	pNewNode = (GEN_LIST<T> *)malloc(sizeof(GEN_LIST<T>));
	if (NULL == pNewNode)
	{
		return FALSE;
	}

	//
	//	Fill the node with data.
	//
	memset(pNewNode, 0, sizeof(GEN_LIST<T>));
	pNewNode->pNext = NULL;
	pNewNode->Data = *pNodeData;

	//
	//	Prepend
	//
	if (NULL == pHead && pTail == NULL)
	{
		pHead = pNewNode;
		pTail = pNewNode;
		pTail -> pNext = pHead;
	}
	else
	{
		pNewNode -> pNext = pHead;
		pHead = pNewNode;
		pTail ->pNext = pNewNode; 
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DisplayGenList
//	Function Date		:	07/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//					NONE
//	Description:
//		This function displays Singly Circular Linked List.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
void 
Singly_linkedList_Circular<T>::DisplayGenList()
{
	GEN_LIST<T> *pTempNode;
	pTempNode = pHead;

	do
	{
		cout<<pTempNode -> Data<<" -> ";
		pTempNode = pTempNode -> pNext;
	}while(pTempNode != pTail->pNext);
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	AddToGenListLast
//	Function Date		:	07/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//
//		[IN] GEN_LIST<T> **ppListToBeAppended.
//		List which is to be appended to an existing list.
//
//	Description:
//		This function appends in Singly Circular Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T> 
BOOL
Singly_linkedList_Circular<T>::AddToGenListLast (
														T *pNodeData
														)
{
	GEN_LIST<T> *pNewNode;

	GEN_LIST<T> *pTempNode;
	pTempNode = pHead;

	if (NULL == pNodeData)
	{
		return FALSE;
	}

	//
	//	Allocate new node.
	//
	pNewNode = (GEN_LIST<T> *)malloc(sizeof(GEN_LIST<T>));
	if (NULL == pNewNode)
	{
		return FALSE;
	}

	//
	//	Fill the node with data.
	//
	memset(pNewNode, 0, sizeof(GEN_LIST<T>));
	pNewNode -> pNext = NULL;
	pNewNode -> Data = *pNodeData;

	//
	//	Append
	//
	if (NULL == pHead && pTail == NULL)
	{
		pHead = pNewNode;
		pTail = pNewNode;
		pTail ->pNext = pHead;
	}
	else
	{
		pTail->pNext = pNewNode;
		pTail = pNewNode;
		pTail->pNext = pHead;
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	FreeGenList
//	Function Date		:	07/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//					NONE
//	Description:
//		This function frees Singly Circular Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL 
Singly_linkedList_Circular<T>::FreeGenList( )
{
	GEN_LIST<T> *pTemp;
	GEN_LIST<T> *pNavigate;

	if (NULL == pHead)
	{
		return FALSE;
	}

	pNavigate = pHead;
	while (NULL != pNavigate)
	{
		pTemp = pNavigate->pNext;
		free(pNavigate);
		pNavigate = pTemp;
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	CountGenListNode
//	Function Date		:	07/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//					NONE
//	Description:
//		This function counts nodes in Singly Circular Linked List.
//
//	Returns:
//		int
//		Number of nodes in generic list
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
int 
Singly_linkedList_Circular<T>::CountGenListNode ( )
{
	// Variable for maintaining number of nodes
	int CountNode = 0;
	GEN_LIST<T> *pTempNode;
	pTempNode = pHead;

	do
	{
		CountNode++;
		pTempNode = pTempNode -> pNext;
	}while(pTempNode != pTail->pNext);

	return CountNode;
}

////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	SearchFirstOccurance
//	Function Date		:	07/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//
//			[IN] GEN_LIST<T> data.
//			Holds head data to be searched.
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
template <typename T>
int 
Singly_linkedList_Circular<T>::SearchFirstOccurance(
															T data
														)
{
	int CountNode = 0;
	GEN_LIST<T> *pListHead = pHead;

	// Traverse the linked list till end
	do
	{
		CountNode++;
		if(memcmp(&(pListHead -> Data), &data, sizeof(data) ) == 0)
		{
			// Break the loop as we get the first occurance
			return CountNode; 
		}
		pListHead = pListHead -> pNext;
	}while(pListHead != pTail->pNext);

	return -1;
}

////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	SearchAllOccurance
//	Function Date		:	07/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//
//			[IN] GEN_LIST<T> data.
//			Holds head data to be searched.
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

template <typename T>
int 
Singly_linkedList_Circular<T>::SearchAllOccurance(
														T data
														)
{
	int CountNode = 0;
	GEN_LIST<T> *pListHead = pHead;

	// Traverse the linked list till end
	do
	{
		if(memcmp(&(pListHead -> Data), &data, sizeof(data) ) == 0)
		{
			CountNode++; 
		}
		pListHead = pListHead -> pNext;
	}while(pListHead != pTail->pNext);

	return CountNode;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	InsertAtPosition
//	Function Date			:	07/11/2013
//	Function Author		:	Piyush Khairnar
//	Parameters:
//
//		[IN] int pos.
//		Holds the the position.
//
//		[IN] T *pNodeData.
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node at specified position in Singly Circular Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL 
Singly_linkedList_Circular<T>::InsertAtPosition( 
														int pos,
														T* pNodeData
													)
{
	int i = 1;
	
	GEN_LIST<T> *temp = NULL;
	GEN_LIST<T> *pNewNode = NULL;
	
	// If linked list is empty
	if( pHead == NULL )
	{ 
		return FALSE;
	}
	
	else if( pos == 1 )
	{
		AddToGenListFirst(pNodeData ); 
	}
	else if(pos == (CountGenListNode( )) + 1)
	{
		AddToGenListLast(pNodeData ); 
	}
	else if( (pos > CountGenListNode()))
	{
		return FALSE;
	}
	else
	{
		temp = pHead;
		pNewNode = (GEN_LIST<T> *)malloc(sizeof(GEN_LIST<T> ));
		if (NULL == pNewNode)
		{
			return FALSE;
		}

		//
		//	Fill the node with data.
		//
		memset(pNewNode, 0, sizeof(GEN_LIST<T>));
		pNewNode -> pNext = NULL;
		pNewNode -> Data = *pNodeData;

		while(i < pos - 1)
		{
			temp = temp -> pNext;
			++i;
		}
		pNewNode -> pNext = temp -> pNext;
		temp -> pNext = pNewNode;
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteFromGenListFirst
//	Function Date		:	07/11/2013
//	Function Author	:	Piyush Khairnar
//
//	Parameters:
//					NONE
//	Description:
//		This function removes first node from Singly Circular Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL 
Singly_linkedList_Circular<T>::DeleteFromGenListFirst( )
{
	GEN_LIST <T> *temp;
	temp = pHead;

	// If linked list is empty
	if(pHead == NULL)
	{
		return FALSE;
	}
	else
	{
		pHead = temp -> pNext;
		free(temp);
	}
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteFromGenListLast
//	Function Date		:	07/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//					NONE
//	Description:
//		This function removes last node from Singly Circular Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL Singly_linkedList_Circular<T>::DeleteFromGenListLast( )
{
	GEN_LIST<T> *temp1,*temp2;
	temp1 = pHead;
	temp2 = pTail;

	// If linked list is empty
	if(pHead == NULL && pTail == NULL)
	{
		return FALSE;
	}
	else
	{
		while(temp1 -> pNext != temp2)
		{
			temp1 = temp1 -> pNext;
		}

		free(temp2);
		pTail = temp1;
		temp1 -> pNext = pHead;

	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteAtPosition
//	Function Date			:	07/11/2013
//	Function Author		:	Piyush Khairnar
//	Parameters:
//					NONE
//		[IN] int pos.
//		Holds the the position.
//
//	Description:
//		This function deletes node from specified position in Singly Circular Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL 
Singly_linkedList_Circular<T>::DeleteAtPosition(
														int pos
													)
{
	if(pos > (CountGenListNode()))
	{
		return FALSE;
	}
	else if(pos == 1)
	{
		DeleteFromGenListFirst();
	}
	else if(pos == (CountGenListNode()))
	{
		DeleteFromGenListLast();
	}
	else
	{
		int i = 0;
		GEN_LIST<T> *temp = pHead,*t;

		for(i = 0; i < pos - 1; i++)
		{
			t = temp;
			temp = temp -> pNext;
		}
		t -> pNext = temp -> pNext;
		temp -> pNext = NULL;
		free( temp );
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Doubly_linkedList_Circular
//	Function Date			:	07/11/2013
//	Function Author		:	Piyush Khairnar
//	Parameters:			: NONE
//	Description:
//		This is constructor of class Doubly_linkedList_Circular
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
Doubly_linkedList_Circular<T> ::Doubly_linkedList_Circular ( )
{
	pHead = NULL;
	pTail = NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	~Doubly_linkedList_Circular
//	Function Date			:	07/11/2013
//	Function Author		:	Piyush Khairnar
//	Parameters:			: NONE
//	Description:
//		This is destructor of class Doubly_linkedList_Circular
//
//	Returns					: NONE
//
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
Doubly_linkedList_Circular<T> ::~Doubly_linkedList_Circular ( )
{
	GEN_DLIST<T> *pTemp;
	GEN_DLIST<T> *pNavigate;

	if (NULL == pHead)
	{
		return;
	}

	pNavigate = pHead;
	while ( pNavigate != pTail)
	{
		pTemp = pNavigate->pNext;
		free(pNavigate);
		pNavigate = pTemp;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	AddToGenListFirst
//	Function Date			:	08/11/2013
//	Function Author		:	Piyush Khairnar
//	Parameters:
//
//		[IN] T *pNodeData.
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node to Doubly Circular Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
BOOL
Doubly_linkedList_Circular<T>::AddToGenListFirst (
														T *pNodeData
														)
{
	GEN_DLIST<T> *pNewNode = NULL;

	if ( NULL == pNodeData)
	{
		return FALSE;
	}

	//
	//	Allocate new node.
	//
	pNewNode = (GEN_DLIST<T> *)malloc(sizeof(GEN_DLIST<T>));
	if (NULL == pNewNode)
	{
		return FALSE;
	}

	//
	//	Fill the node with data.
	//
	memset(pNewNode, 0, sizeof(GEN_DLIST<T>));
	pNewNode -> pNext = NULL;
	pNewNode -> Data = *pNodeData;
	pNewNode -> pPrev = NULL;

	//
	//	Prepend
	//
	if (NULL == pHead)
	{
		pHead = pNewNode;
		pTail = pNewNode;
		pTail -> pNext = pNewNode;
	}
	else
	{
		pNewNode -> pNext = pHead;
		(pHead) -> pPrev = pNewNode;
		pHead = pNewNode;
		pTail->pNext = pHead;
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	AddToGenListLast
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//
//		[IN] GEN_DLIST<T> **ppListToBeAppended.
//		List which is to be appended to an existing list.
//
//	Description:
//		This function appends node to Doubly Circular Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL
Doubly_linkedList_Circular<T>::AddToGenListLast (
														T *pNodeData
													)
{
	GEN_DLIST<T> *pNewNode = NULL;

	GEN_DLIST<T> *pTempNode = NULL;

	pTempNode = pHead;

	if (NULL == pNodeData)
	{
		return FALSE;
	}

	//
	//	Allocate new node.
	//
	pNewNode = (GEN_DLIST<T> *)malloc(sizeof(GEN_DLIST<T>));
	if (NULL == pNewNode)
	{
		return FALSE;
	}

	//
	//	Fill the node with data.
	//
	memset(pNewNode, 0, sizeof(GEN_DLIST<T>));
	pNewNode -> pNext = NULL;
	pNewNode -> Data = *pNodeData;
	pNewNode ->pPrev = NULL;
	//
	//	Append
	//
	if (NULL == pHead)
	{
		pHead = pNewNode;
		pTail = pNewNode;
		pTail -> pNext = pNewNode;
	}
	else
	{
		pNewNode -> pPrev = pTail;
		pTail -> pNext = pNewNode;
		pTail = pNewNode;
		pTail->pNext = pHead;
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	FreeGenList
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//						NONE
//	Description:
//		This function frees Doubly Circular Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL
Doubly_linkedList_Circular<T>::FreeGenList( )
{
	GEN_DLIST<T> *pTemp;
	GEN_DLIST<T> *pNavigate;

	if (NULL == pHead)
	{
		return FALSE;
	}

	pNavigate = pHead;
	while ( pNavigate != pTail)
	{
		pTemp = pNavigate->pNext;
		free(pNavigate);
		pNavigate = pTemp;
	}

	return TRUE;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DisplayGenList
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//			[IN] GEN_DLIST<T> *pListHead.
//			Holds head pointer of list.
//
//	Description:
//		This function displays Doubly Circular Linked List.
//
//	Returns:
//		void
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
void
Doubly_linkedList_Circular<T>::DisplayGenList()
{
	GEN_DLIST<T> *pTempNode;
	pTempNode = pHead;

	do
	{
		cout<<pTempNode -> Data<<" -> ";
		pTempNode = pTempNode -> pNext;
	}while(pTempNode != pTail->pNext);
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	CountGenListNode
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//			[IN] GEN_DLIST<T> *pListHead.
//			Holds head pointer of list.
//
//	Description:
//		This function counts nodes in Doubly Circular Linked List.
//
//	Returns:
//		int
//		Number of nodes in generic list
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
int Doubly_linkedList_Circular<T>::CountGenListNode ( )
{
	// Variable for maintaining number of nodes
	int CountNode = 0;
		GEN_DLIST<T> *pTempNode;
	pTempNode = pHead;

	do
	{
		CountNode++;
		pTempNode = pTempNode -> pNext;
	}while(pTempNode != pTail->pNext);
	return CountNode;
}

////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	SearchFirstOccurance
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//
//			[IN] GEN_DLIST<T> data.
//			Holds head data to be searched.
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
template <typename T>
int Doubly_linkedList_Circular<T>::SearchFirstOccurance(
													T data						// Data to be searched 
															)
{
	int CountNode = 0;
	GEN_DLIST<T> *pListHead = pHead;

	// Traverse the linked list till end
	do
	{
		CountNode++;
		if(memcmp(&(pListHead -> Data), &data, sizeof(data) ) == 0)
		{
			// Break the loop as we get the first occurance
			return CountNode; 
		}
		pListHead = pListHead -> pNext;
	}while(pListHead != pTail->pNext);

	return -1;
}

////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	SearchAllOccurance
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//
//			[IN] GEN_DLIST<T> data.
//			Holds head data to be searched.
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

template <typename T>
int Doubly_linkedList_Circular<T>::SearchAllOccurance( 
									T data
								)
{
	int CountNode = 0;
	GEN_DLIST<T> *pListHead = pHead;

	// Traverse the linked list till end
	do
	{
		if(memcmp(&(pListHead -> Data), &data, sizeof(data) ) == 0)
		{
			CountNode++; 
		}
		pListHead = pListHead -> pNext;
	}while(pListHead != pTail->pNext);

	return CountNode;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	InsertAtPosition
//	Function Date			:	08/11/2013
//	Function Author		:	Piyush Khairnar
//	Parameters:
//
//		[IN] int pos.
//		Holds the the position.
//
//		[IN] T *pNodeData.
//		Holds the entry which is to be added.
//
//	Description:
//		This function adds node at specified position in Doubly Circular Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL Doubly_linkedList_Circular<T>::InsertAtPosition(
									int pos,							// Position at which node is inserted 
									T* pNodeData						// Data member of the node
								)
{
	int i = 1;
	
	GEN_DLIST<T> *temp = NULL;
	GEN_DLIST<T> *pNewNode = NULL;
	
	// If linked list is empty
	if( pHead == NULL )
	{ 
		return FALSE;
	}
	
	else if( pos == 1 )
	{
		AddToGenListFirst(pNodeData ); 
	}
	else if(pos == (CountGenListNode()) + 1)
	{
		AddToGenListLast(pNodeData ); 
	}
	else if( (pos > CountGenListNode()))
	{
		return FALSE;
	}
	else
	{
		temp = pHead;
		pNewNode = (GEN_DLIST<T> *)malloc(sizeof(GEN_DLIST<T> ));
		if (NULL == pNewNode)
		{
			return FALSE;
		}

		//
		//	Fill the node with data.
		//
		memset(pNewNode, 0, sizeof(GEN_DLIST<T>));
		pNewNode -> pNext = NULL;
		pNewNode -> Data = *pNodeData;
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

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteFromGenListFirst
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//
//	Parameters:
//						NONE
//	Description:
//		This function removes first node from Doubly Circular Linked List
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL Doubly_linkedList_Circular<T>::DeleteFromGenListFirst( )
{
	GEN_DLIST <T> *temp = NULL;
	temp = pHead;

	// If linked list is empty
	if(pHead == NULL)
	{
		return FALSE;
	}
	else
	{
		pHead = temp -> pNext;
		pTail->pNext = pHead;
		pHead ->pPrev = pTail;
		free(temp);
	}
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteFromGenListLast
//	Function Date		:	08/11/2013
//	Function Author	:	Piyush Khairnar
//	Parameters:
//						NONE
//	Description:
//		This function removes last node from Doubly Circular Linked List
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL Doubly_linkedList_Circular<T>::DeleteFromGenListLast( )
{
	GEN_DLIST<T> *temp;

	// If linked list is empty
	if(pHead == NULL)
	{
		return FALSE;
	}
	else
	{	temp = pTail;
		pTail = pTail->pPrev;
		pTail->pNext = pHead;
		free(temp);
	}

	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DeleteAtPosition
//	Function Date			:	08/11/2013
//	Function Author		:	Piyush Khairnar
//	Parameters:
//
//		[IN] int pos.
//		Holds the the position.
//
//	Description:
//		This function deletes node from specified position in Doubly Circular Linked List.
//
//	Returns:
//		BOOLEAN
//		If the function succeeds, the return value is TRUE.
//		If the function fails, the return value is FALSE.
//
///////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
BOOL 
Doubly_linkedList_Circular<T>::DeleteAtPosition(
													int pos
											)
{
	if(pos > (CountGenListNode( )))
	{
		return FALSE;
	}
	else if(pos == 1)
	{
		DeleteFromGenListFirst();
	}
	else if(pos == (CountGenListNode()))
	{
		DeleteFromGenListLast();
	}
	else
	{
		int i = 0;
		GEN_DLIST<T> *temp = pHead,*t;

		for(i = 0; i < pos - 1; i++)
		{
			t = temp;
			temp = temp -> pNext;
		}
		t -> pNext = temp -> pNext;
		temp -> pNext ->pPrev = t;

		free( temp );
	}
	return TRUE;
}
///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name		:	DisplayGenListReverse
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

template <typename T>
BOOL
Doubly_linkedList_Circular<T>::DisplayGenListReverse( )
{
	GEN_DLIST<T> *temp = pTail;

	if(pHead == NULL) 
	{
		return TRUE;
	}
	else
	{
		do
		{
			printf("|%d|<=>",temp -> Data);
			temp = temp -> pPrev;
		}while(temp != pHead->pPrev);
	}
	return FALSE;
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
BOOL bRet;

cout<<endl<<"-------------------------------------------------------------"<<endl;
cout<<"\t\tLinear Singly Linked List";
cout<<endl<<"-------------------------------------------------------------"<<endl;

Singly_linkedList <int>sobj;
int no=10;
sobj.AddToGenListFirst(&no);
no++;
sobj.AddToGenListFirst(&no);
no++;
sobj.AddToGenListFirst(&no);
no++;
sobj.AddToGenListFirst(&no);

no = 25;
sobj.AddToGenListLast(&no);
sobj.DisplayGenList();

no = 11;
cout<<endl<<"Element 11 is fount at position "<<sobj.SearchFirstOccurance(no)<<endl;

sobj.InsertAtPosition(4,&no);
sobj.DisplayGenList();
printf("\n");

sobj.DeleteFromGenListFirst();
sobj.DisplayGenList();
printf("\n");

sobj.DeleteFromGenListLast();
sobj.DisplayGenList();
printf("\n");

sobj.DeleteAtPosition(2);
sobj.DisplayGenList();
printf("\n");

sobj.ReverseList();
sobj.DisplayGenList();
printf("\n");

cout<<endl<<"-------------------------------------------------------------"<<endl;
cout<<"\t\tLinear Doubly Linked List";
cout<<endl<<"-------------------------------------------------------------"<<endl;

Doubly_linkedList <int>dobj;

bRet = dobj.AddToGenListFirst(&no);
no++;

bRet = dobj.AddToGenListFirst(&no);
no++;

bRet = dobj.AddToGenListFirst(&no);
no++;

dobj.DisplayGenList();
printf("\n");

no = 20;
bRet = dobj.AddToGenListLast(&no);
no = 30;
bRet = dobj.AddToGenListLast(&no);

dobj.DisplayGenList();
printf("\n");

no = 40;
bRet = dobj.AddToGenListLast(&no);
no = 50;
bRet = dobj.AddToGenListLast(&no);

dobj.DisplayGenList();
printf("\n");

no = 20;
cout<<endl<<"Element 20 is fount at position "<<dobj.SearchFirstOccurance(no)<<endl;
no = 45;
dobj.DisplayGenList();
printf("\n");
dobj.InsertAtPosition(4,&no);
dobj.DisplayGenList();
printf("\n");

printf("\n");
dobj.DeleteAtPosition(4);
dobj.DisplayGenList();
printf("\n");

dobj.DisplayGenListReverse();

cout<<endl<<"-------------------------------------------------------------"<<endl;
cout<<"\t\tCircular Singly Linked List";
cout<<endl<<"-------------------------------------------------------------"<<endl;

Singly_linkedList_Circular <int>scobj;

no = 25;
scobj.AddToGenListLast(&no);
scobj.DisplayGenList();

no = 10;
scobj.AddToGenListFirst(&no);
no++;
cout<<endl;
scobj.DisplayGenList();

scobj.AddToGenListFirst(&no);
no++;
cout<<endl;	
scobj.DisplayGenList();

scobj.AddToGenListFirst(&no);
no++;
scobj.AddToGenListFirst(&no);
no++;
cout<<endl;
scobj.DisplayGenList();
cout<<endl;
no = 25;
scobj.AddToGenListLast(&no);
scobj.DisplayGenList();
no = 11;
cout<<endl<<"Element 11 is fount at position "<<scobj.SearchFirstOccurance(no)<<endl;

scobj.InsertAtPosition(4,&no);
scobj.DisplayGenList();
printf("\n");


no = 25;
cout<<endl<<"Element 11 is fount at position "<<scobj.SearchAllOccurance(no)<<endl;

scobj.DeleteFromGenListFirst();
scobj.DisplayGenList();
printf("\n");

scobj.DeleteFromGenListLast();
scobj.DisplayGenList();
printf("\n");

scobj.DeleteAtPosition(2);
scobj.DisplayGenList();
printf("\n");

cout<<endl<<"-------------------------------------------------------------"<<endl;
cout<<"\t\tCircular Doubly Linked List";
cout<<endl<<"-------------------------------------------------------------"<<endl;

Doubly_linkedList_Circular <int>dcobj;

no = 95;
dcobj.AddToGenListLast(&no);
dcobj.DisplayGenList();

no = 25;
dcobj.AddToGenListFirst(&no);
dcobj.DisplayGenList();

no = 10;
dcobj.AddToGenListFirst(&no);
no++;
cout<<endl;
dcobj.DisplayGenList();

dcobj.AddToGenListFirst(&no);
no++;
cout<<endl;	
dcobj.DisplayGenList();

dcobj.AddToGenListFirst(&no);
no++;
dcobj.AddToGenListFirst(&no);
no++;
cout<<endl;
dcobj.DisplayGenList();
cout<<endl;
no = 35;
dcobj.AddToGenListLast(&no);
dcobj.DisplayGenList();
no = 11;
cout<<endl<<"Element 11 is fount at position "<<dcobj.SearchFirstOccurance(no)<<endl;
cout<<endl<<"Element 11 is fount at position "<<dcobj.SearchAllOccurance(no)<<endl;

dcobj.InsertAtPosition(4,&no);
dcobj.DisplayGenList();
printf("\n");

dcobj.DeleteFromGenListFirst();
dcobj.DisplayGenList();
printf("\n");

dcobj.DeleteFromGenListLast();
dcobj.DisplayGenList();
printf("\n");

dcobj.DeleteAtPosition(2);
dcobj.DisplayGenList();
printf("\n");

dcobj.DisplayGenListReverse();

return 0;
}