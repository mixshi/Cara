
#ifndef __CVM_HPP__
#define __CVM_HPP__

#ifndef __FUNCTIONAL__
#define __FUNCTIONAL__
#include <functional>
#endif

#ifndef __VECTOR__
#define __VECTOR__
#include <vector>
#endif

#ifndef __FSTREAM__
#define __FSTREAM__
#include <fstream>
#endif

#ifndef __IOSTREAM__
#define __IOSTREAM__
#include <iostream>
#endif

#define LEN_REF_BUFS 3

#if LEN_REF_BUFS < 3
#error "LEN_REF_BUFS is too small."
#endif

#include "vmdefs.h"
#include "fdefs.h"
#include "panic.h"

class CaraVM {
public:
    STIFS* ifs;//in file stream of the input file <3
    static char const ** error_msg;
    STBOOL error;
    STCHAR* path;

    STBYTE* program_data;

    STCNSTVEC(std::function<void(BCI&)>) instrset;


    /* * bci
     *
     * Creates a ByteCodeIter for ifs
     *
     * */
    STBCI bci();


    STVD start();


    /* * drefptr
     *
     * Dereference A Pointer
     *
     * Dereferences the pointer held in `refbufs[specified]`
     * 
     * ________________________________________
     * > byte : index of pointer in `refbufs`
     * ________________________________________
     *
     * - NOTE: Macro Expansion byte => unsigned char
     * - NOTE: Macro Expansion STBTYE => static unsigned char
     *
     * */
    STBYTE* drefptr(byte);

    /* *  numerateptr
     *
     * Numerate a Pointer to long long
     *
     * Turns the pointer held in `refbufs[specifed]` into a unsigned long long int
     *
     * ____________________________________________________
     * > byte : index of pointer in `refbufs` to numerate
     * ____________________________________________________
     *
     * - NOTE: Macro Expansion byte => unsigned char
     * - NOTE: Macro Expansion STULLONG => unsinged long long int
     *
     * */
    STULLONG numerateptr(byte);

    /* * parse_opening_headers
     *
     * Parse the Opening Headers to a Program.
     *
     * ____________________________________________________________________
     * BCI& `ByteCodeIter&` : ByteCodeIter reference to draw headers from
     * ____________________________________________________________________
     *
     * - NOTE: Macro Expansion STVD => static void
     * - NOTE: Macro Expansion BCI => ByteCodeIter
     *
     * */
    STVD parse_opening_headers(BCI&);

    STBYTE refbytes;
    STBYTE** refbufs;
private:
    STULONG instrct;

    
    STVD init_refbufs();
    STVD clean_refbufs();
    
    CaraVM() {}
    ~CaraVM() {}
};

#endif