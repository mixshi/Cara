
#ifndef __PANIC_H__
#define __PANIC_H__

#include <cstdlib>

#ifndef __IOSTREAM__
#define __IOSTREAM__
#include <iostream>
#endif

static const char* refidxOB = "REFERENCE BUFFER INDEX OUT OF BOUNDS";
static const char* prematureEOF = "Prematurely reached the EOF (end of file).";

inline static void panic_unimplemented(const char* unimplemented_func) {
    
    std::cerr << "Error, use of Unimplemented Method \"" << unimplemented_func << "\"" << std::endl;
    exit (-1);

}
inline static void panic_ifs_failue(const char* path) {
    std::cerr << "Error, Input File Stream (ifstream) failure\n File may have been empty, or couldn't find file of path \"" << (path? path : "NULLPTR") << "\"." << std::endl;
    exit(-1);
}

inline static void panic_nullptr__deref() {
    std::cerr<< "Error, attempted to dereference a null pointer.";
    exit(-1);
}

#endif
