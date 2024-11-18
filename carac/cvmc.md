
# Cara Bytecode Docs

The Full Documentation of CMC (Cara Machine Code).

- __ASOF Nov 17, 2024, The Contents of this File are *Not Yet Implemented.*__

## Runtime Context

There are several variables that CaraVM maintains statically throughout the program.



__The def `refbytes`__\
<small>*from cvm.hpp*</small>\
`#define refbytes unsigned long int`\
\
<small>*Expands to*</small>\
`static unsigned char refbytes;`

- The number of bytes per reference in memory.

- Set in the [Runtime Context instructions](#instructions) phase of the program.

__The Long Integer `instrct`__\
<small>*from cvm.hpp*</small>\
`STULONG instrct;`
\
<small>*Expands to</small>\
`static unsigned long int instrct;`

- Keeps track of every instruction completed.

## Instructions

Each instruction is essentially just a header describing what to do, then the following bytes are used to instruct the VM what to do it with.\
For instance,

### Exit

<small>*from instrs.h*</small>\
__`#define __EXIT__ 0xFF`__

- When the byte `__EXIT__`, or `0xFF`, appears in cara bytecode as a header, it is expected that the following 4 Bytes are the return value of the entire program, and that the bytecode is instructing the program to exit immediately.

#### Example

```
...

1111 1111 //FOUND: Byte 0xFF, __EXIT__, as header

0000 0000
0000 0000
0000 0000
0000 0000 //FOUND: 4-Byte exit code

//END INSTR
```

#### Full Structure

- `__EXIT__`
    - 4-Byte exit code.

### Load

<small>*from instrs.h*</small>\
__`#define __LOAD__ 0x01`__

- When the byte `__LOAD__` appears as a header
    
    - The next sequential `refbytes` Bytes are interpreted as the pointer to where the data should go.

    - It is expected to have 1 Byte afterwhich to read as the number of bytes to load into memory.
        
        - If the next sequential byte is Byte 0, then the following memory is interpreted a string, only stopping when Byte 0 is found again.
    
#### Example 1

For `refbytes = 2` (16 bit architecture)

```
...

0000 0001 //FOUND: Byte 0x1, __LOAD__, as header

0000 1010
0111 1100 //FOUND: Some 2-Byte reference in memory

0000 0000 //FOUND: Byte 0 as length indicating sequential memory is a string.

0100 1000 //'H'
0110 0101 //'e'
0110 1100 //'l'
0110 1100 //'l'
0110 1111 //'o'
0010 0000 //' '
0101 0111 //'W'
0110 1111 //'o'
0111 0010 //'r'
0110 1100 //'l'
0110 0100 //'d'

0000 0000//FOUND: Byte 0 as the end of string

//END INSTR

...

```

#### Example 2

For `refbytes = 8` (64 bit architecture)

```
...

0000 0001 //FOUND: Byte 0x1, __LOAD__, as header

0000 0000
0000 0000
0000 0000
0000 0000
0000 0000
0000 0000
0000 0000
0000 0001 //FOUND: 8-Byte reference to position in memory

0000 0100 //FOUND: Byte 0x4 as length in bytes of memory

1111 1111 
1111 1111
1111 1111
1111 1101 //FOUND: 4 Bytes of data to be loaded into memory

//END INSTR

...

```

#### Full Structure

- `__LOAD__`

    - `refbytes`-Bytes as reference

    - 1 Byte as `Length`

        - `Length` bytes as data,

        - if `Length` == 0, data is interpreted as a string

### LOAD_2


<small>*from instrs.h*</small>\
__`#define __LOAD_2__ 0x02`__

- When the byte `__LOAD_2__` appears as a header
    
    - The next sequential `refbytes` Bytes are interpreted as the pointer to where the data should go.

    - It is expected to have 2 Bytes afterwhich to read as the number of bytes to load into memory.
        
        - If the next sequential 2 bytes are ushort 0, then the following memory is interpreted a string, only stopping when Byte 0 is found again.

#### Full Structure

- `__LOAD_2__`

    - `refbytes`-Bytes as reference

    - 2 Bytes as `Length`

        - `Length` bytes as data,

        - if `Length` == 0, data is interpreted as a string

### LOAD_4


<small>*from instrs.h*</small>\
__`#define __LOAD_4__ 0x03`__

- When the byte `__LOAD_4__` appears as a header
    
    - The next sequential `refbytes` Bytes are interpreted as the pointer to where the data should go.

    - It is expected to have 4 Bytes afterwhich to read as the number of bytes to load into memory.
        
        - If the next sequential 4 bytes are uint 0, then the following memory is interpreted a string, only stopping when Byte 0 is found again.

#### Full Structure

- `__LOAD_4__`

    - `refbytes`-Bytes as reference

    - 4 Bytes as `Length`

        - `Length` bytes as data,

        - if `Length` == 0, data is interpreted as a string