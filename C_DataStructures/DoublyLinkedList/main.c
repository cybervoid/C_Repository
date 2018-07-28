#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


struct node
{
	struct node *prev;
	int info;
	struct node *next;
};