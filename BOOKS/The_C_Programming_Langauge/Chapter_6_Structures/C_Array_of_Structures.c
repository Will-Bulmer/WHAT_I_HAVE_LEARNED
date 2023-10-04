/*---------------------------  6.3 - Arrays of Structures -----------------------------------------*/

/*
Writing a program to count the occurences of each C keyword. Need an ARRAY of character strings to hold names, and
an ARRAY of integers for the counts.
*/

/* One possibility : two parallel arrays*/
char *keyword[NKEYS];
int keycount[NKEYS];

char *word;
int count;

struct key {  // Structure of type key
    char *word;
    int count;
} keytab[NKEYS];   // Defines an array keytab of structures. Sets aside storage for them.