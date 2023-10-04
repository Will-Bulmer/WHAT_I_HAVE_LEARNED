/*---------------------------  3.8 Goto and Labels -----------------------------------------*/

/*

- Most common use is to abandon processes in some deeply nested structure : Breaking out of two or more loops at once.
- Break statement cannot be used directly as it only leaves the inner most loops.

for (...){
    for (...){
        ...
        if (disaster){
            goto error;
        }
    }
}
...

error:    // This  is a LABEL
    clean up the mess
*/