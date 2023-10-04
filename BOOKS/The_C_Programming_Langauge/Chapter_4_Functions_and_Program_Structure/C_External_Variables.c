/*---------------------------  4.3 External Variables -----------------------------------------*/

/*

- C does not allow functions to be defined inside of other functions. 
- External variables are globally accessible. 
- Greater scope and liftime than automatic variables.

- stack and stack index that are shared by PUSH and POP are examples.
*/

/*
- If two functions must share some data, yet neither calls the other, keep shared data external rather 
    than passed in and out via arguments.
*/