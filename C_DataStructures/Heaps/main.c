/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ryanwemmer
 *
 * Created on August 1, 2018, 8:14 AM
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define LARGE_VALUE 99999

void insert(int value, int a[], int *pn);
int deleteRoot(int a[], int *pn);
void restoreUp(int a[], int loc);
void restoreDown(int a[], int i, int size);
void display(int a[], int n);
/*
 * 
 */
int main() 
{
    int a[50];
    int n = 0; //size of heap
    int choice, value;
    
    a[0] = LARGE_VALUE; //sentinel, all keys in heap should be less than this
    
    while(1)
    {
        printf("1. Insert\n");
        printf("2. delete root\n");
        printf("3. display\n");
        printf("4. exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        
        if(choice == 4)
        {
            printf("goodbye!");
            break;
        }
        switch(choice)
        {
            case 1:
                printf("Enter the value to be inserted:");
                scanf("%d", &value);
                insert(value, a, &n);
                break;
            case 2:
                if(n == 0)
                    printf("Heap is empty.\n");
                else
                {
                    value = deleteRoot(a, &n);
                    printf("maximum value is %d\n", value);
                }
                break;
            case 3:
                display(a, n);
                break;
            default:
                printf("wrong choice\n");
                            
        }
    }
    
    return 0;
}

void insert(int value, int a[], int *pn)
{
    (*pn)++;
    a[*pn]=value;
    restoreUp(a, *pn);
}

void restoreUp(int a[], int i)
{
    int k = a[i];
    int iparent = i / 2;
    //without sentinel, use these conditions:
    //while(iparent >=1 && a[iparent]<k)
    while(a[iparent]<k)        
    {
        a[i]=a[iparent];
        i=iparent;
        iparent = i/2;
    }
    a[i]=k;
}

int deleteRoot(int a[], int *pn)
{
    int maxValue = a[1];
    a[1]=a[*pn];
    (*pn)--;
    restoreDown(a,1,*pn);
    return maxValue;
}

void restoreDown(int a[], int i, int n)
{
    int k = a[i];
    int lchild = 2*i, rchild=lchild+1;
    
    while(rchild <= n)
    {
        if(k >= a[lchild] && k >= a[rchild])
        {
            a[i] = k;
            return;
        }
        else if(a[lchild] > a[rchild])
        {
            a[i] = a[lchild];
            i = lchild;
        }
        else
        {
            a[i] = a[rchild];
            i = rchild;
        }
        lchild = 2 * i;
        rchild = lchild + 1;
    }
    //if number of nodes is even
    if(lchild == n && k < a[lchild])
    {
        a[i] = a[lchild];  
        i = lchild;
    }
    a[i] = k;
}