/* Library of books */
#include <stdio.h>
#include <conio.h>
#define SIZE 100

struct queue
{
	char member[SIZE][15];
	int front, rear;
};

int no_c_books = 0;

/* fn declarations */
void issue_book(struct queue *);
void return_book(struct queue *);
void initq(struct queue *);
void displayq(struct queue *);

void main()
{
	struct queue qc;
	int choice;
	initq(&qc);
	while (1)
	{
		clrscr();
		printf("Library System\n\n");
		printf("1. Issue Book\n");
		printf("2. Return Book\n");
		printf("3. Display Records\n");
		printf("4. Exit\n\n");
		printf("Enter your choice :- ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				issue_book(&qc);
				break;

			case 2:
				return_book(&qc);
				break;

			case 3:
				displayq(&qc);
				break;

			case 4:
				exit();
		}
	}
}

void issue_book(struct queue *pq)
{
	char name[15];
	printf("Enter the member name :- ");
	scanf("%s",name);
	if (no_c_books == 2)
	{
		printf("Book not available");
		printf("\nClaim for book kept");
	}
	else
	{
		no_c_books++;
		printf("Book Issued");
	}
	pq->rear++;
	strcpy(pq->member[pq->rear],name);
	if (pq->front == -1)
		pq->front++;
}

void return_book(struct queue *pq)
{
	no_c_books--;
	pq->front++;

	if (pq->front > pq->rear)
		initq(pq);
	else
	{
		if (pq->front < pq->rear)
		{
			no_c_books++;
			printf("Book Issued to next member %s",pq->member[pq->front+1]);
		}
		else
			printf("No more claims for this book");
	}
	getch();
}

void displayq(struct queue *pq)
{
	int temp, nor=pq->rear-pq->front, cntr=0;
	if (no_c_books == 0)
		printf("Book not issued to anybody");
	else
	{
		printf("Book issued to :- \n");
		for (temp=pq->front;temp<=pq->rear&&cntr<2;temp++,cntr++)
			printf("%s\n",pq->member[temp]);
		if (nor < 2)
			printf("\nNo Claims");
		else
		{
			printf("\nClaims by :-\n");
			for (temp=pq->front+2;temp<=pq->rear;temp++)
				printf("%s\n",pq->member[temp]);
		}
	}
	getch();
}

void initq(struct queue *pq)
{
	pq->front = pq->rear = -1;
}