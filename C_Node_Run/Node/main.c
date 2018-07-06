/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ryanwemmer
 *
 * Created on July 5, 2018, 7:56 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "server.c"
#include "server.h"
#include "client.c"
#include "client.h"
/*
 * 
 */
int main(int argc, char** argv) 
{
    char input = argv[1];
    char server = 's';
    char client = 'c';
    if(input == client) // start client
    {
        printf("client");
    }
        //start_client();
    if(input == server) //start server
    {
        printf("server");
    }    //start_server();
    return 0;
}

