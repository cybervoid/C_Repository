#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 
struct node
{
	int info;	
	struct node *link;
};


void displayList(struct node *start)
{

}

void countNodes(struct node *start)
{

}
void search(struct node *start, int *data) 
{

}
struct node* insertInBeginning(struct node *start, int *data)
{

}
void insertAtEnd(struct node *start, int *data)
{

}
void insertAfter(struct node *start, int *data, int *x)
{

}

struct node* insertBefore(struct node *start, int *data, int *x)
{

}

struct node* deleteNode(struct node *start, int *data)
{

}

struct node* reverseList(struct node *start) 
{

}
int main(int argc, char** argv)
{
	struct node *start = NULL; //declare a new linked list
	start = createList(start);
	while (1)
	{
		int choice, data, x, k;
		printf("\n");
		printf("[1] Display list\n");
		printf("[2] Count the number of nodes\n");
		printf("[3] Search for an element\n");
		printf("[4] Add to empty list / Add at beginning\n");
		printf("[5] Add a node at end of the list\n");
		printf("[6] Add a node after a specified node\n");
		printf("[7] Add a node before a specified node");
		printf("[8] Add a node at a given position\n");
		printf("[9] Delete a node\n");
		printf("[10] Reverse the list\n");
		
		printf("Enter your choice:");
		scanf("%d", &choice);
		if (choice >= 11)
			break;

		switch (choice)
		{
			case 1:
				displayList(start);
			case 2:
				countNodes(start);
			case 3:
				printf("Enter the element to be searched:");
				scanf("%d", &data);
				search(start, data);
				break;
			case 4:
				printf("Enter the element to be inserted:");
				scanf("%d", &data);
				start = insertInBeginning(start, data);
				break;
			case 5:
				printf("Enter the element to be inserted:");
				scanf("%d", &data);
				insertAtEnd(start, data);
				break;
			case 6: 
				printf("Enter the element to be inserted:");
				scanf("%d", &data);
				printf("Enter the element after which to insert:");
				scanf("%d", &x);
				insertAfter(start, data, x);
				break;
			case 7:
				printf("Enter the element to be inserted:");
				scanf("%d", &data);
				printf("Enter the element before which to insert:");
				scanf("%d", &x);
				start = insertBefore(start, data, x);
			case 8:
				printf("Enter the element to be inserted:");
				scanf("%d", &data);
				printf("Enter the position at which to be inserted:");
				scanf("%d", &k);
				start = insertAtPosition(start, data, k);
			case 9:
				printf("Enter the element to be deleted:");
				scanf("%d", &data);
				start = deleteNode(start, data);
				break;
			case 10:
				start = reverseList(start, data);
				break;
		}
	}
}