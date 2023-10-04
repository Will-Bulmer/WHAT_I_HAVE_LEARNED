/*---------------------------  6.1 Basics of Structures -----------------------------------------*/

/*
- A STRUCTURE is a collection of one or more variables, possibly different types, grouped together under a different name.
- Help organise large data in large programs as they permit for them to be treated as a unit instead of separate entities.

- Ie Employee has attributes. Name, address, social security number etc.
    Name could have several components which could be stored in a structure.

- Ie Graphics.
    Point is a pair of coordinates.
*/

struct point {  // Describes a template of shape of the structure. Does not reserve storage.
    // Members
    // Can have same variable name as an ordinary variable. Distinguished by context.
    int x;
    int y;
};

/*
struct { ... } x, y, z;     ==  int x, y, z;
*/

/* Tagged STRUCTURE declaration */
struct point pt; // Defines a variable which is a structure of type struct point
struct point maxpt = { 320, 200};  // Initialised with constant expressions.
structure-name.member // Calling a member


// Can have nested structures
struct rect screen{
    struct point pt1;
    struct point pt2;
};