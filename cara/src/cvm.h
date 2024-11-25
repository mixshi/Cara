
#ifndef __CVM_H__
#define __CVM_H__

#include <functional>

#include <vector>

#include <fstream>

#include <iostream>

#ifndef REGCT
#define REGCT                     16  //The number of registers to be maintained throughout the program.
#endif

#ifndef DEFAULT_REGISTER_RESERVE
#define DEFAULT_REGISTER_RESERVE  8  //The defulaut ammount of bytes per register,
#endif

//CONFIG WARNING: Expected to be primitive unsigned linearly numerical type ( char , short , int , etc. , )
#ifndef __REGPTR_T__
#define __REGPTR_T__ //register POINTER
typedef unsigned char Pointer_t;
#endif



#include "vmdefs.h"
#include "defs.h"
#include "panic.h"

typedef std::vector<byte> Register;

typedef class CaraVM {
public:
	static const char** error_msg;
	static bool error;


	static std::vector<Register> bufs;
	static unsigned long long int pPtr; //process pointer 

	static byte* program_data;
    inline static void* CARA_NULL() noexcept { return CaraVM::program_data; } 

	/* * bci
	 *
	 * Creates a ByteCodeIter for ifs
	 *
	 * */
	static BCI bci();

    static void start();

    // Places data at RegPtr_t into target `byte` for until it's size
    static void drefptr(Pointer_t, byte); // 
    
	static byte* refptr(Pointer_t); // reference a byte

	static void parse_opening_headers(BCI&);

    static byte refbytes;

    inline static void set_path(const char* path) {
		CaraVM::path = path;
    }
    static void bind_ifs();

	static void init_bufs();
    static void clear_bufs();
 
private:
	static const char* path;
	static std::ifstream* ifs; //In file stream of the input file <3
	static void __Validate__();	
   
    CaraVM() {}
    ~CaraVM() {}
} CVM;

#endif



