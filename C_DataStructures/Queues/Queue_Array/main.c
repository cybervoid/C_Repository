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
	rear - 1;
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