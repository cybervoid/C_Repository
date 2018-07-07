/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ryanwemmer
 *
 * Created on July 6, 2018, 7:36 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "client.h"
#include "server.h"
/*
 * 
 */
int main(int argc, char** argv) {

    char *arg2 = argv[1];
    char c = 'c';
    char input = arg2[0];
    printf("\n arg2: %s", arg2);
    //int cmp = strcmp("c", arg2, 1);
    //printf("\n cmp number: %d", cmp);
    int result;
    if(c == input)
    {
        
        char *arg3 = argv[2];
        printf("%s\n", arg3);
        result = start_client(arg3);
    }      
    else 
    {
        result = start_server();
        //result = printf("\nserver!\n");
    }
    printf("Result: %d", result);
    return (EXIT_SUCCESS);
}

