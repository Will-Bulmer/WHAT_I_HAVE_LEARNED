/*---------------------------  1.5 Character Input and Output  -----------------------------------------*/

/* text stream - A sequence of characters divided into lines:
                 each line consists of zero or more characters
                 followed by a newline character*/

#include <stdio.h>

/* while (character is not end-of-file indicator)
          ouput the character just read
          read a character*/ // Bracket enclosure not needed. Will evaluate next statement only


/* copy input to output; 1st version */
main()
{

    // EOF is an integer defined in <stdio.h>
    int c;

    c = getchar();
    while (c != EOF){
        putchar(c);
        c = getchar();
    }
}

/* copy input to output; 2nd version*/
main()
{
    int c;

    while ((c = getchar() != EOF)){ // Centralises the input. Now only one reference to getchar.
                                    // Parenthesis IMPORTANT. != gets precedence over = 
        putchar(c);
    }
}

/* count characters in input; 1st version*/
main()
{
    long nc; // At least 32 bits

    nc = 0;
    while (getchar() != EOF)
        ++nc; // ++ operator : increment by 1
              // -- operator : decrement by 1
              // suffix ++nc : prefix nc++
        printf("%1d\n", nc); // %1d : long integer
}


/* count characters in input; 2nd version*/
main()
{
    double nc;
    printf("Hello World\n");
    for (nc = 0; getchar() != EOF; ++nc){
    }; // Acts as a null statement
    printf("%.0f\n", nc); // Uses %f for both float and double. 
                          // %.0f suppresses printing of the decimal point and the fraction part, which is zero.
}

/* counts lines in input*/
main()
{
    int c, nl;

    nl = 0;
    while ((c = getchar() != EOF)){
        if (c == '\n'){ // Character constant
                        /* Represents an integer value equal to the numerical value of the 
                            character in the machine's character set 
                            - A is a character constant : ASCII character set is 65 
                            - '\n' is a character constant : stands for 10 ASCII
                            - "\n" is a string constant    : contains just one character  */ 
            ++n1;
        };
    };
    printf("%d\n", n1);
}

/* cont lines, words, and characters in input */
#define IN 1      /* inside a word*/
#define OUT 0     /* outside a word */

main()
{
    int c, nl, nw, nc, state;

    state = OUT;  // Records whether in a word or not. IN = 1, OUT = 0
    nl = nw = nc = 0;
    while ((c = getchar() != EOF)){
        ++nc;
        if (c == '\n'){
            ++n1;
        };
        if (c == ' ' || c == '\n' || c == '\t'){  // || OR, && AND (precedence higher than OR)
            state = OUT;
        };
        else if (state == OUT){
            state = IN;
            ++nw;
        };
    }
    printf("%d %d %d\n", n1, nw, nc);
}