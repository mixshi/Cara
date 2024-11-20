#include "instrs.h" 



void Instrs::_LOAD (BCI& bci) { //0x1
    if (CaraVM::error)
        return;
    byte* ptr = CaraVM::drefptr(0);

    byte len = bci.get();

    if (len) {
        for (byte i = 0; i < len; i++) {
            ptr[i] = bci.get();
        }
    } else {
        for (; bci.peek(); ptr++)
            *ptr = bci.get();            
        ptr[1] = 0;
    }
}   

void Instrs::_LOADL (BCI& bci) { //0x2
    if (CaraVM::error)
        return;
    byte* ptr = CaraVM::drefptr(0);

    uint len = bci.pull();

    if (len) {
        for (uint i = 0; i < len; i++) {
            ptr[i] = bci.get();
        }
    } else {
        for (; bci.peek(); ptr++)
            *ptr = bci.get();
        ptr[1] = 0;
    }
}

void Instrs::_LOADPTR(BCI& bci) { //0x3
    if (CaraVM::error)
        return;

    byte target = bci.get();
    if (target >= LEN_REF_BUFS) {
        CaraVM::error = true;
        CaraVM::error_msg = &refidxOB;
        return;
    }
    
    for (byte i = 0; i < CaraVM::refbytes && !CaraVM::error; i++) {
        CaraVM::refbufs[target][i] = bci.get();
    }
}

void Instrs::_COPY(BCI& bci) { //0x4
    if (CaraVM::error)
        return;
    byte target = bci.get();
    byte target_2 = bci.get();
    byte length = bci.get();

    if (target >= LEN_REF_BUFS || target_2 >= LEN_REF_BUFS) {
        CaraVM::error = true;
        CaraVM::error_msg = &refidxOB;
        return;
    }

    byte* from = CaraVM::drefptr(target);
    byte* to   = CaraVM::drefptr(target_2);

    if (length) 
        for (byte i = 0; i < length; i++, from++, to++) 
            *to = *from;
    else {
        for (; *from; from++, to++) 
            *to = *from;
    }
    
}


void Instrs::_RELOADPTR(BCI& bci) {
    byte target = bci.get();
    byte target_2 = bci.get();

    if (target >= LEN_REF_BUFS || target_2 >= LEN_REF_BUFS) {
        CaraVM::error = true;
        CaraVM::error_msg = &refidxOB;
        return;
    }

    byte* ref = CaraVM::drefptr(target);


    for (byte i = 0; i < CaraVM::refbytes; i++, ref++) {
        CaraVM::refbufs[target_2][i] = *ref;
    }

}


void Instrs::_EXIT (BCI& bci) { 
    exit((bci.get() << 24) | (bci.get() << 16) | (bci.get() << 8) || bci.get()); 
}