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
int main(int argc, char** argv) 
{
    display_pointer_value();
    //strings();
    //pointerExample();
    return (EXIT_SUCCESS);
}
