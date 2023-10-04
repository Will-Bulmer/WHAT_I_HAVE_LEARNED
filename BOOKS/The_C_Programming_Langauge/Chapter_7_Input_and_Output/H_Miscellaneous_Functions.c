/*---------------------------  7.8 Miscellaneous Functions -----------------------------------------*/
// Included in the standard library...

/* --------        STRING OPERATIONS        -------- */
// <string.h>
strcat(s,t)     // concatenate t to end of s
strncat(s,t,n)  // concatenate n characters of t to end of s
strcmp(s,t)     // return negative, zero, or positive for 
                //    s < t, s == t or s > t
strncmp(s,tn)   // same as strcmp but only in first n characters
strcpy(s,t)     // copy t to s
strncpy(s,t,n)  // copy at most n characters of t to s
strlen(s)       // return length of s
strchr(s,c)     // return pointer to first c in s, or NULL if not present
strrchr(s,c)    // return pointer tp last c in s, or NULL if not present

/* --------        CHARACTER CLASS TESTING AND CONVERSION        -------- */
// <ctype.h>
isalpha(c)      // non-zero if c is alphabetic, 0 if not
isupper(c)      // non-zero if c is upper case, 0 if not
islower(c)      // non-zero if c is lower case, 0 if not
isdigit(c)      // non-zero if c is digit, 0 if not
isalnum(c)      // non-zero if isalpha(c) or isdigit(c), 0 if not
isspace(c)      // non-zero if c is blank, tab, newline, return, formfeed, vertical tab
toupper(c)      // return c converted to upper case
tolower(c)      // return c converted to lower case

/* --------        UNGETC        -------- */

int ungetc(int c, FILE *fp);  // Restricted version of ungetch
                              // Pushes the character c back onto file fp, returns either c or EOF

/* --------        COMMAND EXECUTION        -------- */

system(char *s); // Executes the command contained in the character string s, then resumes execution of the current program

/* --------        STORAGE MANAGEMENT        -------- */

// Obtain blocks of memory dynamically.
void *malloc(size_t n); // Returns a pointer to n bytes of uninitialized storage
void *calloc(size_t n, size_t size);  // Returns a pointer to enough space for an array of n objects of the specified size. Init to 0.s
free(p);  // Frees the space pointed to by p, where p was obtained by a malloc or calloc call

/* --------        MATHEMATICAL FUNCTIONS        -------- */
//<math.h>

sin(x)      //
cos(x)
atan2(y,x)  // arctangent of y/x in radians
exp(x)
log(x)
log10(x)
power(x,y)
sqrt(x)
fabs(x)     // absolute value of x

/* --------        RANDOM NUMBER GENERATION        -------- */
//<stdlib.h>
rand()      // Computes a sequence of pseudo-random integers in the range RAND_MAX