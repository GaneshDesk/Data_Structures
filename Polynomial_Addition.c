/* Addition of polynomials using Linked List */

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
struct node *addpoly(struct node *,struct node *,struct node *);

void main()
{
	struct node *p1 = NULL, *p2 = NULL, *p3 = NULL;
	clrscr();
	printf("Enter poly 1 :- \n");
	p1 = createpoly(p1);
	printf("\nEnter poly 2 :- \n");
	p2 = createpoly(p2);
	p3 = addpoly(p1,p2,p3);
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

struct node *addpoly(struct node *p1,struct node *p2,struct node *p3)
{
	struct node *newnode, *temp;
	/* compare the power of terms of p1 and p2 as long as terms
	   exist in both p1 and p2 */
	while (p1 != NULL && p2 != NULL)
	{
		/* if power of 2 terms is same, add the coeff of
		   terms & put them in newnode of p3. However
		   if addition gives 0, then newnode is not to be
		   created */
		   if (p1->pow == p2->pow)
		   {
			if (p1->coeff + p2->coeff == 0)
			{
				p1 = p1->next;
				p2 = p2->next;
				continue;
			}
		}
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->next = NULL;

		if (p1->pow == p2->pow)
		{
			newnode->coeff = p1->coeff+p2->coeff;
			newnode->pow = p1->pow;
			p1 = p1->next;
			p2 = p2->next;
		}
		else
		{
			if (p1->pow > p2->pow)
			{
				newnode->coeff = p1->coeff;
				newnode->pow = p1->pow;
				p1 = p1->next;
			}
			else
			{
				newnode->coeff = p2->coeff;
				newnode->pow = p2->pow;
				p2 = p2->next;
			}
		}
		/* attach newnode to p3 */
		if (p3 == NULL)
		{
			p3 = newnode;
			temp = newnode;
		}
		else
		{
			temp->next = newnode;
			temp = newnode;
		}
	}
	/* case - 1, p2 exhausted, so copy terms of p1 in p3 */
	while (p1 != NULL)
	{
		newnode = (struct node *) malloc(sizeof(struct node));
		newnode->next = NULL;
		newnode->coeff = p1->coeff;
		newnode->pow = p1->pow;
		p1 = p1->next;
		/* set the links */
		temp->next = newnode;
		temp = newnode;
	}
	/* case - 2, p1 exhausted, so copy terms of p2 in p3 */
	while (p2 != NULL)
	{
		newnode = (struct node *) malloc(sizeof(struct node));
		newnode->next = NULL;
		newnode->coeff = p2->coeff;
		newnode->pow = p2->pow;
		p2 = p2->next;
		/* set the links */
		temp->next = newnode;
		temp = newnode;
	}
	return p3;
}
			
		





















































