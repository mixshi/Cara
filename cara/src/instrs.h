#ifndef __INSTRS_H__
#define __INSTRS_H__

#ifndef __VMDEFS_H__
#include "vmdefs.h"
#endif

#include "fdefs.h"

/*
 * Byte Code Definitions
 * */
#define LOAD   0x1
#define LOAD_2 0x2
#define LOAD_4 0x3



#define EXIT   0xFF

/*
 * Instruction Definitions
 * */
class Instrs {
public:
    STVD _LOAD   (BCI&);
    STVD _LOAD_2 (BCI&);
    STVD _LOAD_4 (BCI&);

    STVD _EXIT   (BCI&);

private:
    Instrs() {}
    ~Instrs() {}
};
#endif