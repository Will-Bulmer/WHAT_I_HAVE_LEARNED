/*---------------------------  7.7 Line Input and Output -----------------------------------------*/

/*

Standard library provides an input routine FGETS that is similar to GETLINE function

*/


/* FGETS reads the next input line (including the newline) from file fp into the character array LINE. 
    At most, MAXLINE - 1 characters will be read  */
char *fgets(char *line, int maxline, FILE *fp); // 