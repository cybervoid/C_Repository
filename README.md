# C_Repository
A repository for writing code in C. 

## Overview
This repository intends to cover the various topics necessary for a stronger understanding in computer science.

## Repository Contents
1. [C_Beginners](./C_Beginners) - a repository for C programming beginners, based upon Udemy C Programming. See [Resources Section](#resources) class for C beginners.
2. [C_Node_Run](./C_Node_Run) - a basic node program with the intended goal of including computer science fundamentals:
    - tcp/ip socket(s)
    - threads (pthreads)
    - and maybe semaphores
3. [Advanced_Pointers](./Advanced_Pointers) - Based upon the Udemy course [Advanced C Programming - Pointers](https://www.udemy.com/advanced-c-programming-pointers/learn/v4/). Includes Netbeans and Visual Studio workspace.
4. [PThreads](./PThreads) - a simple project with a pthread example.
5. [RaspberryPI_Setup](./RaspberryPI_Setup) -  Setup instructions for raspberry pi setup
6. [C_DataStructures](./C_DataStructures) - a workspace to review the fundamental computer science concept of data structures.

## Quick Reference
1. Pointers and memory addresses | [Example](https://github.com/cybervoid/C_Repository/blob/master/Advanced_Pointers/main.c#L30)
```
int mem = 1;
int *pointer;
pointer = &mem; //a pointer takes a memory address
printf("pointer value: %p", pointer);
//output: "pointer value: 0x7ffee2e81a0c"
int *pointerII;
pointerII = mem;
printf("pointer value: %d", pointer);
//output: "pointer value: 1"
```

## Resources
1. [Udemy C Programming Course](https://www.udemy.com/c-programming-for-beginners-/learn/v4/)
2. [CodeBlocks](http://codeblocks.org/) - C and C++ developer environment
3. [C Pointers (Advanced Programming)](https://www.udemy.com/advanced-c-programming-pointers/learn/v4/t/lecture/6863158?start=0)
4. [Tutorial: Netbeans debugger](https://netbeans.org/kb/docs/cnd/debugging.html#requirements) - A walkthrough for the debugger for netbeans.
    - [Install gdb](https://stackoverflow.com/questions/35497491/netbeans-resolve-missing-debugger-command-c) - installing gdb debugger on OSX.
    - ["Codedesign" Taskgated Permissions on mac (darwin)](https://github.com/cs01/gdbgui/issues/55)
5. Creating a C Project in Visual Studio| [Clip](https://www.youtube.com/watch?v=YOLN-t09-tM)
