#ifndef __INSTRS_H__
#define __INSTRS_H__

#include "cvm.h"
#include "vmdefs.h"
#include "defs.h"
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
    static void _LOAD      (BCI&); //load data from file
    static void _LOADL     (BCI&); //load long data from file
    static void _LOADPTR   (BCI&); //load pointer from file
    
    static void _COPY      (BCI&); //copy data from memory
    static void _COPYL     (BCI&); //copy long data from memory
    static void _RELOADPTR (BCI&); //load pointer from memory

    static void _TRAP      (BCI&); //Execute trap routine

    static void _EXIT      (BCI&); //Exit the program

    //static std::function<void(BCI&)>** context_declarative_instructions;

    static std::vector<std::function<void(BCI&)>*> context_runtime_instructions;

    //static std::function<void(BCI&)>** context_dispositional_instructions;


private:
    Instrs() {}
    ~Instrs() {}
};
#endif