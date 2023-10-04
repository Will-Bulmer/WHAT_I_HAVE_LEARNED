/*---------------------------  1.9 Character Arrays  -----------------------------------------*/

/* Write a program that reads a set of text lines and prints the longest:
    while (there's another line){
        if (its longer than the previous longest){
            save it
            save it's length
        }
    }
    print longest line*/

/* NOTE: getline is a standard library in stdio.h - must rename to getlienes*/
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getlines(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
/* main program that controls getline and copy.*/
main()
{
    int len;                  /* current line length */
    int max;                  /* maximum length seen so far */
    char line[MAXLINE];       /* current input line */
    char longest[MAXLINE];    /* longest line saved here */

    max = 0;
    while ((len = getlines(line, MAXLINE)) > 0){
        if (len > max){
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0){             /* There was a line */
        printf("%s", longest);
    }
    return 0;
}

/* getline : read a line into s, return length */
int getlines(char s[], int lim)
{ // int is the default datatype and could be omitted.
    int c, i;

    // Getline checks for overflow. No way of knowing what the max value will be.
    for (i=0 ; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i){  
        s[i] = c;
    }
    if ( c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';  // Places a null character at the end of the array to mark the end of the string of characters.
                  // Is used in C language. String constant like "hello\n" is stored, it is stored with a null character as well.
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
/* Used when we find out a line is longer than the previous longest. Must save it somewhere. */

void copy(char to[], char from[]) // Void returns no value 
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '0'){
        ++i;
    }
    // Does not return anything. Only used for it's affect.
}