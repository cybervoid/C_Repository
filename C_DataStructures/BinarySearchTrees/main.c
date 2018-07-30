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


struct node *search(struct node *, int);
struct node
{
    int info;
    struct node *lchild;
    struct node *rchild;
};
int main() {

    return (0);
}

struct node *search(struct node *p, int target)
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
