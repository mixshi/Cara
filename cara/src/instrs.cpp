#include "instrs.h"


// Loads data from mem to some register
void Instrs::_LD(BCI& bci) {
	Pointer_t ptr = bci.pull_ptr();	
	
	CVM::drefptr(ptr, bci.get());
}

void Instrs::_ST(BCI& bci) {
    byte target = bci.get();
    byte* memref = CVM::refptr(bci.pull_ptr());

    ushort sz = CVM::bufs.at(target).size(); 

	for (byte i = 0; i < sz; i++, memref++) {
			CVM::bufs.at(target).at(i) = *memref;
	}

}

void Instrs::_LDI(BCI& bci) {
    Pointer_t ptr = bci.pull_ptr();


}

void Instrs::_STI(BCI& bci){

}

void Instrs::_LDR(BCI& bci) {

}

void Instrs::_STR(BCI& bci) {

}

void Instrs::_LEA(BCI& bci){

}

void Instrs::_JMP(BCI& bci) {

}

void Instrs::_CLR(BCI& bci) {
    byte target = bci.get();
	CVM::bufs.at(target).clear();
}

void Instrs::_FLL(BCI& bci) {
    byte target = bci.get();
    byte filler = bci.get();
	byte size   = bci.get();

	for (byte i = 0; i < size; i++) 
		CVM::bufs.at(target).push_back(filler);
}

void Instrs::_ADD(BCI& bci) {
    byte addend_1 = bci.get();
	byte addend_2 = bci.get();

}

void Instrs::_MUL(BCI& bci){
    byte multiplicand_1 = bci.get();
	byte multiplicand_2 = bci.get();

}

void Instrs::_DIV(BCI& bci) {
    byte dividand_1 = bci.get();
	byte dividand_2 = bci.get();
    
	{
		bool fail = true;
		for (byte i = 0; i < CVM::bufs.at(dividand_2).size(); i++) {
			if (CVM::bufs.at(dividand_2).at(i) != 0) fail == false;
		}
	    
		if (fail) {
		    const char** err = new const char*("Attempted to divide by 0");
		    CVM::error = true;
			CVM::error_msg = err;
		    panic(*err);
		}
	}

}

void Instrs::_TRAP(BCI& bci) {
		panic_unimplemented("amogus");

}

void Instrs::_EXIT(BCI& bci) {
}


