/* Multiplication of polynomials using Linked List */

#include <stdio.h>
#include <conio.h>
#include <alloc.h>

struct node
{
	int coeff, pow;
	struct node *next;
};

/* fn declarations */
struct node *createpoly(struct node *);
void displaypoly(struct node *);
struct node *multipoly(struct node *,struct node *,struct node *);

void main()
{
	struct node *p1 = NULL, *p2 = NULL, *p3 = NULL;
	clrscr();
	printf("Enter poly 1 :- \n");
	p1 = createpoly(p1);
	printf("\nEnter poly 2 :- \n");
	p2 = createpoly(p2);
	p3 = multipoly(p1,p2,p3);
	clrscr();
	printf("Poly 1 is :- \n");
	displaypoly(p1);
	printf("\n\nPoly 2 is :- \n");
	displaypoly(p2);
	printf("\n\nAdded Poly is :- \n");
	displaypoly(p3);
	getch();
}

struct node *createpoly(struct node *p)
{
	struct node *newnode, *temp;
	int i, no_terms;
	printf("Enter the no. of terms for poly :- ");
	scanf("%d",&no_terms);
	printf("Enter the terms in DESC order by power :-\n");
	for (i=0;i<no_terms;i++)
	{
		newnode = (struct node *) malloc(sizeof(struct node));
		newnode->next = NULL;
		printf("Enter the coeff & power :- ");
		scanf("%d %d",&newnode->coeff,&newnode->pow);
		if (p == NULL)
		{
			p = newnode;
			temp = newnode;
		}	
		else
		{
			temp->next = newnode;
			temp = newnode;
		}
	}	
	return p;
}

void displaypoly(struct node *p)
{
	while (p != NULL)
	{
		if (p->coeff > 0 && p->pow > 0)
			printf(" + %dx%d ",p->coeff,p->pow);
		else if (p->coeff > 0 && p->pow == 0)
			printf(" + %d ",p->coeff);
		else if (p->coeff < 0 && p->pow > 0)
			printf(" %dx%d ",p->coeff,p->pow);
		else
			printf(" %d ",p->coeff);
	
		p = p->next;
	}
}

struct node *multipoly(struct node *p1,struct node *p2,struct node *p3)
{
	struct node *newnode, *temp, *t2, *t3;
	/* t2 is a var used to traverse poly 2 and t3 is a var to
	   traverse poly 3 */
	int ncoeff, npow;
	/* refer to every term of p1 */
	while (p1 != NULL)
	{
		/* refer to every term of p2 */
		t2 = p2;
		while (t2 != NULL)
		{
			ncoeff = p1->coeff * t2->coeff;
			npow = p1->pow + t2->pow;
			/* if p3 doesn't exist i.e. this is 1st term of p3 */
			if (p3 == NULL)
			{
				newnode = (struct node *) malloc(sizeof(struct node));
				newnode->next = NULL;
				newnode->coeff = ncoeff;
				newnode->pow = npow;
				p3 = newnode;
				temp = newnode;
			}
			else
			{
				/* search for a term/node with same power. If it exists, do not create a newnode */
				t3 = p3;
				while (t3 != NULL)
				{
					if (t3->pow == npow)
					{
						t3->coeff += ncoeff;
						break;
					}
					t3 = t3->next;
				}	
				if (t3 == NULL)
				{
					/* node with same power not found */
					newnode = (struct node *)malloc(sizeof(struct node));
					newnode->next = NULL;
					newnode->coeff = ncoeff;
					newnode->pow = npow;
					/* set the links */
					temp->next = newnode;
					temp = newnode;
				}
			}
			t2 = t2->next;
		}   /* while (t2 != NULL) */
		p1 = p1->next;
	} /* while p1 != NULL */
	return p3;
}








































