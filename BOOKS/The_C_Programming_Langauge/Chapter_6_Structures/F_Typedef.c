/*---------------------------  6.7 Typedef -----------------------------------------*/

/*

Similar to DEFINE although can cope with textual substitutions that are beyond the capabilities of the preprocessor

Main usage:
    - Parametrise a program against portability problems
    - Better documentation. A type called Treeptr is easier to understand than one declared only as a pointer to a complicated structure.

*/

typedef int Length;  // Makes the name Length a SYNONYM for int
                     // Syntactically, typedef is like the storage classes extern, static etc
                     // Capitalized names for typedef

Length len, maxlen;
Length *lengths[];