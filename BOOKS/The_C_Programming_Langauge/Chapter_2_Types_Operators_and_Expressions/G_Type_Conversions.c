/*---------------------------  2.7 Type Conversions  -----------------------------------------*/

/*
- Values to the RIGHT are converted to values to the LEFT

- Operands of different types will convert then into a common type according to a small set of rules
- Automatic conversions are "narrow" operator into "wider" without losing information:
        int -> float
        float -> double

- Legal but draw warnings:
        float -> int
        long -> short

- Conversion of non-character data to char variables, must specify signed or unsigned as different machine produce
  different converisons

- A BINARY operator will promote the LOWER operator to the HIGHER operator

    1. If either operand is LONG DOUBLE, convert the other to LONG DOUBLE
    2. Otherwise, if either operand is DOUBLE, convert the other to DOUBLE
    3. Otherwise, if either operand is FLOAT, convert the other to FLOAT
    4. Otherwise, convert CHAR and SHORT to INT
    5. Then, if either operand is LONG, convert the other to LONG

- In general, mathematical functions use DOUBLE precisions. Main reason for float is to save time or save storage

- Sqrt requires a DOUBLE and so we use CAST

    sqrt((double), n)
    root2 = sqrt(2)         coerces the INTEGER 2 into the DOUBLE value 2.0 without a need for CAST.
*/