/*---------------------------  4.11 The C Preprocessor -----------------------------------------*/

/*

- Two most common are #include and #define

---------        FILE INCLUSION        --------

#include "filename"  // File search begins where the source program was found. 
#include <filename>  // File search follows an implementation-defined rule to find the file.

- replaces with the contents of the file.

--------        MACRO SUBSTITUION        --------

#define     name     replacement text
#define    forever   for (;;)            // Defines 'forever' for an infinite loop

#define   sqaure(x)    x * x            // WRONG

--------        CONDITIONAL INCLUSION        --------

#if !defined(HDR)
#define HDR
// Contents of hdr.h go here

#endif

*/