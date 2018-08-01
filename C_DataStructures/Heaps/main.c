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
    
    a[0] = LARGE_VALUE; //sentinal, all keys in heap should be less than this
    
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
