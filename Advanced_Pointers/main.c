/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ryanwemmer
 *
 * Created on July 8, 2018, 11:22 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
#define LENGTH 3
int data [LENGTH]; //some integers
void pointerExample()
{
    int num;
    int* numPtr;
    int num2;
    num = 100;
    numPtr = &num; //gets address of num variable.
    num2 = *numPtr;
    printf("num=%d, numPtr=%d, address of num=%d, num2=%d\n", num, numPtr, &num, num2);
}

void indirection()
{
    int num;
    int* numPtr;
    int num2;
    num = 100;
    numPtr = &num; //gets address of num variable.
    num2 = *numPtr;
    printf("num=%d, numPtr=%d, address of num=%d, num2=%d\n", num, numPtr, &num, num2);    
}

void strings() 
{
    char str1[] = "Hello world!";
    printf("%s %c %d %d %d\n", str1, str1[0], &str1, &str1[0], str1);
    return;
}

void display_pointer_value() 
{
    char str1[] = "hello";
    char *str2 = "Goodbye";
    printf("%d %d %s\n", &str1, str1, str1);
    printf("%d %d %s\n", &str2, str2, str2);
}

void multiple_indirection()
{
    int *pi;    // a simple pointer to an integer
    int **ppi;  // a pointer to a point to an integer
    
    printf("multiple indirection example\n");
    // initialize our integer arry
    for(int i = 0; i < LENGTH; i++)
    {
        data[i] = i;
    }
    for(int i = 0; i < LENGTH; i++)
    {
        printf("%d\n", data[i]);
    }
    /*
     * A: simple pointer to an integer
     */
    pi = data;
    ppi = &pi;
    
    for(int i = 0; i < LENGTH; i++) {
        printf("- Loop{%d} array address is %p\n", i, data);
        printf("\titem pointed to by pi is %d\n", *pi);
        printf("\titem pointed to by double indirection of ppi is %d\n", **ppi);
        printf("The address of pi is %p and the value of pi (what it points to) is %p\nn", &pi, ppi);
    }
}

void address_sandbox()
{
    int mem = 1;
    int *pointer;
    pointer = &mem; //a pointer takes a memory address
    printf("pointer value: %p", pointer);
    //char str1[] = "my char array";
    //char *xstr1 = &str1;
    //printf("%s : %d | %s : %d", str1, str1, xstr1, &xstr1);
}

int main(int argc, char** argv) 
{
    //multiple_indirection();
    address_sandbox();
    //display_pointer_value();
    //strings();
    //pointerExample();
    return (EXIT_SUCCESS);
}
