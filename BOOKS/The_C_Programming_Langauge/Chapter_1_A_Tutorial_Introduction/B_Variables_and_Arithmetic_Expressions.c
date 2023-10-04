/*---------------------------  1.2 Variables and Arithmetic Expressions  -----------------------------------------*/

#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300 */

main()
{
    float fahr, celsius;      // Declaration data-type. Float mag e-38 -> e+38.
                           // Char : single byte
                           // short : short integer
                           // long : long integer
                           // double : double precision floating point
    int lower, upper, step;

    lower = 0;              /* lower limit of temperature table*/
    upper = 300;            /* upper limit*/
    step = 20;              /* step size*/

    fahr = lower;
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);  // Integer division truncates. 5/9 both integers and would be truncated to zero.
        //printf("%d\t%d", fahr, celsius); // %d specifies an integer argument.
                                         // printf not apart of the C language. Belongs to the standard library.
                                         // scanf is the same except it reads instead of write
        printf("%3.0f %6.1f\n", fahr, celsius); // Right-justified numbers. %3d - 3 digits wide, %6d - 6 digits wide.
                                                // %3.0f - 3 digits, no decimal, %6.1f - 6 digits, 1 decimal place
                                                // Printf recognises %o for octal, %x for hexadecimal, %c for character, %s for character string
                                                // %% for % itself
        fahr = fahr + step;
    }
}