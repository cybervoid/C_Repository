/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ryanwemmer
 *
 * Created on July 5, 2018, 7:25 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    direction d = 1;
    direction d2 = direction.down;
    direction both = (d + d2);
    printf(both);
    return (EXIT_SUCCESS);
}

enum direction {up = 1, down = 2, left = 3, right = 4 };