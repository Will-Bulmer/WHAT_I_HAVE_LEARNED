/*---------------------------  5.12 Complicated Declarations -----------------------------------------*/

/*

dcl converts a C declaration into a word description

*/

int *f();     /* f: function returning pointer to int */

int (*pf)();  /* pf: pointer to function returning int
                    * is a prefix operator with lower precedence so need the brackets */

