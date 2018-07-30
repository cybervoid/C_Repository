/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ryanwemmer
 *
 * Created on July 29, 2018, 9:12 AM
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
void insertQueue(struct node *);
int queueEmpty();
int height(struct node *);
struct node *deleteQueue(struct node *);
struct node
{
    struct node *lchild;
    char info;
    struct node *rchild;
};

// parent: k/2
// right 2k
// left 2k+1

int main(int argc, char** argv) 
{
    return (0);
}

//preorder traversal -> n, l, r
void preorder(struct node *p)
{
    
    if(p == NULL)
        return;
    
    printf("%c ", p->info);
    preorder(p->lchild); 
    preorder(p->rchild);
}

//inorder traversal -> l, n, r
void inorder(struct node *p)
{
    if(p == NULL)
        return;
    
    inorder(p->lchild); 
    printf("%c ", p->info);
    inorder(p->rchild);
}

//postorder traversal -> l, r, n
void postorder(struct node *p)
{
    if(p == NULL)
        return;
    
    postorder(p->lchild); 
    postorder(p->rchild);
    printf("%c ", p->info);
}

//traverse node using level order
void level_order(struct node *p)
{
	if (p == NULL)
	{
		printf("Tree is empty\n");
		return;
	}
	insertQueue(p);

	while (!queueEmpty()) 
	{
		p = deleteQueue(p);
		printf("%c ", p->info);
		if (p->lchild != NULL)
			insertQueue(p->lchild);
		if (p->rchild != NULL)
			insertQueue(p->rchild);
	}
}
int height(struct node *p)
{
	int hL, hR;

	if (p == NULL)
		return 0;

	hL = height(p->lchild);
	hR = height(p->rchild);

	if (hL > hR)
		return 1 + hL;
	else
		return 1 + hR;
}
void insertQueue(struct node *p) 
{

}
int queueEmpty()
{

}

struct node *deleteQueue(struct node *p)
{

}