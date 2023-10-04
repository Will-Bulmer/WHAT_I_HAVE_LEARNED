/*---------------------------  3.4 Switch  -----------------------------------------*/

/*

switch (expression){
    case const-expr:   statements
    case const-expr:   statements
    default:   statements
}

- Cases and default can occur in any order.
- Does not terminate chain.

*/

#include <stdio.h>

main(){ /* count digits, white space, others */
    int c, i , nwhite, nother, ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; i++){
        ndigit[i] = 0;
    }
    while ((c = getchar()) != EOF){
        switch (c) {
            case '0' : case '1' : case '2' : case '3' : case '4' :
            case '5' : case '6' : case '7' : case '8' : case '9' :
                ndigit[c-'0']++;
                break;  // Causes an immediate exit from the switch

            case ' ':  // Case fall throughs should be commented and used sparingly. Always end with a break.
            case '\n':
            case '\t':
                nwhite++;
                break;
            default:
                nother++;
                break;  // Good practice to put a break after the last case
        }
    }
    printf("digits =");
    for (i = 0; i < 10; i++ ){
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n", nwhite, nother);
    return 0;
}  