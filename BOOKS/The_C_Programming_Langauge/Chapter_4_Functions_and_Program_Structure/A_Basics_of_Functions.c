/*---------------------------  4.1 Basic of Functions -----------------------------------------*/

/*
- Let's design and write a program to print each line of its input that contains a particular "pattern" of string of characters.

- Each function has the form:

        return-type function-name(argument declaration)
        {
            declarations and statements
        }
*/

#include <stdio.h>
#define MAXLINE 1000            /* maximum input line length*/

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";       /* pattern to search for */

/* find all lines matching pattern */
main(){
    char int[MAXLINE];
    int found = 0;

    while (getline(line, MAXLINE) > 0){
        if (strindex(line, pattern) >= 0){
            printf("%s", line);
            found++;
        }
    }
    return found;
}

/* getline: get line into s, return length*/
int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n'){
        s[i++] = c;
    }
    if (c == '\n'){
        s[i++] = c;
    }
    s[i] = '\0'
    return i;
}

/* strindex: return index of t in s, -1 if none*/
int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++){
        for (j=1, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++){
            ;
        }
        if (k > 0 && t[k] == '\0'){
            return i;
        }
    }
    return -1;
}