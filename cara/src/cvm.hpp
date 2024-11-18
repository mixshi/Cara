
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

#include "vmdefs.h"
#include "fdefs.h"

class CaraVM {
public:
    STIFS* ifs;//in file stream of the input file <3
    STCHAR* error_msg;
    STBOOL error;

    STCNSTVEC(std::function<void(BCI&)>) instrset;

    STUCHAR take();
    // STUSHORT take2();
    // STUINT take3();
    // STUINT take4();
    // STVEC(unsigned char) take(int);

    STVD start();

    
    

    STVD ldptr(unsigned char, BCI&);

private:
    STUCHAR refbytes;
    STULONG instrct;
    
    STUCHAR** refbufs;
    
    STVD init_refbufs();
    STVD clean_refbufs();
    
    CaraVM() {}
    ~CaraVM() {}
};

#endif