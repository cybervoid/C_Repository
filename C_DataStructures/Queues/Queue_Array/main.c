#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void enqueue(int);
int dequeue();
void initializeQueue();
int isFull();
int isEmpty();
int size();
int peek();
int front, rear;
int a[MAX];
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

		switch(choice)
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
				printf("Print Element at front of queue", peek());
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

void enqueue(int x)
{
	rear = rear + 1;
	if (rear > MAX)
	{
		printf("queue overflow");
		exit(1);
	}
	a[rear] = x;
}
void initializeQueue()
{
	front = -1;
	rear = -1;
}
int isFull()
{
	if (rear == MAX - 1)
		return 1;
	else
		return 0;
}
int isEmpty()
{
	if (front == -1 || front == rear + 1)
		return 1;
	else
		return 0;
}

int size()
{
	if (isEmpty())
	{
		return 0;
	}
	else 
	{
		return rear - front + 1;
	}
}

void enqueue(int x)
{
	if (isFull())
	{
		printf("Queue overflow\n");
		return;
	}
	if (front == -1)
		front = 0;

	rear = rear + 1;
	a[rear] = x;
}

int dequeue()
{
	int x;
	if (isEmpty())
	{
		printf("queue underflow\n");
		exit(1);
	}
	x = a[front];
	front = front + 1;
	return x;
}

int peek()
{
	if (isEmpty())
	{
		printf("queue underflow\n");
		exit(1);
	}
	return a[front];
}

void display()
{
	int i;
	if (isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}
	printf("-----------------\n");
	printf("queue is : \n\n");
	for (i = front; i <= rear; i++)
		printf("%d  ", a[i]);

	printf("\n\n");
}