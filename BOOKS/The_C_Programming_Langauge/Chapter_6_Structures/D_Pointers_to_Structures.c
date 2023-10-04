/*---------------------------  6.4 Pointers to Structures -----------------------------------------*/

/*
Rewrite the keyword-counting program with pointers instead of array indices
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100

int getword(car *, int);
struct key *binsearch(char *, struct key *, int);  // Returns a pointer to a struct key instead of an integer.

/* count C leywords; pointer version */
main()
{
    char word[MAXWORD];
    struct key *p;

    while (getword(word, MAXWORD) != EOF){
        if (isalpha(word[0])){
            if ((p=binsearch(word, keytab, NKEYS)) != NULL){
                p->count++;
            }
        }
    }
    for (p = keytab; p < keytab + NKEYS; p++){  // Elements of keytab are now accessed by pointers
    // If p is a pointer to a structure, arithmetic on p takes into account the size of the structure.
    // Structure size != (may NOT) sum of the sizes of its members 
    // Alignement requirements for different objects create unnamed "holes" in a structure
    /* Ie, struct {    // May requires 8 Bytes. Sizeof returns the proper value.
            char c;    // Byte
            int i;     // 4 Bytes
           }
    */

        if (p->count > 0){
            printf("%4d %s\n", p->count, p->word);
        }
    }
    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
struct key *binsearch(char *word, struct key *tab, int n) // Returns a pointer to a struct key instead of an integer.
{
    int cond;
    struct key *low = &tab[0];  // Initializers now pointer to beginning of table
    struct key *high = &tab[n]; // Initializer now pointer to end of the table
    struct key *mid;

    while (low < high) {
        mid = low + (high-low) / 2;  // ADDITION of pointers is ILLEGAL. SUBTRACTION is LEGAL.
        if ((cond = strcmp(word, mid -> word) < 0)){  // If it find the word, it returns a pointer
            high = mid;
        }
        else if (cond > 0){
            low = mid + 1;
        }
        else {
            return mid;
        }
    }
    return NULL;  // Failure returns NULL
}

/*
- Sometimes hard to see a function name in a long definition. An alternate style is sometimes used...

struct key *binsearch(char *word, struct key *tab, int n)

struct key *
binsearch(char *word, struct key *tab, int n)

*/
