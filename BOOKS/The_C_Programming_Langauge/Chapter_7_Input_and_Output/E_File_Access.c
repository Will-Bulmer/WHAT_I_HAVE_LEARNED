/*---------------------------  7.5 File Access -----------------------------------------*/

/*

Write a program that accesses a file that is not already connected to the program. Ie. Use of the operation called cat.

- CAT is used for printing files on the screen
*/

cat x.c y.c // Prints the contents of the files x.c and y.c on the standard input.

/*
- Before it can be READ or WRITTEN, a file has to be OPENED by the library function FOPEN
- FOPEN takes external name like x.c or y.c and does some housekeeping and negotiation with the operating system, returns a pointer.
- FILE POINTER points to a structure that contains information about the file; location, buffer, being read, being written
*/

#include <stdio.h>
FILE *fp;       // fp a pointer to FILE
FILE *fopen(char *name, char *mode);

fp = fopen(name, mode); // Calling fopen in a program
                        // MODE : character string how one intends on using the file.

int getc(FILE *fp); // Returns the next character from the stream referred to by fp
int putc(intc, FILE *fp); // Writes the character c to the file fp and returns the character written.

/*
When a file is started the operating system environment is responsible for opening three files and providing pointers for them
    standard input : stdin
    standard output : stout
    standard error : stderr
These are declared in <stdio.h>
*/