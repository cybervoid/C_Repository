#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 50


int a[MAX];
int top;

void initializeStack();
int isEmpty();
int isFull();
int size();
int peek();
void push(int x);
int pop();
void display();

int main()
{
	int choice, x;

	initializeStack();

	while (1)
	{
		printf("1. Push an element on the stack \n");
		printf("2. Pop an element from the stack \n");
		printf("3. Display the top element\n");
		printf("4. Display all stack elements\n");
		printf("5. Display size of the stack\n");
		printf("6. Quit.\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);

		if (choice == 6)
			break;

		switch (choice) 
		{
			case 1:
				printf("Enter the element to be pushed: ");
				scanf("%d", &x);
				push(x);
				break;
			case 2:
				x = pop();
				printf("Popped element is: %d\n", x);
				break;
			case 3:
				printf("Element at the top is : %d\n", peek());
				break;
			case 4:
				display();
				break;
			case 5:
				printf("size of stack = %d\n", size());
				break;
			default:
				printf("invalid selection, please try again");
				break;
		}
		printf("\n");
	}
	return 0;
}

void initializeStack()
{
	top = -1;
}

int size()
{
	return top + 1;
}

int isEmpty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

int isFull()
{
	if (top == MAX - 1)
		return 1;
	else 
		return 0;
}

void push(int x)
{
	if (isFull())
	{
		printf("error: Stack overflow \n");
		return;
	}
	top = top + 1;
	a[top] = x;
}

int pop()
{
	int x;
	if (isEmpty())
	{
		printf("error: stack underflow");
		exit(1);
	}
	x = a[top];
	top = top - 1;
	return x;
}

int peek()
{
	if (isEmpty())
	{
		printf("error: stack underflow\n");
		exit(1);
	}
	return a[top];
}

void display()
{
	int i;

	printf("top=%d\n", top);

	if (isEmpty())
	{
		printf("Stack is empty\n");
		return;
	}
	printf("stack is : \n\n");
	for (i = top; i >= 0; i--)
		printf(" %d\n", a[i]);

	printf("\n");
}