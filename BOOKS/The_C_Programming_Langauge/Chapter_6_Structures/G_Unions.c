/*---------------------------  6.8 Unions -----------------------------------------*/

/*

A UNION is a variable that may hold (at different times), objects of DIFFERENT TYPESand SIZES.

- Compiler keeps track of size and alignment requirements
- Manipulate different kinds of data in a single area of storage, without embedding any machine-dependent information in the program

*/

union u_tag { /* Large enough to hold the largest of the 3 types */
    int ival;
    float fval;
    char *sval;
} u;


// Retrieval syntax
union-name.member
union-pointer->member

// Union is a struct in which all members have OFFSET ZERO from the base. Struct holds the WIDEST member.

// NOTE: Can only be initialised with a value of the type of its FIRST MEMBER (ie. int here)