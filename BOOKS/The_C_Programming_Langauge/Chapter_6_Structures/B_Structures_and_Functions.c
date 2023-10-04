/*---------------------------  6.2 Structures and Functions -----------------------------------------*/

/*
- Only LEGAL operations on a structure are COPYING it, ASSIGNING to it as a unit, taking its ADDRESS with &
    and ACCESSING it's members
- COMPARING is ILLEGAL
*/

/*
Investigate structures by writing some functions to manipulate points and rectangles. Three possible approaches:
1. Pass components separately
2. Pass an entire structure
3. Pass a pointer to a structure
*/

/* makepoint: make a point from x and y components */
// Can now be used to make any point dynamically or provide structure arguments to a function.
struct point makepoint(int x, int y)
{
    struct point temp;
    
    temp.x = x;
    temp.y = y;
    return temp;
}

struct rect screen;
struct point middle;
struct point makepoint(int, int);

screen.pt1 = makepoint(0, 0);
screen.pt2 = makepoint(XMAX, YMAX);
middle = makepoint((screen.pt1.x + screen.pt2.x) / 2, (screen.pt1.y + screen.pt2.y) / 2)

/* addpoint: add two points */
struct point addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;  // Passed by value so can do this.
    p1.y += p2.y;
    return p1;
}

/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x
        && p.y >= r.pt1.y && p.y < r.pt2.y;
}

/* It is generally better to pass a pointer to a structure than pass a large structure as an argument */
struct point *pp; // pp is a pointer to a structure of type struct point
                  // If pp points to a structure, then *pp is the structure, (*pp).x and (*pp).y are its members.
p -> member-of-structure  // Is the same notation. High precedence.

struct {
    int len;
    char *str;
} *p ;

/* then 
++p -> len //Increments len, NOT p since ++(p -> len)
*/
