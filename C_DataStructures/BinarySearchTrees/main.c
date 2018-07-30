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


struct node *search_recursive(struct node *, int);
struct node *search_while(struct node *, int);
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
        search(p->lchild, target);
    
    if(target > p->info)
        search(p->rchild, target);
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