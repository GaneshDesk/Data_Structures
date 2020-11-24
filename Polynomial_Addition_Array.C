/* Addition of polynomials using array of structures */
#include <stdio.h>
#include <conio.h>

struct poly
{
	int coeff[10];    /* position / index in array represents
			    power of term */
};

void main()
{
	struct poly p[3];   /* array of structure */
	int i, j, no_terms, pow;
	clrscr();
	/* initialise every poly's term to 0 */
	for (i=0;i<3;i++)    /* to reach every poly */
	{
		for (j=0;j<10;j++)  /* to reach every term */
			p[i].coeff[j] = 0;
	}
	/* Accept terms for poly1 and poly2 */
	for (i=0;i<2;i++)
	{
		printf("Enter the no of terms for poly %d :- ",i+1);
		scanf("%d",&no_terms);
		for (j=0;j<no_terms;j++)
		{
			printf("Enter power :- ");
			scanf("%d",&pow);
			printf("Enter coeff :- ");
			scanf("%d",&p[i].coeff[pow]);
		}
	}
	/* Add terms of poly with same power only */
	for (j=0;j<10;j++)
		p[2].coeff[j] = p[0].coeff[j] + p[1].coeff[j];

	/* Display all the polys in DESC order by power */
	clrscr();
	for (i=0;i<3;i++)   /* to reach every poly */
	{
		printf("\n\nPoly %d is :- \n",i+1);
		for (j=9;j>=0;j--)
		{
			/* while printing positive terms, print "+" */
			if (p[i].coeff[j] > 0)
			{
				/* pow > 0 */
				if (j > 0)
					printf(" + %dx%d",p[i].coeff[j],j);
				else  /* j = 0 */
					printf(" + %d",p[i].coeff[j]);
			}
			/* while printing negative terms, don't print "-" */
			else if (p[i].coeff[j] < 0)
			{
				/* pow > 0 */
				if (j > 0)
					printf(" %dx%d",p[i].coeff[j],j);
				else   /* j = 0 */
					printf(" %d",p[i].coeff[j]);
			}
		} /* end of j loop */
	} /* end of i loop */
	getch();
}  /* end of main */




























