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
void pointers_memaddr_example()
{
    int mem = 1;
    int *pointer;
    pointer = &mem; //a pointer takes a memory address
    printf("pointer value: %p", pointer);
}

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
    //#define LENGTH 3
    //int data [LENGTH]; //some integers
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
        printf("\titem pointed to by pi is %d\n", *pi); //de-reference to display the integer value
        printf("\titem pointed to by ppi is %p\n", *ppi); //gets the value at pi, which ppi points too
        //the following gets the actual number value stored in pi using two levels of pointers 
        printf("\titem pointed to by double indirection of ppi is %d\n", **ppi); //gets the value of the Pointer that the referenced pointer points to. [<-- not a typo. that's written correctly]
        printf("\tThe address of pi is %p \n\tThe value of pi (what it points to) is %p\n\n", &pi, ppi); //shows the value stored by the ppi variable is the address of the pi variable 
        printf("[x] The value of pi is %p (pi) and it points to %d (*pi)\n", pi, *pi);
        printf("--------------------------------------------\n");
        //advance the pointer to point to the next element of the data array
        pi += 1; // simple example of pointer arithmetic
        // (!!) - This advances through the loop with pointer arithmetic
    }
}
void multiple_indirection_chars()
{
    char *pc;   // a pointer to a character
    char **ppc; // a pointer to a pointer to a character
    char* words[LENGTH];
    printf("multiple indrection example\n");
    
    // initialize our string array
    words[0] = "zero";
    words[1] = "one";
    words[2] = "two";
    for(int i =0; i < LENGTH; i++)
    {
        printf("%s\n", words[i]);
    }
    
    /*
     * B: a pointer to an array of strings
     *  - the same as a pointer to a pointer to a character
     */
    printf("\nNow print the chars in each string...\n");
    ppc = words;
    for(int i = 0; i < LENGTH; i++) {
        ppc = words + i;
        pc = *ppc;
        while(*pc != 0) {
            printf("%c ", *pc);
            pc += 1;
        }
        printf("\n");
    }   
}
void address_sandbox()
{
    char str1[] = "my char array";
    char *xstr1 = &str1;
    printf("%s : %d | %s : %d", str1, str1, xstr1, &xstr1);
}

int main(int argc, char** argv) 
{
    multiple_indirection_chars();
    //multiple_indirection();
    //address_sandbox();
    //display_pointer_value();
    //strings();
    //pointerExample();
    return (EXIT_SUCCESS);
}
