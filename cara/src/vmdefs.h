/*
    Virtual Machine Definitions
*/
#include "defs.h"

#ifndef __VMDEFS_H__
#define __VMDEFS_H__


#include <functional>

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

typedef class ByteCodeIter {
public:
    byte (*_peek)();
    byte (*_get)();
    bool (*_good)();

    byte peek() {
        return (*_peek)();
    }
    byte get() {
        return (*_get)();
    }
    bool good() {
        return (*_good)();
    }

    /* * pull_x
     *
     * Pulls a number from self
     *
     * - NOTE: Multiple Macro Expansions from "fdefs.h"
     *
     * */
    
    short pull_s () {

        return (ushort)((get() << 8) | get());

    }
    uint pull(){

        return (uint)((get() << 24) | (get() << 16) | (get() << 8) | get());

    }
    unsigned long pull_l () {

        unsigned long ret = 0;
        unsigned long buf;

        for (byte i = 0; i < sizeof(long); i++) {
            buf = get();
            buf <<= i * 8;
            ret |= buf;
        }

        return ret;
    }

    unsigned long long pull_ll() {
        
        unsigned long long ret = 0;
        unsigned long long buf;

        for (byte i = 0; i < sizeof(long long); i++) {
            buf = get();
            buf <<= i * 8;
            ret |= buf;
        }

        return ret;

    }

    Pointer_t pull_ptr() {
		char ret[sizeof(Pointer_t)];

		for (byte i = 0; i < sizeof(Pointer_t); i++)
			ret[i] = get();
		return *((Pointer_t*)ret);
	}

    ByteCodeIter (
        byte (*peek)(),
        byte (*get)(),
        bool (*good)()
    ) : 
    _peek(peek),
    _get(get),
    _good(good)
    {}

} BCI;

#endif
