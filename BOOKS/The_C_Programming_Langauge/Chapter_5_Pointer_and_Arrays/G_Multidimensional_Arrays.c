/*---------------------------  5.7 Multi-dimensional Arrays -----------------------------------------*/

/*

- Used less than an array of pointers.
- Multi-dimensional arrays are really just 1D arrays.
- Passing a 2D array to a function must include the number of COLUMNS. Number of ROWS is irrelevant.
    Ie. For months with a 0th row, will pass a POINTER to objects that are arrays of 13 ints. All LEGAL:
    f(int daytab[2][13]){...}
    f(int daytab[][13]){...}
    f(int (*daytab)[13]){...}   // Brackets have high precendence than *


- daytab[i][j]   // [row][col]
- daytab[i,j]    // WRONG

*/