/*---------------------------  5.3 Pointers and Arrays -----------------------------------------*/

/*

- Any operation that can be done with ARRAY SUBSCRIPTING can also be done with POINTERS - FASTER.
*/

int a[10];     // Block of 10 consecutive objects
int *pa;       // Pointer to an integer
pa = &a[0];    // Sets pa to point to element zero of a.
               // pa contains the address of a[10]
               // pa + 1 will point to the next element

x = *pa;       // Copy the contents of a[0] into x

/*
if pa = &a[0];    // Thus after assignment, value of pa and a have indentical values.
                  // Can also be written pa = a; since the name of an array is a synonym for the location of the initial element
then 
pa+1 = a[1]
pa+2 = a[2]
pa+3 = a[3]
etc..


- a[i] == *(a+i)    // Evaluating a[i], C converts it to a pointer almost immediately
- pa[i] == *(pa+i)  // If pa is a pointer, this works too
                    // pa = a LEGAL
                    // pa++   LEGAL
                    // a=pa   ILLEGAL
                    // a++    ILLEGAL
*/