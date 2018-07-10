/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ryanwemmer
 *
 * Created on July 10, 2018, 10:19 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
/*
 * 
 */

// A normal C function that is executed as a thread 
// when its name is specified in pthread_create()
void *myThread(void *vargp)
{
    int count;
    count = 0;
    while(count < 10)
    {
        sleep(1);
        printf("Printing count from thread %d\n", count);
        count++;
    }
    return NULL;
}
int main(int argc, char** argv) 
{
    pthread_t thread_id;
    printf("before thread\n");
    pthread_create(&thread_id, NULL, myThread, NULL);
    pthread_join(thread_id, NULL);
    printf("thread complete");
    return (EXIT_SUCCESS);
}

