# C_Repository
A repository for writing code in C


## Repository Contents
1. [C_Beginners](./C_Beginners) - a repository for C programming beginners, based upon Udemy C Programming. See [Resources Section](#resources) class for C beginners.
2. [C_Node_Run](./C_Node_Run) - a basic node program with the intended goal of including computer science fundamentals:
    - tcp/ip socket(s)
    - threads (pthreads)
    - and maybe semaphores

## Quick Reference
1. Pointers and memory addresses | [Example](https://github.com/cybervoid/C_Repository/blob/b4fad643bed657a25dcb54cace9618ff35145cbd/Advanced_Pointers/main.c#L90)
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
