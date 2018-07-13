
//disable compiler warnings: 

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/*
*
*/
#define _CRT_SECURE_NO_WARNINGS 
#define LENGTH 3
#define MAXSTRLEN 100
int data[LENGTH]; //some integers
char* words[LENGTH];






void pointers_memaddr_example()
{
	int mem = 1;
	int *pointer;
	pointer = &mem; //a pointer takes a memory address
	printf("pointer value: %p", pointer);
}

void pointerExample()
{
	int num;
	int* numPtr;
	int num2;
	num = 100;
	numPtr = &num; //gets address of num variable.
	num2 = *numPtr;
	printf("num=%d, numPtr=%d, address of num=%d, num2=%d\n", num, numPtr, &num, num2);
}

void indirection()
{
	int num;
	int* numPtr;
	int num2;
	num = 100;
	numPtr = &num; //gets address of num variable.
	num2 = *numPtr;
	printf("num=%d, numPtr=%d, address of num=%d, num2=%d\n", num, numPtr, &num, num2);
}

void main_test(int argc, char **argv) {

}

void strings()
{
	char str1[] = "Hello world!";
	printf("%s %c %d %d %d\n", str1, str1[0], &str1, &str1[0], str1);
	return;
}

void display_pointer_value()
{
	char str1[] = "hello";
	char *str2 = "Goodbye";
	printf("%d %d %s\n", &str1, str1, str1);
	printf("%d %d %s\n", &str2, str2, str2);
}

void multiple_indirection()
{
	//#define LENGTH 3
	//int data [LENGTH]; //some integers
	int *pi;    // a simple pointer to an integer
	int **ppi;  // a pointer to a point to an integer

	printf("multiple indirection example\n");
	// initialize our integer arry
	for (int i = 0; i < LENGTH; i++)
	{
		data[i] = i;
	}
	for (int i = 0; i < LENGTH; i++)
	{
		printf("%d\n", data[i]);
	}
	/*
	* A: simple pointer to an integer
	*/
	pi = data;
	ppi = &pi;

	for (int i = 0; i < LENGTH; i++) {

		printf("- Loop{%d} array address is %p\n", i, data);
		printf("\titem pointed to by pi is %d\n", *pi); //de-reference to display the integer value
		printf("\titem pointed to by ppi is %p\n", *ppi); //gets the value at pi, which ppi points too
														  //the following gets the actual number value stored in pi using two levels of pointers 
		printf("\titem pointed to by double indirection of ppi is %d\n", **ppi); //gets the value of the Pointer that the referenced pointer points to. [<-- not a typo. that's written correctly]
		printf("\tThe address of pi is %p \n\tThe value of pi (what it points to) is %p\n\n", &pi, ppi); //shows the value stored by the ppi variable is the address of the pi variable 
		printf("[x] The value of pi is %p (pi) and it points to %d (*pi)\n", pi, *pi);
		printf("--------------------------------------------\n");
		//advance the pointer to point to the next element of the data array
		pi += 1; // simple example of pointer arithmetic
				 // (!!) - This advances through the loop with pointer arithmetic
	}
}
void multiple_indirection_chars()
{
	char *pc;   // a pointer to a character
	char **ppc; // a pointer to a pointer to a character

	printf("multiple indrection example\n");

	// initialize our string array
	words[0] = "zero";
	words[1] = "one";
	words[2] = "two";
	for (int i = 0; i < LENGTH; i++)
	{
		printf("%s\n", words[i]);
	}

	/*
	* B: a pointer to an array of strings
	*  - the same as a pointer to a pointer to a character
	*/
	printf("\nNow print the chars in each string...\n");
	ppc = words;
	for (int i = 0; i < LENGTH; i++) {
		ppc = words + i;
		pc = *ppc;
		while (*pc != 0) {
			printf("%c ", *pc);
			pc += 1;
		}
		if (*pc == 0)
			printf("e: %d", *pc); // *pc == false?
		printf("\n");
	}
}
void address_sandbox()
{
	char str1[] = "my char array";
	char *xstr1 = &str1;
	printf("%s : %d | %s : %d", str1, str1, xstr1, &xstr1);
}

void generic_pointers()
{
	void *gp;
	printf("generic pointer example\n");
	// initialize our integer array
	for (int i = 0; i < LENGTH; i++)
	{
		data[i] = i;
	}
	for (int i = 0; i < LENGTH; i++) {
		printf("%d\n", data[i]);
	}
	// initialize our string array
	words[0] = "zero";
	words[1] = "one";
	words[2] = "two";
	for (int i = 0; i < LENGTH; i++) {
		printf("%s\n", words[i]);
	}
	/*
	* c: example of a generic pointer
	*/
	gp = data;
	printf("\ndata array address is %p\n", gp);
	// print out th first item in the array
	printf("item points to by gp is %d\n", *(int*)gp);
	//the cast tells the compiler what the address type is
	gp = (int*)gp + 1;
	printf("item pointed to by gp is now %d\n", *(int*)gp); //deference operator (another asterisk)
	printf("------------ part 2: char ------------");
	gp = words; //set generic pointer to the words array start position
	printf("\nwords array address is %p\n", gp);
	//now print out the first item in the array
	//- a cast is now needed to let the compiler know this is a pointer to a pointer of a char
	printf("item pointed to by gp is %s\n", *(char**)gp);
	// the cast tells the compiler what the address type is and so we can add 
	gp = (char**)gp + 1;
	printf("item pointed to by gp is now %s\n", *(char**)gp);
}

