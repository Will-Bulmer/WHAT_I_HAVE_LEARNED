/*---------------------------  6.9 Bit-fields -----------------------------------------*/

/*

Used for saving storage.

QUESTION
What is the best way to store the information in a program, ie. KEYWORD, static or external.. etc.

ANSWER
Encode the information in a set of ONE-BIT FLAGS in a single char or int

*/

enum { KEYWORD = 01, EXTERNAL = 02, STATIC = 04}; //Numbers POWERS of 2
// Accessing bits becomes a matter of 'bit-fiddling'
// BIT-FIELD - Adjacent bits within a single implementation-defined storage unit that we will call a "word"

//Can be replaced by...

struct {
    unsigned int is_keyword : 1; // Three 1-bit fields
    unsigned int is_extern : 1; // 1 = field-width in bits
    unsigned int is_static : 1;
} flags;    // Variable called flags