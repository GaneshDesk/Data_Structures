/* Implementation of Dynamic Queue */
#include <stdio.h>
#include <conio.h>
#include <alloc.h>

struct node
{
	int data;
	struct node *next;
};

struct node *front, *rear;

/* fn declarations */
void addq(int);
int delq();
void displayq();
int isqempty();
void initq();

void main()
{
	int no, choice;
	initq();
	while (1)
	{
		clrscr();
		printf("Operations on Dynamic Queue\n\n");
		printf("1. ADD TO QUEUE\n");
		printf("2. DELETE FROM QUEUE\n");
		printf("3. DISPLAY QUEUE\n");
		printf("4. EXIT\n\n");
		printf("Enter your choice :- ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("Enter the no. :- ");
				scanf("%d",&no);
				addq(no);
				break;

			case 2:
				if (isqempty())
					printf("Queue is empty");
				else
					printf("Element deleted is %d",delq());

				getch();
				break;

			case 3:
				if (isqempty())
					printf("Queue is empty");
				else
					displayq();

				getch();
				break;

			case 4:
				exit();
		}
	}
}

void addq(int no)
{
	struct node *newnode;
	newnode = (struct node *) malloc(sizeof(struct node));
	newnode->data = no;
	newnode->next = NULL;
	/* check whether it is 1st element of queue */
	if (front == NULL)
	{
		front = newnode;
		rear = newnode;
	}
	else
	{
		rear->next = newnode;
		rear = newnode;
	}
}

int delq()
{
	struct node *temp;
	int no;
	no = front->data;
	temp = front;
	front = front->next;
	if (front == NULL)
		rear = NULL;

	free(temp);
	return no;
}

void displayq()
{
	struct node *temp;
	for (temp=front;temp != NULL;temp=temp->next)
		printf("%d ",temp->data);
}

int isqempty()
{
	if (front == NULL)
		return 1;

	return 0;
}

void initq()
{
	front = rear = NULL;
}


































