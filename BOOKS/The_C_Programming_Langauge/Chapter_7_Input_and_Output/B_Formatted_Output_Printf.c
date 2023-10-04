/*---------------------------  7.2 Formatted Output - Printf -----------------------------------------*/

/* PRINTF : Translates internal values to characters */

//int printf(char *format, arg1, arg2, ...)

/*
- Formate contains two types of objects :
    - Ordinary characters, copied to output stream
    - Conversion specifications, %...%, with .. being : 
         - A minus sign, which specifies left adjustment of the converted argument.
         - Number specifying the minimum field width. May be padded for adjustments.
         - Period which separates the field width from the precision.
         - Precision, specifies the maximum number of characters to be printed from a string.. No. decimal points of float etc
*/


/*
============================================================
    CHARACTER               ARGUMENT TYPE; PRINTED AS
     d, i               int; decimal number
     o                  int; unsigned octal number (without leading zero)
     x, X               int; unsigned hex (without leading 0x or 0X)
     u                  int; unsignmed decimal
     c                  int; single character
     s                  char *; print characters from string until a '\0'
                                or number of characters given by precision
     f                  double; [-]m.dddddd where d's given by precisions (default 6)
     e, E               double; [-]m.dddddd+-xx
     g, G               double; use %e or %E is exponent is less than -4 or
                                greater than or equal to precision. Otherwise use
                                &f. Trailing zero and dec. point not printed
     p                  void *; pointer
     %                  No argument is converted; print a %
---------------------------------------------------------------

*/