/*---------------------------  5.9 Pointers vs. Multi-dimensional Arrays -----------------------------------------*/

/*

*/

int a[10][20];  // 200 int-sized locations have been set aside.
                // 20xrow + col is used to find the element a[row][col]
int *b[10];     // If b points to a 20 element array, then 200 ints set aside, plus 10 cells for the pointers.
                // Pointer array useful if the rows are of different lengths.
                // Ie. character strings of undefined lengths.

/*
Then a[3][4] and b[3][4] are LEGAL references to a single int.
*/