/*---------------------------  1.6 Arrays  -----------------------------------------*/

/* Write a program to count the number of occurrences of each digit, of white space
   characters (blank, tab, newline), and all other characters*/

#include <stdio.h>
/* counts digits, white space, others*/
main()
{
    int c, i, nwhite, nother;
    int ndigit[10]; // An array of 10 integers
                    // Subscripts always start from 0

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i){
        ndigit[i] = 0;
    };
    while ((c = getchar()) != EOF){
        if (c >= '0' && c <= '9'){  // Determines whether the character in c is a digit
                                    // If it is, the numeric value of that digit is c - '0'
            ++ndigit[c-'0'];
        }
        else if (c == ' ' || c == '\n' || c == '\t'){
            ++nwhite;
        }
        else{
            ++nother;
        }
    }
    printf("digits =");
    for (i = 0; i < 10; ++i){
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n", nwhite, nother);
}