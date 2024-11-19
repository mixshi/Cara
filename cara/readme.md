
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

<small>*from instrs.hpp*</small>\
__`#define __EXIT__ 0xFF`__

- When the byte `EXIT`, or `0xFF`, appears in cara bytecode as a header, it is expected that the following 4 Bytes are the return value of the entire program, and that the bytecode is instructing the program to exit immediately.

#### Example

```
...

1111 1111 //FOUND: Byte 0xFF, EXIT, as header

0000 0000
0000 0000
0000 0000
0000 0000 //FOUND: 4-Byte exit code

//END INSTR
```

#### Full Structure

- `EXIT`
    - 4-Byte exit code.

### Load

<small>*from instrs.hpp*</small>\
__`#define LOAD 0x01`__

- When the byte `LOAD` appears as a header
    
    - The next sequential `refbytes` Bytes are interpreted as the pointer to where the data should go.

    - It is expected to have 1 Byte afterwhich to read as the number of bytes to load into memory.
        
        - If the next sequential byte is Byte 0, then the following memory is interpreted a string, only stopping when Byte 0 is found again.
    
#### Example 1


```
...

0000 0001 //FOUND: Byte 0x1, __LOAD__, as header

0111 1100 //FOUND: 1-byte target reference in `refbufs`

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


```
...

0000 0001 //FOUND: Byte 0x1, __LOAD__, as header

0000 0001 //FOUND: 1-Byte target reference to `refbufs`

0000 0100 //FOUND: Byte 0x4 as length in bytes of memory

1111 1111 
1111 1111
1111 1111
1111 1101 //FOUND: 4 Bytes of data to be loaded into memory

//END INSTR

...

```

#### Full Structure

- `LOAD`
    - Dereferences ptr 0 in `refbufs`
    - EXPECTS 1 byte as `length`
        - If `length` 0, EXPECTS null terminated data
        - Else, EXPECTS `length` bytes in data. 

~~I'm not writing complex examples for every single instruction.~~

### LoadL
---

Loads long data into memmory

<small>from instrs.hpp</small>\
__`#define LOADL 0x2`__

#### Full Structure

- `LOADL`
    - Dereferences ptr 0 in `refbufs`. 
    - EXPECTS 4 bytes as `length`
        - If `length` 0, EXPECTS null terminated data
        - Else, EXPECTS `length` bytes in data.

### LoadPTR
---
Loads a pointer into `refbufs`

<small>from instrs.hpp</small>\
__`#define LOADPTR 0x3`__

#### Full Structure

- `LOADPTR`
    - EXPECTS 1 byte as target to fill
    - EXPECTS `refbytes` bytes as pointer

### COPY
---

Copys data from one location to another

<small>from instrs.hpp</small>\
__`#define COPY 0x4`__


#### Full Structure

- `COPY`
    - EXPECTS 1 byte as first target of dereference for data to copy
    - EXPECTS 1 byte as second target of dereference for position to copy to
    - EXPECTS 1 byte as `length` of data to copy 
        - If `length` 0, writes null terminated data from first target to second.
        - Else, writes `length` bytes in data from first target to second.


### COPYL
---
Copys long data from one location to another

<small>from instrs.hpp</small>\
__`#define COPYL 0x5`__

#### Full Structure

- `COPYL`
    - EXPECTS 1 byte as first target of dereference to copy
    - EXPECTS 1 byte as second target of dereference to copy to
    - EXPECTS 4 bytes as `length` of data to copy
        - If `length` 0, writes null terminated data from first target to second.
        - Else, writes `length` bytes in data from first target to second.


### ReloadPTR
---

Loads pointer from memory into refbufs

<small>from instrs.hpp</small>\
__`#define RELOADPTR 0x6`__

#### Full Structure

- `RELOADPTR`
    - EXPECTS 1 byte as first target of dereference to load ptr from
    - EXPECTS 1 byte as second target to fill `refbufs[target]` with data from the dereferenced first target
        - Writes `refbytes` bytes to `refbufs[target]` from first dereferenced target




### Trap
___
Executes a trap routine such as uploading data to OpenGL, Printing data to the console, reading data from a file, etc.

<small>from instrs.hpp </small>\
__`#define TRAP 0x50`__

__Not Yet Implemented.__
