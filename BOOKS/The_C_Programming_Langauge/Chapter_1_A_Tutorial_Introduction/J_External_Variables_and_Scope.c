/*---------------------------  1.10 External Variables and Scope  -----------------------------------------*/

/* automatic variables : Variables in the scope of a function that only come into existence when the function is called 
                         If values are not set upon entry, they will contain garbage 
                         
    global variables   : Exist externally and can be used to communicate information between functions. 
                         Must be declared in a function that wants access to it
                         */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int max;                  /* maximum length seen so far */
char line[MAXLINE];       /* current input line */
char longest[MAXLINE];    /* longest line saved here */

int getlines(void); // Declaration
void copy(void);

/* print longest input line; specialized version */
/* main program that controls getline and copy.*/
main()
{
    int len;                  /* current line length */
    extern int max;           // No need for extern if the declaration in the source file is before its use
                              // If variable defined in file1, used in file2 and file3 - need extern
                              // Usual practice is to collect externs in a folder called header
    extern char longest[];

    max = 0;
    while ((len = getlines()) > 0){
        if (len > max){
            max = len;
            copy();
        }
    }
    if (max > 0){             /* There was a line */
        printf("%s", longest);
    }
    return 0;
}

/* getline : read a line into s, return length ; specialised version */
int getlines(void) // Definition
{ // int is the default datatype and could be omitted.
    int c, i;
    extern char line[];

    // Getline checks for overflow. No way of knowing what the max value will be.
    for (i=0 ; i<MAXLINE-1 
        && (c=getchar()) != EOF && c!='\n'; ++i){  
        line[i] = c;
    }
    if ( c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';  // Places a null character at the end of the array to mark the end of the string of characters.
                  // Is used in C language. String constant like "hello\n" is stored, it is stored with a null character as well.
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough; specialized version */
/* Used when we find out a line is longer than the previous longest. Must save it somewhere. */

void copy(void) // Void returns no value 
{
    int i;
    extern char line[], longest[];

    i = 0;
    while((longest[i] = line[i]) != '0'){
        ++i;
    }
    // Does not return anything. Only used for it's affect.
}