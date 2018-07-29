#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *link;
};

struct node *front, *rear;

void initializeQueue();
int size();
void enqueue(int x);
int dequeue();
int peek();
int isEmpty();
void display();
int main()
{
	int choice, x;

	initializeQueue();

	while (1)
	{
		printf("1. Enqueue an element in the queue \n");
		printf("2. Dequeue an element from the queue \n");
		printf("3. Display the element at the front\n");
		printf("4. Display all queue elements\n");
		printf("5. Display size of the queue\n");
		printf("6. Quit.\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);

		if (choice == 6)
		{
			printf("goodbye!");
			break;
		}

		switch (choice)
		{
		case 1:
			printf("Enter the element to be pushed: ");
			scanf("%d", &x);
			enqueue(x);
			break;
		case 2:
			x = dequeue();
			printf("Popped element is: %d\n", x);
			break;
		case 3:
			printf("Element at front of queue: %d\n", peek());
			break;
		case 4:
			display();
			break;
		case 5:
			printf("Size of queue is %d\n", size());
			break;
		default:
			printf("invalid selection, try again.");
			break;
		}
	}
}

void initializeQueue()
{
	front = NULL;
	rear = NULL;
}

int size()
{
	int s = 0;
	struct node *p = front;
	while (p != NULL)
	{
		s++;
		p = p->link;
	}
	return s;
}

void enqueue(int x)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("Memory not available\n");
		return;
	}
	temp->info = x;
	temp->link = NULL;

	if (front == NULL)
		front = temp;
	else
		rear->link = temp;
	rear = temp;
}

int dequeue()
{
	struct node *temp;
	int x;
	if (isEmpty())
	{
		printf("Queue underflow\n");
		exit(1);
	}

	temp=front;
	x = temp->info;
	front = front->link;
	free(temp);
	return x;
}

int peek()
{
	if (isEmpty())
	{
		printf("queue underflow\n");
		exit(1);
	}
	return front->info;
}

int isEmpty()
{
	if (front == NULL)
		return 1;
	else
		return 0;
}

void display()
{
	struct node *p;
	p = front; 
	if (isEmpty())
	{
		printf("queue is empty\n");
		return;
	}
	printf("Queue is:\n\n");
	while (p != NULL)
	{
		printf("%d ", p->info);
		p = p->link;
	}

	printf("\n\n");
}