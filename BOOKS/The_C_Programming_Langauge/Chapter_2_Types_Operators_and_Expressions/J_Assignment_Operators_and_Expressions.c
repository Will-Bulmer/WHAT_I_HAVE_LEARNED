/*---------------------------  2.10 Assignment Operators and Expressions  -----------------------------------------*/

/*

---------     ASSIGNMENT OPERATOR    --------
op= where op is:
        +  -  *  /  %  <<  >>  &  ^  |


i = i + 2     -->      i += 2

- i is now only computed only once
*/

/* bitcount: count 1 bits in x*/
int bitcount(unsigned x)   /*  Unsigned means that when it is right-shfited, vacated bits will be filled with zeros
                                not sign bits, regardless of the machine that the program is run on */ 
                           
{
    int b;

    for (b =0; x != 0; x >>= 1){
        if (x & 01){
            b++;
        }
    }
    return b;
}