/*---------------------------  1.8 Arguments - Call by Value  -----------------------------------------*/

/* function arguments are pass 'by value*:  They are given the values of its arugments in temporary variables.
                                            NOT call by reference
                                            Function cannot directly lter a variable in the calling function
                                            Can only alter its private, temporary copy 
                                            
                                            Can edit the original copy if you pass an address 'pointer' 
                                            Function must declare the parameter to be a pointer
                                            
    Arrays as arguments                   : Value passed to the function is the array pointer. 
                                            No copying of array elements */

/* power: raise base to n-th power; n>=0; version 2 */
#include <stdio.h>

int power(int m, int n);  // Function prototype. Parameter names need not agree, but everything else must.

main()
{
    int i;
    
    for (i = 0; i < 10; ++i){
        printf("%d %d %d\n", i, power(2,i), power(-3,i)); // Function called twice.
    }
    return 0; // Describes normal termination.
              // Non-zero describe unusual or erroneous termination conditions.
}
int power(int base, int n) // Parameter n used as a temporary variable
{
    int p;

    for (p = 1; n > 0; --n) // No longer need for a variable i
    {
        p = p * base;
    }
    return p;
}