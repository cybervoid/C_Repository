/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080

void start_server()
{
    int socket_fd; //socket descriptor, an integer (like a file-handle)
    int new_socket; 
    int valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";
    
    /* Socket: creating socket file descriptor:
     *  domain: 
     *      integer, communication domain e.g., 
     *      AF_INET (IPv4 protocol), AF_INET6 (IPv6 protocol)
     *  protocol:
     *      Protocol value for Internet Protocol(IP), which is 0. 
     *      This is the same number which appears on protocol field 
     *      in the IP header of a packet.(man protocols for more 
     *      details) 
     */
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    /* setsockopt: Sets the options for the socket 
     *  summary: 
     *      This helps in manipulating options for the socket referred 
     *      by the file descriptor sockfd. This is completely optional,
     *      but it helps in reuse of address and port. Prevents error 
     *      such as: “address already in use”.
     */
    if (setsockopt(socket_fd, SOL_SOCKET, 
            SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
    /* Bind: 
     *      binding socket to port 8080
     *  summary: 
     *      After creation of the socket, bind function binds the 
     *      socket to the address and port number specified in 
     *      addr(custom data structure). In the example code, we 
     *      bind the server to the localhost, hence we use INADDR_ANY 
     *      to specify the IP address.
     */
    if(bind(socket_fd, (struct sockaddr *)&address, 
                            sizeof(address)) < 0)
    {
        //if binding fails...
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if(listen(socket_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(socket_fd, (struct sockaddr *)&address, 
                       (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    
    valread = read( new_socket, buffer, 1024);
    printf("%s\n", buffer);
    send(new_socket, hello, strlen(hello), 0);
    printf("hello message sent\n");
    return;
}
