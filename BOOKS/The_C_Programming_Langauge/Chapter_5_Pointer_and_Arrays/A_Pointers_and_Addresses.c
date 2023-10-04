/*---------------------------  5.1 Pointers and Addresses -----------------------------------------*/


/*
- POINTER contains the address of a variable.

EXAMPLE

If c is a char and p is a pointer that points to it, 

                   p:      --->           c:
_____________________________________________________
      ...        |||||       ...       ||||||||
_____________________________________________________

p = &c;     // Assigns the address of c to the variable p... p 'points to' c
            // Only applies to objects in memory : VARIABLES and ARRAY elements.
               CANNOT be applied to EXPRESSIONS , CONSTANTS, or REGISTER variables 
*/

int x = 1, y = 2, z[10];
int *ip;                     /* ip is a pointer to int */

ip = &x;                      /* ip now points to x */
y = *ip;                      /* y is now 1 */
*ip = 0;                      /* x is now 0 */
ip = &z[0];                   /* ip now points to z[0] */

/*
NOTE:    *ip++  WRONG: Increments ip
        (*ip)++ RIGHT: Increments where ip points to
*/