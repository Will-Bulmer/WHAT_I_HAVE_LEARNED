/*---------------------------  6.5 Self-referential Structures -----------------------------------------*/

/*
Writing a program to count the occurences of ALL the words in some input.

- How can we organize the date to cope efficientyl with a list of arbitrary words?
    1. Could keep the words seen so far sorted at all times. Use a data structure called a BINARY TREE
        - The tree contains one "node" per distinct word. Each node contains
            a pointer to the text of the word
            a count of the number of occurences
            a pointer to the left child node
            a pointer to the right child node
*/

struct tnode {  /* the tree node: */
    char *word; /* point to the text */
    int count;  /* number of occurrences */
    struct tnode *left; /* left child */
    struct tnode *right; /* right child */
}

/*
- Word presented by main to the top level
- At each stage, that word is compared to the word stored in the node.
- Percolated down either left or right sub-tree by a recursive call
*/

/* self referential structures: */

struct t {
    ...
    struct s *p; /* p points to an s */
};

struct s {
    ...
    struct t *q; /* q points to a t*/
};

/*
Brief discussion of storage allocaters

QUESTIONS
1. Want to be able to meet alignment requirements (ie, integers stored at even address)
2. Want declaration to be able to cope with th fact that an allocater must necessarily return different kind of pointers

ANSWERS
1. Alignment requirements can be satisifed at the cost of wasted space. Ensure allocater returns a pointer that meets
    ALL alignment requirements. Alloc does NOT require any particular alignment. Malloc does.
    Proper way is that MALLOC returns a pointer to VOID, then explicitly coerce the pointer via a CAST.
*/