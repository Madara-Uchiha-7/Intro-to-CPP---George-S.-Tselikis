/*
1 byte = 8 bits.
-----------------------------------------------------------------------------------------------------

What is Less significant byte :->
In particular, the leftmost (first) byte is the most significant byte 
(containing the most significant eight bits of the corresponding bit string) 
and 
the rightmost (last) byte is the least significant byte 
(containing the least significant eight bits of the corresponding bit string).
-----------------------------------------------------------------------------------------------------

When a variable is declared, the compiler reserves the required consecutive bytes to store its value. 
If a variable occupies more than one byte, the variables address is the address of the first byte. 
For example, with the declaration int a = 10; 
the compiler reserves four consecutive unused bytes (e.g., the addresses 5000 - 5003) 
and stores the value 10 there, assuming that the less significant byte of the value is stored 
in the lower address byte (little-endian architecture). 
The compiler associates the name of a variable with its memory address. 
When the variable is used in the program, the compiler accesses its address. 
For example, with the statement a = 3; 
the compiler knows that the memory address of a is 5000 and sets its content to 3.
-----------------------------------------------------------------------------------------------------


*/