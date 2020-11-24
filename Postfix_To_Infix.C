/* Postfix to Infix conversion of expression */
#include <stdio.h>
#include <conio.h>
#include <string.h>

struct stack
{
	char data[10][50];
	int top;
};

/* fn declarations */
void initstack(struct stack *);
void push(struct stack *,char []);
char *pop();

void main()
{
	struct stack s;
	char postfix[20], str[2], op1[50], op2[50], expr[50];
	int i;
	initstack(&s);
	clrscr();
	printf("Enter the postfix expression :- ");
	gets(postfix);
	for (i=0;postfix[i] != '\0';i++)
	{
		/* 1st convert operand/operator into a string */
		str[0] = postfix[i];
		str[1] = '\0';
		/* switch case accepts char or int data type only */
		switch (postfix[i])
		{
			/* case operators */
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
			case '$':
			case '%':
				strcpy(op2,pop(&s));
				strcpy(op1,pop(&s));
				/* form the expression */
				strcpy(expr,"(");
				strcat(expr,op1);
				strcat(expr,str);
				strcat(expr,op2);
				strcat(expr,")");
				push(&s,expr);
				break;

			default :  /* operand */
				push(&s,str);
		}
	}
	printf("Infix expression is %s",pop(&s));
	getch();
}

void initstack(struct stack *ps)
{
	ps->top = -1;
}

void push(struct stack *ps,char str[])
{
	ps->top++;
	strcpy(ps->data[ps->top],str);
}

char *pop(struct stack *ps)
{
	return ps->data[ps->top--];
}








































