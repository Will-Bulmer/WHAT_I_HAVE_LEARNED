/*---------------------------  5.11 Pointer to Functions -----------------------------------------*/

/*

Modify the earlier sorting algorithm so that it will sort the input lines numerically instead of lexicographically (strcmp).

*/

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000     /* max #lines to be sorted */
char *lineptr(MAXLINES);  /* pointer to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort( void *lineptr[], int left, int right, int (*comp)( void *, void *));
// qsort expects an array of pointers, two integers, anda  function with two pointer arguments
// Can call qsort by CASTING arguments to void * and back again with loss of information.
int numcmp(char *, char *);

/* sort input lines */
main(int argc, char*argv[])
{
    int nlines;             /* number of input lines read */
    int numeric = 0;        /* 1 if numeric sort */

    if (argc > 1 && strcmp(argv[1], "-n") == 0){
        numeric = 1;
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0 ){
        qsort((void **) lineptr, 0 , nlines - 1 , (int (*)(void*, void*))(numeric ? numcmp : strcmp)); 
        // lineptr and strcmp are known to be addresses to functions and so we do not need &
        writelines(lineptr, nlines);
        return 0;
    }
    else{
        printf("input too big to sort\n");
        return 1;
    }
}

// Rest of code omitted.
// Info about declaring to void. Can be converted to any type pointer via CASTING.