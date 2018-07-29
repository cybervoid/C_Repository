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
    return (EXIT_SUCCESS);
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

//inorder traversal -> l, r, n
void postorder(struct node *p)
{
    if(p == NULL)
        return;
    
    postorder(p->lchild); 
    postorder(p->rchild);
    printf("%c ", p->info);
}