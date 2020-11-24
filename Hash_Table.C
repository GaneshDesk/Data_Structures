/* Hash Table Prog for insertion, display & delete */

#include <stdio.h>
#include <conio.h>
#define SIZE 10

struct hash
{
	int key, chain;
};

struct hash b[SIZE];
int cntr = 0;

/* fn declaration */
void insert(int), display(), delete(int);  /* pass pos & not no */
int search(int);

void main()
{
	int choice, i, no, pos;
	/* 1st initialise all key & chain values to -1 */
	for (i=0;i<SIZE;i++)
	{
		b[i].key = -1;
		b[i].chain = -1;
	}
	while (1)
	{
		clrscr();
		printf("Hash Table - w/o replacement\n\n");
		printf("1. Insert\n");
		printf("2. Display\n");
		printf("3. Search\n");
		printf("4. Delete\n");
		printf("5. Exit\n\n");
		printf("Enter choice :- ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				if (cntr == SIZE)
				{
					printf("Hash Table is Full");
					getch();
				}
				else
				{
					printf("Enter the no. :- ");
					scanf("%d",&no);
					insert(no);
				}
				break;

			case 2:
				if (cntr == 0)
					printf("Hash Table is Empty");
				else
					display();

				getch();
				break;


			case 3:
				if (cntr == 0)
					printf("Hash Table is Empty");
				else
				{
					printf("Enter the no. to search :- ");
					scanf("%d",&no);
					pos = search(no);
					if (pos == -1)
						printf("No. not found in Hash Table");
					else
						printf("No. found at position %d",pos);

				}
				getch();
				break;

			case 4:
				if (cntr == 0)
					printf("Hash Table is Empty");
				else
				{
					printf("Enter the no. to delete :- ");
					scanf("%d",&no);
					pos = search(no);
					if (pos == -1)
						printf("No. %d not found in Hash Table",no);
					else
					{
						delete(pos);
						printf("No. %d deleted successfully from Hash Table",no);
					}
				}
				getch();
				break;


			case 5:
				exit();
		}
	}
}

void insert(int no)
{
	int k, m = -1;
	/* k is the position where the identifier will be mapped/put,
	   m is the position to which identifier at position is chained */
	k = no % SIZE;
	while (1)
	{
		if (b[k].key == -1)
		{
			b[k].key = no;
			cntr++;

			/* set the links */
			if (m != -1)
				b[m].chain = k;

			break;
		}
		else
		{
			if (m == -1)
				m = k;

			/* let k proceed */
			k = (k+1) % SIZE;

			/* m proceeds only if chain at pos m contains k */
			if (b[m].chain == k)
				m = k;
		}
	}
}

void display()
{
	int i;
	printf("Pos\tKey\tChain\n");
	for (i=0;i<SIZE;i++)
		printf("%d\t%d\t%d\n",i,b[i].key,b[i].chain);
}

int search(int no)
{
	int pos = -1, k;
	k = no % SIZE;   /* valid hash address */
	while (1)
	{
		if (b[k].key == no)
		{
			pos = k;   /* no found at pos = k, search terminates */
			break;
		}
		if (b[k].chain != -1)
			k = b[k].chain;
		else
			break;  /* no not found, search terminates */
	}
	return pos;
}

void delete(int pos)
{
	int k, m;  /* m to know whether there is a chain to pos */
	if (b[pos].chain == -1)
		b[pos].key = -1;
	else
	{
		/* shift elements below to top using links */
		m = pos;
		while (b[m].chain != -1)
		{
			k = b[m].chain;
			b[m].key = b[k].key;
			if (b[k].chain == -1)
				b[m].chain = -1;
			m = k;
		}
		b[k].key = -1;
	}
	cntr--;
}















