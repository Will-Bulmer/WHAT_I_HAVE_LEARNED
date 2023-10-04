/*---------------------------  2.3 Constants  -----------------------------------------*/

/*
long constant           : 123456789L
unsigned constant       : 123456789U
float constant          : 123456789F
0int                    : octal
0x                      : hexidecimal
character constant      : integer written as one character within single quotes, 'x'
\n                      : Newline. Looks like 2 characters but is only 1.

escape sequences        : \a        alert (bell) character
                          \b        backspace
                          \f        formfeed
                          \n        newline
                          \r        carriage return
                          \t        horizontal tab
                          \v        vertical tab
                          \\        backslash
                          \?        question mark
                          \'        single quote
                          \"        double quote
                          \ooo      octal number
                          \xhh      hexadecimal number

- Constants are evaluated at compilation rather than run-time

"hello," "world"  == "hello, world"  : Can split long strings along several lines
        'x'       !=       "x"       : Character constant vs string constant

enumeration constant    : A list of constant integer values
                            ie. enum boolean {NO, YES}
                                enum escapes { BELL = '\a' etc,}
*/

