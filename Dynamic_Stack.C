/* Dynamic stacks */
#include <stdio.h>
#include <conio.h>
#include <alloc.h>

struct node
{
	int data;
	struct node *next;
};

struct node *top;

/* fn declarations */
void initstack();
void push(int);
int pop();
int isempty();
void display();

void main()
{
	int choice, num;
	initstack();
	while (1)
	{
		clrscr();
		printf("Operations on Dynamic Stack\n\n");
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("3. DISPLAY\n");
		printf("4. EXIT\n\n");
		printf("Enter your choice :- ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("Enter the no. to push :- ");
				scanf("%d",&num);
				push(num);
				break;

			case 2:
				if (isempty())
					printf("Stack is empty");
				else
					printf("Element popped is %d",pop());

				getch();
				break;

			case 3:
				if (isempty())
					printf("Stack is empty");
				else
					display();

				getch();
				break;

			case 4:
				exit();
		}
	}
}

void initstack()
{
	top = NULL;
}

void push(int num)
{
	struct node *newnode;
	newnode = (struct node *) malloc(sizeof(struct node));
	newnode->data = num;
	/* check whether it is the 1st node */
	if (top == NULL)
	{
		newnode->next = NULL;
		top = newnode;
	}
	else
	{
		newnode->next = top;
		top = newnode;
	}
}

int pop()
{
	struct node *temp;
	int num;
	num = top->data;
	temp = top;
	top = top->next;
	free(temp);
	return num;
}

int isempty()
{
	if (top == NULL)
		return 1;

	return 0;
}

void display()
{
	struct node *temp;
	for (temp=top;temp != NULL;temp=temp->next)
		printf("%d\n",temp->data);
}































