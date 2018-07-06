/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   command_line_arguments.c
 * Author: ryanwemmer
 *
 * Created on July 6, 2018, 6:16 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Supplements the main method but will allow compilation
 */
int pretend_main(int argc, char *argv[]) {

    int numberOfArguments = argc;
    char *argument1 = argv[0]; //setting argument1 equal to program name
    char *argument2 = argv[1];
    printf("Number of arguments: %d", numberOfArguments);
    printf("argument1 Name of program: %s", argument1);
    printf("argument2 command line argument: %s", argument2);
    return (EXIT_SUCCESS);
}

