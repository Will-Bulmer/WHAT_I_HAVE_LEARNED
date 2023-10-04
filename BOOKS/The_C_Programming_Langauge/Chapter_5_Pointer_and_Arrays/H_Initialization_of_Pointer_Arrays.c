/*---------------------------  5.8 Initialization of Pointer Arrays  -----------------------------------------*/

/*
Consider writing a function month_name(n), which returns a pointer to a character string containing the name of the n-th month.

- Use an INTERNAL STATIC ARRAY
*/

/* month_name: return name of n-th month */
char *month_name(int n)
{
    static char *name[] = {  // Array of character pointers.
                             // Character to i-th string is placedd somewhere, a ponter to them is stored in name[i]
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };
    return (n < 1 || n > 12) ? name[0] : name[n];
}