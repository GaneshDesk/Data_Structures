/* Evaluation of Prefix Expression */
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>   /* pow(base,index) */
#include <ctype.h>  /* isalpha(char) */
#define SIZE 50

struct stack
{
	int data[SIZE];
	int top;
};

/* fn declarations */
void initstack(struct stack *);
void push(struct stack *,int);
int pop(struct stack *);

void main()
{
	struct stack s;
	char prefix[SIZE];
	int i, op1, op2, val;   /* val to accept values for operands */
	initstack(&s);
	clrscr();
	printf("Enter the prefix expression :- ");
	gets(prefix);
	for (i=strlen(prefix)-1;i >= 0;i--)
	{
		/* analyse every char of prefix expr */
		if (isalpha(prefix[i]))
		{
			printf("Enter value for operand %c :- ",prefix[i]);
			scanf("%d",&val);
			push(&s,val);
		}
		else /* operator */
		{
			op1 = pop(&s);
			op2 = pop(&s);
			if (prefix[i] == '+')
				push(&s,op1+op2);
			else if (prefix[i] == '-')
				push(&s,op1-op2);
			else if (prefix[i] == '*')
				push(&s,op1*op2);
			else if (prefix[i] == '/')
				push(&s,op1/op2);
			else if (prefix[i] == '%')
				push(&s,op1%op2);
			else /* $ or ^ */
				push(&s,pow(op1,op2));
		}
	}
	printf("Result is %d",pop(&s));
	getch();
}

void initstack(struct stack *ps)
{
	ps->top = -1;
}

void push(struct stack *ps,int no)
{
	ps->top++;
	ps->data[ps->top] = no;
}

int pop(struct stack *ps)
{
	return ps->data[ps->top--];
}



































