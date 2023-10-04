/*---------------------------  2.9 Bitwise Operators  -----------------------------------------*/

/*
These are the six operators for bit manipulation...
Can only be appled to integral operands: CHAR, SHORT, INT, LONG, whether signed or unsigned

&           : bitwise AND
|           : bitwise inclusive OR
^           : bitwise exclusive OR. Sets a 1 in each bit position where operands have different bits, zero when they are the same
<<          : left shift
>>          : right shift
~           : one's complement (unary)



x = x | SET_ON;    Used to turn bits on. Sets to one in x the bits that are set to one in SET_ON
n = n & 0177;      Used to mask off some bits. Sets to zero all but low-order 7 bits of n.

-------       DISTINGUISH BETWEEN LOGIVAL OPERATORS      -------
If x is 1, y is 2:
    x & y = 0
    x && y = 1

<< shifts bit:
    x << 2 shifts value of x left by two positions. Equivalent to multiplying by 4.

~ sets 1's to 0's and vice versa:
    x = x & ~077        : Sets the last six bits of x to zero.

*/