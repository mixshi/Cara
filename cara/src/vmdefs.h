/*
    Virtual Machine Definitions
*/

#ifndef __VMDEFS_H__
#define __VMDEFS_H__

#ifndef __FUNCTIONAL__
#define __FUNCTIONAL__
#include <functional>
#endif

#include "fdefs.h"

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
public:
    std::function<byte()>* _peek;
    std::function<byte()>* _get;
    byte peek() {
        return (*_peek)();
    }
    byte get() {
        return (*_get)();
    }


    /* * pull_x
     *
     * Pulls a number from self
     *
     * - NOTE: Multiple Macro Expansions from "fdefs.h"
     *
     * */
    
    inline short pull_s () {

        return (ushort)((get() << 8) | get());

    }
    inline uint pull(){

        return (uint)((get() << 24) | (get() << 16) | (get() << 8) | get());

    }
    ul pull_l () {

        ul ret = 0;
        ul buf;

        for (byte i = 0; i < sizeof(ul); i++) {
            buf = get();
            buf <<= i * 8;
            ret |= buf;
        }

        return ret;
    }

    ull pull_ll() {
        
        ull ret = 0;
        ull buf;

        for (byte i = 0; i < sizeof(ull); i++) {
            buf = get();
            buf <<= i * 8;
            ret |= buf;
        }

        return ret;

    }


    ByteCodeIter (
        std::function<byte()>* peek,
        std::function<byte()>* get
    ) : 
    _peek(peek),
    _get(get)

    {}

};

#include "instrs.hpp"
#endif
