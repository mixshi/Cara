
/*
    Virtual Machine Definitions
*/

#ifndef __VMDEFS_H__
#define __VMDEFS_H__


#define FIRST_1  0b0000000000000001
#define FIRST_2  0b0000000000000011
#define FIRST_3  0b0000000000000111
#define FIRST_4  0b0000000000001111
#define FIRST_5  0b0000000000011111
#define FIRST_6  0b0000000000111111
#define FIRST_7  0b0000000001111111
#define FIRST_8  0b0000000011111111
#define FIRST_9  0b0000000111111111
#define FIRST_10 0b0000001111111111
#define FIRST_11 0b0000011111111111
#define FIRST_12 0b0000111111111111
#define FIRST_13 0b0001111111111111
#define FIRST_14 0b0011111111111111
#define FIRST_15 0b0111111111111111
#define FIRST_16 0b1111111111111111




class ByteCodeIter {
private:
    std::function<char()>* _peek;
    std::function<char()>* _get;
public:
    char peek() {
        return (*_peek)();
    }
    char get() {
        return (*_get)();
    }

    ByteCodeIter (
        std::function<char()>* peek,
        std::function<char()>* get
    ) : 
    _peek(peek),
    _get(get)

    {}

};

#ifndef __INSTRS_H__
#include "instrs.h"
#endif
#endif
