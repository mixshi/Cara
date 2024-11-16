
#ifndef __CVM_HPP__
#define __CVM_HPP__

#ifndef __VECTOR__
#define __VECTOR__
#include <vector>
#endif

#include "fdefs.h"

class CaraVM {
public:
    STVEC(unsigned char)* bytecode;

    void start();
    
    
private:
    
    CaraVM() {}
    ~CaraVM() {}
};

#endif