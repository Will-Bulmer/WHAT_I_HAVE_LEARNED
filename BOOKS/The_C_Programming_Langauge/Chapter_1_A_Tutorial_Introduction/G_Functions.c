/*---------------------------  1.7 Functions  -----------------------------------------*/

/* A function defintion has this for: 
    
    return type function-name(parameter declarations, if any)
    {
        declarations
        statements
    }
*/



#include <stdio.h>

int power(int m, int n);  // Function prototype. Parameter names need not agree, but everything else must.

/* test power function*/
main()
{
    int i;
    
    for (i = 0; i < 10; ++i){
        printf("%d %d %d\n", i, power(2,i), power(-3,i)); // Function called twice.
    }
    return 0; // Describes normal termination.
              // Non-zero describe unusual or erroneous termination conditions.
}

/* power: raise base to n-th power; n >= 0 */
int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i){
        p = p * base;
    }
    return p;
}