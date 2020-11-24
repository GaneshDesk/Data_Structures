/* Implementation of Dequeue */
#include <stdio.h>
#include <conio.h>
#define SIZE 5

struct queue
{
	int data[SIZE];
	int front, rear;
};

void initq(struct queue *);
void addl(struct queue *,int);
void addr(struct queue *,int);
int dell(struct queue *);
int delr(struct queue *);
void displayq(struct queue *);
int isqfull(struct queue *);
int isqempty(struct queue *);

void main()
{
	struct queue q;
	int choice, num;
	initq(&q);
	while (1)
	{
		clrscr();
		printf("Operations on Dequeue\n\n");
		printf("1. ADD FROM LEFT\n");
		printf("2. ADD FROM RIGHT\n");
		printf("3. DELETE FROM LEFT\n");
		printf("4. DELETE FROM RIGHT\n");
		printf("5. DISPLAY QUEUE\n");
		printf("6. EXIT\n\n");
		printf("Enter your choice :- ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				if (isqfull(&q))
				{
					printf("Queue is full");
					getch();
				}
				else
				{
					printf("Enter the element :- ");
					scanf("%d",&num);
					addl(&q,num);
				}
				break;

			case 2:
				if (isqfull(&q))
				{
					printf("Queue is full");
					getch();
				}
				else
				{
					printf("Enter the element :- ");
					scanf("%d",&num);
					addr(&q,num);
				}
				break;

			case 3:
				if (isqempty(&q))
					printf("Queue is empty");
				else
					printf("Element deleted is %d",dell(&q));

				getch();
				break;


			case 4:
				if (isqempty(&q))
					printf("Queue is empty");
				else
					printf("Element deleted is %d",delr(&q));

				getch();
				break;

			case 5:
				if (isqempty(&q))
					printf("Queue is empty");
				else
					displayq(&q);

				getch();
				break;

			case 6:
				exit();
		}
	}
}

void initq(struct queue *pq)
{
	pq->front = pq->rear = -1;
}

void addl(struct queue *pq,int num)
{
	int i;
	if (isqempty(pq))
	{
		pq->front = 0;
		pq->rear = 0;
	}
	else
	{
		/* if pq->rear != SIZE-1, shift all elements from L to R */
		if (pq->rear != SIZE-1)
		{
			pq->rear++;
			for (i=pq->rear;i!=pq->front;i--)
				pq->data[i] = pq->data[i-1];
		}
		else
			pq->front--;
	}
	pq->data[pq->front] = num;
}

void addr(struct queue *pq,int num)
{
	int i;
	if (isqempty(pq))
	{
		pq->front = 0;
		pq->rear = 0;
	}
	else
	{
		/* if pq->front != 0, shift elements from R to L */
		if (pq->front != 0)
		{
			pq->front--;
			for (i=pq->front;i != pq->rear;i++)
				pq->data[i] = pq->data[i+1];
		}
		else
			pq->rear++;
	}
	pq->data[pq->rear] = num;
}

int dell(struct queue *pq)
{
	int no;
	no = pq->data[pq->front];
	pq->front++;
	/* check whether front has crossed rear */
	if (pq->front > pq->rear)
	{
		pq->front = -1;
		pq->rear = -1;
	}
	return no;
}

int delr(struct queue *pq)
{
	int no;
	no = pq->data[pq->rear];
	pq->rear--;
	/* check whether rear has crossed front */
	if (pq->rear < pq->front)
	{
		pq->front = -1;
		pq->rear = -1;
	}
	return no;
}

void displayq(struct queue *pq)
{
	int temp;
	for (temp=pq->front;temp<=pq->rear;temp++)
		printf("%d ",pq->data[temp]);
}

int isqfull(struct queue *pq)
{
	if (pq->front == 0 && pq->rear == SIZE-1)
		return 1;

	return 0;
}

int isqempty(struct queue *pq)
{
	if (pq->front == -1)
		return 1;

	return 0;
}










































