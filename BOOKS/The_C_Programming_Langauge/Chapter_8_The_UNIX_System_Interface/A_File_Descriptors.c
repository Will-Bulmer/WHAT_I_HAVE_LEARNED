/*---------------------------  8.1 Files Descriptors -----------------------------------------*/

/*

The UNIX opreating system provides its services through a set of system calls, which are in effect functions within the 
operating system that may be called by user program.

- All input and output is done by reading or writing files. Single homogenous interface handles all 
    communication between a program and peripheral devices.
- Must inform system of intent to READ or WRITE by OPENING the file. System check your RIGHT to do so.
   If all is well, returns to the program a small non-negative integer called a FILE DESCRIPTOR.
   This is used instead of the file name. Analogous to FILE POINTER.

*/