/*---------------------------  2.11 Conditional Expressions  -----------------------------------------*/

/*
*/

int a, b, z, n;
if (a > b){
    z = a;
}
else{
    z = b;
}

/* can be written as ...

expr1 ? expr2 : expr3    // Ternary operator ?
                        //  expr1 evaluated first
                        //  If true (non-zero), then expr2 evaluated and expr1 = expr2
                        //  if false (zero), then expr3 evaluated and expr1 = expr3

*/

z = (a > b) ? a : b  /* z = max(a , b) */

/* result type depends on conversion rules */

(n > 0) ? f : n  /* Result will be a float regardless of whether n is positive 
                    Precedence of ? is LOW, so parentheses are not necessary */