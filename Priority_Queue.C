/* An eg. of DESC Priority Queue */
#include <stdio.h>
#include <conio.h>
#define SIZE 5

struct queue
{
	int num;
	int flag;
};

int front, rear;

void initq();
void addq(struct queue [],int);
int delq(struct queue []);
void displayq(struct queue []);
int isqempty();
int isqfull();


void main()
{
	struct queue pq[SIZE];
	int choice, no;
	initq();
	while (1)
	{
		clrscr();
		printf("Operations on Desc Priority Queue\n\n");
		printf("1. ADD TO QUEUE\n");
		printf("2. DELETE FROM QUEUE\n");
		printf("3. DISPLAY QUEUE\n");
		printf("4. EXIT\n\n");
		printf("Enter your choice :- ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				if (isqfull())
				{
					printf("Queue is full");
					getch();
				}
				else
				{
					printf("Enter the no :- ");
					scanf("%d",&no);
					addq(pq,no);
				}
				break;

			case 2:
				if (isqempty())
					printf("Queue is empty");
				else
					printf("Element deleted is %d",delq(pq));

				getch();
				break;

			case 3:
				if (isqempty())
					printf("Queue is empty");
				else
					displayq(pq);

				getch();
				break;

			case 4:
				exit();
		}
	}
}

void addq(struct queue pq[],int no)
{
	rear++;
	pq[rear].num = no;
	pq[rear].flag = 0;
	if (front == -1)
		front = 0;
}

void displayq(struct queue pq[])
{
	int i;
	for (i=front;i <= rear;i++)
	{
		if (pq[i].flag == 0)
			printf("%d ",pq[i].num);
	}
}

int delq(struct queue pq[ ])
{
	int i, pos, max;
	/* find the 1st undeleted element */
	for (i=front;i <= rear;i++)
	{
		if (pq[i].flag == 0)
		{
			max = pq[i].num;
			pos = i;
			break;   /* search terminates */
		}
	}
	/* continue the search for max element further */
	for (i=pos+1;i <= rear;i++)
	{
		if (max < pq[i].num && pq[i].flag == 0)
		{
			max = pq[i].num;
			pos = i;
		}
	}
	/* delete the element at pos */
	pq[pos].flag = 1;
	/* now check if the element deleted now was the last element.
	   If so, it means that now the q is empty & a fresh batch of
	   elements can be accepted */
	pos = -1;    /* used like a flag */
	for (i=front;i <= rear;i++)
	{
		if (pq[i].flag == 0)
		{
			pos = i;
			break;
		}
	}
	if (pos == -1)    /* means all el's are now deleted. so reset
				front and rear */
		initq();

	return max;
}

void initq()
{
	front = rear = -1;
}

int isqfull()
{
	if (rear == SIZE-1)
		return 1;

	return 0;
}

int isqempty()
{
	if (front == -1)
		return 1;

	return 0;
}






















