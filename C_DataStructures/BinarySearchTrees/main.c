/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ryanwemmer
 *
 * Created on July 30, 2018, 8:59 AM
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void insert(int value);
struct node *search_recursive(struct node *, int);
struct node *search_while(struct node *, int);
struct node *Min(struct node *);
struct node *Max(struct node *);
struct node *getnode(char);
struct node
{
    int info;
    struct node *lchild;
    struct node *rchild;
};
int main() {

    return (0);
}

struct node *search_recursive(struct node *p, int target)
{
    if(p == NULL)
    {
        printf("%d not found", target);
        return NULL;
    }
    if(p->info == target)
        return p;
    
    if(target < p->info)
        return search_recursive(p->lchild, target);
    
    if(target > p->info)
        return search_recursive(p->rchild, target);

	return NULL;
}

struct node *getnode(char c)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p->info = c;
	p->lchild = NULL;
	p->rchild = NULL;
	return p;
}
struct node *search_while(struct node *p, int target)
{
    
    while(p != NULL)
    {
        if(target < p->info)
            p = p->lchild;
        else if(target > p->info)
            p=p->rchild;
        else
            return p;
    }
    return NULL;
}

void insert(struct node *root, int x)
{
	struct node *temp, *parent, *p;

	p = root;
	parent = NULL;

	while (p != NULL)
	{
		parent = p;
		if (x < p->info)
			p = p->lchild;
		else if (x > p->info)
			p = p->rchild;
		else
		{
			printf("%d already present in the tree\n", x);
			return root;
		}

		temp = getnode(x);
	}
}

struct node *Min(struct node *p)
{
	if (p == NULL)
		return NULL;
	while (p->lchild != NULL)
		p = p->lchild;
	return p;
}

struct node *Max(struct node *p)
{
	if (p == NULL)
		return NULL;
	while (p->rchild != NULL)
		p = p->rchild;
	return p;
}