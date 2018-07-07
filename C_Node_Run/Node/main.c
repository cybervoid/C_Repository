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

    char *arg1 = argv[1];
    int s = strncmp("c", arg1, 1);
    int result;
    if(s = 1)
    {
        result = start_client();
    }      
    else 
    {
        result = printf("\nserver!\n");
    }
    printf("Result: %d", result);
    return (EXIT_SUCCESS);
}

