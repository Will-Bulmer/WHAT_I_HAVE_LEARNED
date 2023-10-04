/*---------------------------  4.2 Functions Returning non-integers -----------------------------------------*/

/*

- If atof itself and the call in the main function (same source file) have inconsistent types,
   the error would be detected by the compiler

HOWEVER

- If they are in separate files, then the error will not be detected.
- Can also get mismatches if there is no function PROTOTPYE.. Implicit declaration:

    sum += atof(line)

*/