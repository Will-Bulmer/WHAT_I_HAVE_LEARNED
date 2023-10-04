/*---------------------------  5.2 Pointers and Function Arguments -----------------------------------------*/

/*
- swap(a, b) will only swap copies of a and b
- swap(&a, &b) will swap the originals of a and b:
                operands access indirectly through the points

- Pointer arguments enable a function to access and change objects in the function that called it.
- Pass the address of an array[n] to a function so that it can communicate the changes back to the caller.

*/