char * string_function(char *astring)
{
	char* s;
	s = (char*)malloc(MAXSTRLEN);
	s[0] = 0;		                // need this to initialize the buffer created by malloc
	strcat(s, "Hello ");
	strcat(s, astring);
	strcat(s, "\n");
	return s;
}

void runtime_memory_allocation()
{
	printf(string_function("John"));
	printf(string_function("Gussie Fink-Nottle"));
}
//very simple allocation of memory changing something in the newly allocated
void malloc_and_sizeof()
{
	char* s;
	int stringsize;

	stringsize = sizeof("hello");   //first work out how big the string is
	printf("size of 'hello' is %d\n", stringsize);// note, it is 6
												  //now allocate some memory
	s = (char*)malloc(stringsize);
	if (s == NULL) {
		printf("malloc failed!\n");
		exit(0);
	}
	// now copy the string into the newly allocated memory
	strncpy(s, "hello", stringsize);
	// and change the first character (just to show we can)
	printf("s is %s\n", s);
	s[0] = 'c';
	printf("s is now %s\n", s);
}
// look at calloc and memory leaks
void calloc_example()
{	
	char* s;
	int i;
	int* p;
	//use malloc first to allocate some memory and see what is in it (usually junk)
	s = (char*)malloc(6); //malloc will return NULL(0) if it fails, so we should check here, but we won't for brevity
	for (i = 0; i < 6; i++) 
	{
		printf("s[%d]=%d\n", i, s[i]);
	}

	free(s);	//use 'free' to return the memory so that we don't get the memory leak
	// now we'll use calloc to do the same - note that the memory is zero'd out
	//Note: the syntax of calloc is different for malloc - the second argument gives the size of the memory unit to allocate
	s = (char*)calloc(6, sizeof(char));		// calloc will return 0 if it fails, so we should check here, but we won't for brevity
	for (i = 0; i < 6; i++)
	{		
		printf("s[%d]=%d\n", i, s[i]);
	}
	free(s);

	// in this last example, calloc allocates 6 integers, or 24 bytes, since an integer is 4 bytes long
	p = (int*)calloc(6, sizeof(int));
	for (i = 0; i < 6; i++)
	{
		printf("p[%d] =%d\n", i, p[i]);
	}

}
#define TOTAL 50000
void calloc__big_ex()
{	
	//An example to test the limits of how much memory can be utilized for a single array of pointers in a program. 
	int i = 0;
	char* charArray[TOTAL];
	int count = 0;
	
	while (i < TOTAL)
	{
		char* s;
		s = (char*)calloc(2000, sizeof(char));		// calloc will return 0 if it fails, so we should check here, but we won't for brevity

		free(s);
		charArray[i] = s;
		i++;
	}
	count += TOTAL;
}

//changing the size of memory
void reallocate()
{
	char* s;
	int i;

	i = sizeof("hello");						// as before first work out how big "hello" is ...
	s = (char*)malloc(i);						// malloc will return 0 if it fails, so we should check here, but we wont for brevity
	strncpy(s, "hello", i);						// now copy the string into the newly allocated memory
	printf("s is %s\n", s);

	// now suppose we want to add 'world' to 'hello' - we can't just do this ...
	// strcat(s, " world");					- disaster!!! 
	realloc(s, 12);
	//s = (char*)realloc(s, 12);					// but we can use 'realloc' which frees the original 6 bytes of memory and allocates an new 12 bytes
	strncpy(s, "hello", i);						// now copy the string into the newly re-allocated memory
	strcat(s, " world");						// now we can tag on the 'world'
	printf("s is now %s\n", s);


	free(s);									// and when we've finished we should always free up any memory by using 'free'
												// NOTE: make a habit of using 'free' whan you've finished with some memory otherwise there will be 'memory leaks'
												// where memory that you have allocated will be 'lost' to your program
												// these are not as important as they used to be (a few bytes in several GB won't make much of a difference) but it is considered to be good programming practise to tidy up

}

int main(int argc, char** argv)
{
	reallocate();
	//calloc__big_ex();
	//calloc_example();
	//malloc_and_sizeof();
	//runtime_memory_allocation();
	//generic_pointers();
	//main_test(argc, argv);
	//multiple_indirection_chars();
	//multiple_indirection();
	//address_sandbox();
	//display_pointer_value();
	//strings();
	//pointerExample();
	return (0);
}