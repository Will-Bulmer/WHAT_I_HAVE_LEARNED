/*---------------------------  7.1 Standard Input and Output -----------------------------------------*/

/*



*/
#include <stdio.h> /* Must include if refers to input/ output library function */
#include <ctype.h>

/*
int getchar(void); // Simplest input. Read one character at a time from the STANDARD INPUT
int putchar(int);  // Used for output. Puts character int on the STANDARD OUTPUT (screen)
*/

int main() /* lower: convert input to lower case*/
{
    int c;
    //fflush(stdout);  // Actually write the output to standard output
    while ((c = getchar()) != EOF){
        putchar(tolower(c));
    }
    return 0;
}