#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 50


struct node
{
	int info;
	struct node *link;
};
struct node *top;
void initializeStack();
int isEmpty();
int size();
void push(int x);
int pop();
int peek();
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
		{
			printf("goodbye!");
			break;
		}
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
}

void initializeStack()
{
	top = NULL;
}

int size()
{
	int s = 0;
	struct node *p = top;

	while (p != NULL)
	{
		p = p->link;
		s = s + 1;
	}
	return s;
}

void push(int x)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("no memory: stack overflow\n");
		return;
	}
	temp->info = x;
	temp->link = top;
	top = temp;
}

int pop() 
{
	struct node *temp;
	int x;
	if (isEmpty())
	{
		printf("stack underflow\n");
		exit(1);
	}
	temp = top;
	x = temp->info;
	top = top->link;
	free(temp);
	return x;
}

int peek()
{
	if (isEmpty())
	{
		printf("stack underflow\n");
		exit(1);
	}
	return top->info;
}

int isEmpty()
{
	if (top == NULL)
		return 1;
	else
		return 0;
}

void display()
{
	struct node *p;
	p = top;
	if (isEmpty())
	{
		printf("Stack is empty\n");
		return;
	}

	printf("stack is : \n\n");
	while (p != NULL)
	{
		printf(" %d\n", p->info);
		p = p->link;
	}
	printf("\n");
}