/* Primitive Operations on Static Stack */
#include <stdio.h>
#include <conio.h>
#define SIZE 5

struct stack
{
	int data[SIZE];
	int top;
};

/* fn declarations */
void initstack(struct stack *);
void push(struct stack *,int);
int pop(struct stack *);
int isfull(struct stack *);
int isempty(struct stack *);
void display(struct stack *);

void main()
{
	struct stack s;
	int choice, num;
	initstack(&s);   /* imp */
	while (1)
	{
		clrscr();
		printf("Operations on Static Stack\n\n");
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("3. DISPLAY\n");
		printf("4. EXIT\n\n");
		printf("Enter your choice :- ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				if (isfull(&s))
				{
					printf("Stack is full");
					getch();
				}
				else
				{
					printf("Enter the no. to push :- ");
					scanf("%d",&num);
					push(&s,num);
				}
				break;


			case 2:
				if (isempty(&s))
					printf("Stack is empty");
				else
				{
					num = pop(&s);
					printf("Element removed is %d",num);
				}
				getch();
				break;

			case 3:
				if (isempty(&s))
					printf("Stack is empty");
				else
					display(&s);

				getch();
				break;

			case 4:
				exit();
		}
	}
}

void initstack(struct stack *ps)
{
	ps->top = -1;
}

void push(struct stack *ps,int num)
{
	ps->top++;
	ps->data[ps->top] = num;
}

int pop(struct stack *ps)
{
	int num;
	num = ps->data[ps->top];
	ps->top--;
	return num;
	/* return ps->data[ps->top--]; */
}

int isfull(struct stack *ps)
{
	if (ps->top == SIZE-1)
		return 1;
	else
		return 0;
}

int isempty(struct stack *ps)
{
	if (ps->top == -1)
		return 1;
	else
		return 0;
}

void display(struct stack *ps)
{
	int temp;
	for (temp=ps->top;temp != -1;temp--)
		printf("%d\n",ps->data[temp]);
}

























































