/*---------------------------  5.5 Character Pointers and Functions -----------------------------------------*/

/*

- A string constant is accessed by a pointer to its first element.

char *pmessage;

pmessage = "now is the time"       // Assigns a pointer to the character ARRAY

char amessage[] = "now is the time";    // An array. 
                                        // Individual characters can change but the array will always refer to the same storage.
char *pmessage = "now is the time";     // A pointer
                                        // Dynamic Data

*/


/* Would be nice to do t = s BUT this copies the pointer, NOT the characters*/
/* strcpy: copy t to s; array subscript version*/
void strcpy(char *s, char *t){
    int i;

    i = 0;
    while((s[i] = t[i]) != '\0'){
        i++;
    }
}

/* strcpy: copy t to s; pointer version 1*/
void strcpy(char*s, char *t){
    while((*s = *t) != '\0'){
        s++;
        t++;
    }
}

/* strcpy: copy t to s; pointer version 2 */
void strcpy(char *s, char *t){
    while((*s++ = *t++) != '\0'){ // Only incremented AFTER the character is fetched.
        ;
    }
}


/*
*p++ = val;    // PUSH val onto stack
val == *--p;   // POP top of stack into val

*/