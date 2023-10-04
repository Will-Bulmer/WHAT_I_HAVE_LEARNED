/*---------------------------  2.12 Precedence and Order of Evaluation  -----------------------------------------*/

/*
================================================================
            OPERATORS                           ASSOCIATIVITY
            () [] -> ,                          left to right 
        ! ~ ++ -- + - * & (type) sizeof         right to left
              * / %                             left to right
             +   -                              left to right
             <<  >>                             left to right
            < <= > >=                           left to right
             ==  !=                             left to right
                &                               left to right
                ^                               left to right
                |                               left to right
                &&                              left to right
                ||                              left to right
                ?:                              right to left
    = += -= *= /= %= &= ^= |= <<= >>=           right to left
                ,                               left to right
---------------------------------------------------------------
*/