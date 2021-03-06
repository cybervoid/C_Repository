#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>


struct node *insertInBeginning(struct node *, int);
void insertAtEnd(struct node *, int);
struct node *get_position(struct node *, int);
struct node *insert_node(struct node *);
void insertAfter(struct node *, int, int );
struct node* insertBefore(struct node *, int, int);
struct node* insertAtPosition(struct node *, int, int);
struct node* deleteNode(struct node *, int);
struct node
{
	int info;	
	struct node *link;
};


void displayList(struct node *start)
{
	struct node *p;
	if (start == NULL)
	{
		printf("list is empty \n");
		return;
	}

	printf("list is : ");
	p = start; 	
	while (p != NULL)
	{
		printf("%d ", p->info);
		p = p->link;
	}
	printf("\n");
}

struct node* createList(struct node *start)
{	
	int i, n, data;

	printf("Enter the number of nodes : ");
	scanf("%d", &n);

	if (n == 0)
		return start;

	printf("Enter the first element to be inserted : ");
	scanf("%d", &data);
	start = insertInBeginning(start, data);

	for (i = 2; i <= n; i++)
	{
		printf("Enter the next element to be inserted : ");
		scanf("%d", &data);
		insertAtEnd(start, data);
	}
	return start;
}

struct node* secondToLastNode(struct node *start)
{
	struct node *p = start;
	while (p->link->link != NULL)
		p = p->link;

	return p;
}
struct node* create_node(int data)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;
	return temp;
}


void countNodes(struct node *start)
{
	int n = 0;
	struct node *p = start;
	while (p != NULL)
	{
		n++;
		p = p->link;
	}
	printf("Number of nodes = %d\n", n);

}
void search(struct node *start, int x)
{
	int position = 1;
	struct node* p = start;
	while (p != NULL)
	{
		if (p->info == x)
			break;
		position++;
		p = p->link;
	}
	if (p == NULL)
		printf("%d not found in list\n", x);
	else
		printf("%d is at position %d\n", x, position);
	
}

struct node* reverseList(struct node *start) 
{
	struct node *prev, *ptr, *next;

	prev = NULL;
	ptr = start;
	while (ptr != NULL)
	{
		next = ptr->link;
		ptr->link = prev;
		prev = ptr;
		ptr = next;
	}

}

int main(int argc, char** argv)
{
	struct node *start = NULL; //declare a new linked list
	int choice, data, x, k;
	start = createList(start);	
	while (1)
	{
		
		printf("\n");
		printf("[1] Display list\n");
		printf("[2] Count the number of nodes\n");
		printf("[3] Search for an element\n");
		printf("[4] Add to empty list / Add at beginning\n");
		printf("[5] Add a node at end of the list\n");
		printf("[6] Add a node after a specified node\n");
		printf("[7] Add a node before a specified node\n");
		printf("[8] Add a node at a given position\n");
		printf("[9] Delete a node\n");
		printf("[10] Reverse the list\n");
		
		printf("Enter your choice: ");
		scanf("%d", &choice);
		if (choice >= 11)
			break;

		switch (choice)
		{
			case 1:
				displayList(start);
				break;
			case 2:
				countNodes(start);
				break;
			case 3:
				printf("Enter the element to be searched: ");
				scanf("%d", &data);
				search(start, data);
				break;
			case 4:
				printf("Enter the element to be inserted: ");
				scanf("%d", &data);
				start = insertInBeginning(start, data);
				break;
			case 5:
				printf("Enter the element to be inserted: ");
				scanf("%d", &data);
				insertAtEnd(start, data);
				break;
			case 6: 
				printf("Enter the element to be inserted: ");
				scanf("%d", &data);
				printf("Enter the element after which to insert: ");
				scanf("%d", &x);
				insertAfter(start, data, x);
				break;
			case 7:
				printf("Enter the element to be inserted: ");
				scanf("%d", &data);
				printf("Enter the element before which to insert: ");
				scanf("%d", &x);
				start = insertBefore(start, data, x);
				break;
			case 8:
				printf("Enter the element to be inserted: ");
				scanf("%d", &data);
				printf("Enter the position at which to be inserted: ");
				scanf("%d", &k);
				start = insertAtPosition(start, data, k);
                break;
			case 9:
				printf("Enter the element to be deleted:");
				scanf("%d", &data);
				start = deleteNode(start, data);
				break;
			case 10:
				start = reverseList(start, data);
				break;
			default:
				printf("Invalid Choice Selected\n");
				break;
		}
	}
}
struct node *insertInBeginning(struct node *start, int data)
{ 
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;
	temp->link = start;
	start = temp;
	return start;
}
void insertAtEnd(struct node *start, int data)
{
	struct node *p, *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info=data;
        
        p = start;
	while(p->link != NULL)
	{
            p = p->link;
	}
	p->link = temp;
	temp->link = NULL;
}

struct node *get_position(struct node *start, int position)
{
    struct node* p;
    p = (struct node *)malloc(sizeof(struct node));
    p = start;
    for(int i = 1; i < position && p !=NULL; i++)
    {
        p = p->link;
    }
    return p;
}

struct node *insert_node(struct node * parent, int data)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;
	temp->link = parent->link;
	parent->link = temp;
	return temp;
}

void insertAfter(struct node *start, int data, int x)
{
	struct node *temp, *p;
	
	p = start;
	while (p != NULL)
	{
		if (p->info == x)
			break;
		p = p->link;
	}
	if (p == NULL)
		print("%d not present in the list\n", x);
	else 
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->info = data;
		temp->link = p->link;
		p->link = temp;
	}
}

struct node* insertBefore(struct node *start, int data, int x)
{
	struct node *temp, *p;
	temp = (struct node *)malloc(sizeof(struct node));
	p = start;
	while (p->link != NULL)
	{
		if (p->link->info == x)
			break;
		p = p->link;
	}

	temp->link = p->link;
	p->link = temp;
	temp->info = data;
	return temp;
}
struct node* insertAtPosition(struct node *start, int data, int k_position)
{
	struct node *temp, *p;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;
	p = start;
	for (int i = 1; i < k_position - 1 && p != NULL; i++)
	{
		p = p->link;
	}

	temp->link = p->link;
	p->link = temp;
	return start;
}


struct node* deleteNode(struct node *start, int dataToDelete)
{
	struct node *temp, *p;

	if (start == NULL)
	{
		printf("list is empty");
		return start;
	}
	//deletion of first node
	if (start->info == dataToDelete)
	{
		temp = start; 
		start = start->link;
		free(temp);
		return start;
	}
	//deletion in between or at the end
	p = start;
	while (p->link != NULL)
	{
		if (p->link->info == dataToDelete)
			break;
		
		p = p->link;
	}

	if (p->link == NULL)
		printf("element %d not in list\n\n", dataToDelete);
	else 
	{
		temp = p->link;
		p->link = temp->link;
		free(temp);
	}
	return start;
}