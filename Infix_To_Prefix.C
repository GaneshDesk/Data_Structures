/* Program for infix to prefix conversion of expression */
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define SIZE 40

struct stack
{
	char data[SIZE];
	int top;
};

/* fn declarations */
void initstack(struct stack *);
void push(struct stack *,char);
char pop(struct stack *);
int isempty(struct stack *);
int priority(char);


void main()
{
	struct stack s;
	char infix[SIZE], prefix[SIZE], ch;
	int i, j = 0;  /* i - to move in infix string, j - to move in
				postfix string */
	initstack(&s);
	clrscr();
	printf("Enter the infix expression :- ");
	gets(infix);
	/* analyse every char of infix string from R to L*/
	for (i=strlen(infix)-1;i>=0;i--)
	{
		switch (infix[i])
		{
			case ')':
				push(&s,infix[i]);  /* push(&s,')'); */
				break;

			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
			case '$':
				while (!isempty(&s) && priority(s.data[s.top]) > priority(infix[i]))
				{
					prefix[j] = pop(&s);
					j++;
				}
				push(&s,infix[i]);
				break;

			case '(':
				ch = pop(&s);
				while (ch != ')')  /* ch is operator */
				{
					prefix[j] = ch;
					j++;
					ch = pop(&s);
				}
				break;

			/* operands */
			default :
				prefix[j] = infix[i];
				j++;
		} /* end of switch */
	} /* end of while */
	/* if stack is not empty, pop all operators from stack
	   and append them to prefix string */
	while (!isempty(&s))
	{
		prefix[j] = pop(&s);
		j++;
	}
	prefix[j] = '\0';  /* to get rid of garbage values */
	printf("Prefix expression is %s",strrev(prefix));
	getch();
}

/* fn defns */
void initstack (struct stack *ps)
{
	ps->top = -1;
}

void push(struct stack *ps,char ch)
{
	ps->top++;
	ps->data[ps->top] = ch;
}

char pop(struct stack *ps)
{
	return ps->data[ps->top--];
}

int isempty(struct stack *ps)
{
	if (ps->top == -1)
		return 1;

	return 0;
}

int priority(char op)
{
	if (op == '^' || op == '$')
		return 3;

	if (op == '*' || op == '/' || op == '%')
		return 2;

	if (op == '+' || op == '-')
		return 1;

	return 0;   /* for close bracket */
}










































