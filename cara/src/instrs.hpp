#ifndef __INSTRS_HPP__
#define __INSTRS_HPP__

#include "cvm.hpp"
#include "vmdefs.h"
#include "fdefs.h"
#include "panic.h"

#define LOAD      0x1
#define LOADL     0x2
#define LOADPTR   0x3

#define COPY      0x4
#define COPYL     0x5
#define RELOADPTR 0x6


#define TRAP 0x50

#define EXIT    0xFF

class Instrs {
public:
    STVD _LOAD      (BCI&); //load data from file
    STVD _LOADL     (BCI&); //load long data from file
    STVD _LOADPTR   (BCI&); //load pointer from file
 
    STVD _COPY      (BCI&); //copy data from memory
    STVD _COPYL     (BCI&); //copy long data from memory
    STVD _RELOADPTR (BCI&); //load pointer from memory

    STVD _TRAP      (BCI&); //Execute trap routine

    STVD _EXIT      (BCI&); //Exit the program

    //static std::function<void(BCI&)>** context_declarative_instructions;

    STVEC(std::function<void(BCI&)>*) context_runtime_instructions;

    //static std::function<void(BCI&)>** context_dispositional_instructions;


private:
    Instrs() {}
    ~Instrs() {}
};
#endif