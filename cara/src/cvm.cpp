#include "cvm.hpp"

std::ifstream* CaraVM::ifs = nullptr;
char* CaraVM::error_msg = nullptr;
bool CaraVM::error = false; 
unsigned char** CaraVM::refbufs;
unsigned char CaraVM::refbytes = 0;
unsigned long int CaraVM::instrct = 0;

// char* CaraVM::refbufs[3] = {nullptr, nullptr, nullptr};

unsigned char CaraVM::take() {
    if (CaraVM::ifs->peek() == -1) {
        CaraVM::error = (char*)"EOF";
        std::cout << CaraVM::error;
        return -1;
    }
    return (unsigned char)(CaraVM::ifs->get() &FIRST_8);
}
// STUSHORT CaraVM::take2();
// STUINT CaraVM::take3();
// STUINT CaraVM::take4();
// STVEC(unsigned char) CaraVM::take(int);


void CaraVM::start() {
    if (!CaraVM::ifs || CaraVM::ifs->fail() || !CaraVM::ifs->good()) {
        std::cerr << "Error Error Error Error Error Error Error" << std::endl;
        exit(-1);
    }
    CaraVM::init_refbufs();
}

void CaraVM::ldptr(unsigned char idx, BCI& bci) {
    if (CaraVM::error)
        return;
    if (idx > LEN_REF_BUFS) {
        CaraVM::error = true;
        CaraVM::error_msg = (char*)"REFBUF IDX OUT OF BOUNDS";
        return;
    }
    
    for (char i = 0; i < CaraVM::refbytes && !CaraVM::error; i++) {
        CaraVM::refbufs[idx][i] = bci.get();
    }
}

void CaraVM::init_refbufs() {
    CaraVM::refbufs = new unsigned char* [LEN_REF_BUFS];
    for (int i = 0; i < LEN_REF_BUFS; i++) {
        CaraVM::refbufs[i] = new unsigned char[CaraVM::refbytes];
    }
}

void CaraVM::clean_refbufs() {
    for (int i = 0; i < LEN_REF_BUFS; i++) {
        delete[] CaraVM::refbufs[i];
        CaraVM::refbufs[i] = nullptr;
    } 
}
