/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080
int start_client(char* ip) 
{
    printf("starting client %s\n", ip);
    int sockfd = 0, n = 0;
    char recvBuff[1024];
    struct sockaddr_in serv_addr; 

    //if(argc != 2)
    //{
    //    printf("\n Usage: %s <ip of server> \n",argv[0]);
    //    return 1;
    //} 

    memset(recvBuff, '0',sizeof(recvBuff));
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error : Could not create socket \n");
        return 1;
    } 

    memset(&serv_addr, '0', sizeof(serv_addr)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT); 
    printf("setting inet_pton\n");
    if(inet_pton(AF_INET, ip, &serv_addr.sin_addr)<=0)
    {
        printf("error: inet_pton error occured\n");
        return 1;
    } 
    printf("connecting to socket\n");
    if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
       printf("Error : Connect Failed \n");
       return 1;
    } 
    printf("read response...");
    while ( (n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
    {
        recvBuff[n] = 0;
        if(fputs(recvBuff, stdout) == EOF)
        {
            printf("Error : Fputs error\n");
        }
    } 
    if(n < 0)
    {
        printf("\n Read error \n");
    } 

    return 0;
}