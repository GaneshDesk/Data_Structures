//////////////////////////////////////////////////////////////////////////////////////////
//
//			Implementation of Stack using Array
//
//////////////////////////////////////////////////////////////////////////////////////////

/*
Stacks is abstract data types (ADT)

We can implement stack in two ways
	1.Arrays
	2.Linked lists

We can perform following operations on stack
	push( ) Insert element at top of stack
	pop( ) Delete and return the top of stack
	IsStackEmpty( ) Return true if stack is empty
	IsStackFull( ) Return true if stack is Full

Applications of Stacks :

	Web browsers store the addresses of recently visited sites on a stack
	Each time the visits a new site ==> pushed on the stack.
	Browsers allow to “pop” back to previously visited site.

	The undo-mechanism in an editor
	The changes are kept in a stack.
	When the user presses “undo” the stack of changes is popped.

	The function-call mechanism
	The active (called but not completed) functions are kept on a stack
	Each time a function is called, a new frame describing its context is pushed onto the stack
	The context of a method: its parameters, local variables, what needs to be returned, and where 
	to return (the instruction to be executed upon return)
	When the function returns, its frame is popped, the context is reset to the previous method 
	(now on top of the stack) and the program continues by executing the previously suspended method

-----------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<malloc.h>
# define MAX 10

int top = -1;
int Stack[MAX];

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	IsStackEmpty
//
//	Description:
//		This function checks whether stack is empty or not.
//
///////////////////////////////////////////////////////////////////////////////////////////
int IsStackEmpty()
{
	if(top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	IsStackFull
//
//	Description:
//		This function checks whether stack is full or not.
//
///////////////////////////////////////////////////////////////////////////////////////////
int IsStackFull()
{
	if(top == MAX)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//
//	Description:
//		This function displays contents of stack.
//
///////////////////////////////////////////////////////////////////////////////////////////
void Display()
{
	int i = 0;
	if(top == -1)
	{
		return;
	}
	for(i = top; i != -1; i--)
	{
		printf("| %d |\n",Stack[i]);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	pop
//
//	Description:
//		This function remove element from stack.
//
///////////////////////////////////////////////////////////////////////////////////////////
int pop()
{
	int no = 0;

	if(IsStackEmpty())
	{
		return -1;
	}
	else
	{
		return Stack[top--];
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	push
//
//	Description:
//		This function add element in stack.
//
///////////////////////////////////////////////////////////////////////////////////////////
void push(int no)
{
	if(IsStackFull( ))
	{
		return;
	}
	Stack[++top] = no;
}

int main(int argc, char *argv[])
{
	push(10);
	push(20);
	push(30);
	push(40);

	Display();

	printf("\nPoped Element %d\n",pop());
	printf("Poped Element %d\n",pop());

	Display();
	return 0;
}