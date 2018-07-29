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