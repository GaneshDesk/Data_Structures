/* Static Circular Queue */
#include <stdio.h>
#include <conio.h>
#define SIZE 5

struct queue
{
	int data[SIZE];
	int front, rear;
};

/* fn declarations */
void initq(struct queue *);
void addq(struct queue *,int);
int delq(struct queue *);
void display(struct queue *);
int isqempty(struct queue *);
int isqfull(struct queue *);

void main()
{
	struct queue q;
	int choice, num;
	initq(&q);
	while (1)
	{
		clrscr();
		printf("Operations on Circular Queue\n\n");
		printf("1. Add to Queue\n");
		printf("2. Delete from Queue\n");
		printf("3. Display Queue\n");
		printf("4. Exit\n\n");
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
					printf("Enter no to add :- ");
					scanf("%d",&num);
					addq(&q,num);
				}
				break;


			case 2:
				if (isqempty(&q))
					printf("Queue is Empty");
				else
					printf("Element deleted is %d",delq(&q));

				getch();
				break;

			case 3:
				if (isqempty(&q))
					printf("Queue is Empty");
				else
					display(&q);

				getch();
				break;

			case 4:
				exit();
		}
	}
}

void initq(struct queue *pq)
{
	pq->front = pq->rear = -1;
}

void addq(struct queue *pq,int num)
{
	pq->rear = (pq->rear+1) % SIZE;
	pq->data[pq->rear] = num;
	/* check whether it is 1st element */
	if (pq->front == -1)
		pq->front = 0;
}

int delq(struct queue *pq)
{
	int no;
	no = pq->data[pq->front];
	pq->front = (pq->front+1) % SIZE;
	/* check whether front has crossed rear positio. If so,
	   reset front & rear to -1 bcoz now the queue is empty */
	if (pq->front == (pq->rear+1) % SIZE)
	{
		pq->front = -1;
		pq->rear = -1;
	}
	return no;
}

void display(struct queue *pq)
{
	int temp = pq->front;
	while (1)
	{
		printf("%d ",pq->data[temp]);
		temp = (temp + 1) % SIZE;
		if (temp == (pq->rear+1) % SIZE)
			break;
	}
}

int isqfull(struct queue *pq)
{
	if (pq->front == (pq->rear+1) % SIZE)
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