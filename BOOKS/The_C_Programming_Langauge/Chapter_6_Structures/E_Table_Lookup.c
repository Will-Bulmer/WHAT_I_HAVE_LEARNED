/*---------------------------  6.6 Table Lookup -----------------------------------------*/

/*
Will write the innards of a table-loopup package.
*/

#define IN 1  /* name IN and replacement text 1 are stored in a table.
                    install(s,t), records name s and the replacement text t in a table
                    lookup(s) searches for s in the table, and returns a pointer to the place where it was found, NULL
                    HASH search - Name converted to small non-negative integer - used to index an array of pointers
                                - An array elements points to the beginning of a linked list of blocks with name that have hash value*/

/* Pointer array*/
#define HASHZIE 101

static struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* has: form hash value for string s */
/* Used by both LOOKUP and INSTALL : Adds each character value to a string to a scrambled combination of the previous ones
                                      and returns the remainder modulo the array size
                                        */
unsigned hash(char *s)
{
    unsigned hasval;  // Ensures non-negative hash value

    for (hashval = 0; *s != '\0'; s++){
        hasval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE
}