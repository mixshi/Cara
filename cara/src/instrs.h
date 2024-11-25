#ifndef __INSTRS_H__
#define __INSTRS_H__

#include "cvm.h"
#include "vmdefs.h"
#include "defs.h"
#include "panic.h"

enum opcode {

		LD = 0, // mem --[]-> reg
		ST,     // reg --[]-> mem
				//
				// Load / Store data to / from memory
		
		LDI, // mem       --[Dereference]-> reg | buf
		STI, // reg | buf --[Dereference]-> mem
			 //
			 // Load / Store data indirectly to / from memory
			 
		JMP, // set CMV::PP
			 //
			 // Jump to positions

		CLR, // Clear content of a buf
		FLL, // Fill content of a buf 
		     //
			 // Manage bufs 
		
			 // ------------------------------
		ADD, // reg --[Addition]-> reg
    		 //
			 // Addition 
			 //              
		MUL, // reg --[Multiplication]-> reg
		DIV, // reg --[Divison]-> reg
			 //
			 // Multiply / Divide
			 // ------------------------------

		TRAP = 0x50, // exec complex functionality
				     //
		PHSE = 0x75, // Switch to different program phase
				     //
		EXIT = 0xFF  // exit program
					 //
};					 // misc


class Instrs {
    static void _LD   (ByteCodeIter&);
	static void _ST   (ByteCodeIter&);
    static void _LDI  (ByteCodeIter&);
	static void _STI  (ByteCodeIter&);
	static void _LDR  (ByteCodeIter&);
    static void _STR  (ByteCodeIter&);
	static void _LEA  (ByteCodeIter&);
	static void _JMP  (ByteCodeIter&);
	static void _CLR  (ByteCodeIter&);
	static void _FLL  (ByteCodeIter&);
	static void _ADD  (ByteCodeIter&);
	static void _MUL  (ByteCodeIter&);
	static void _DIV  (ByteCodeIter&);
										
	static void _TRAP (ByteCodeIter&);
	static void _PHSE (ByteCodeIter&);
	static void _EXIT (ByteCodeIter&);
private:	
	Instrs() {}
	~Instrs() {}

};


#endif
