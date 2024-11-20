#include "cvm.h"

std::ifstream* CaraVM::ifs = nullptr;

char* CaraVM::path = nullptr;

bool CaraVM::error = false; 

char const** CaraVM::error_msg;

byte** CaraVM::refbufs;

byte* CaraVM::program_data;

byte CaraVM::refbytes = 0;

unsigned long int CaraVM::instrct = 0;

static std::function<byte()> ifs_peek = []() -> byte {
    if (!CaraVM::ifs->good()) {
        CaraVM::error = true;
        CaraVM::error_msg = &prematureEOF;   
    }
    return CaraVM::ifs->peek();
}; 

static std::function<byte()> ifs_get = []() -> byte {
    if (!CaraVM::ifs->good()) {
        CaraVM::error = true;
        CaraVM::error_msg = &prematureEOF;   
    }
    return CaraVM::ifs->get();
};

BCI CaraVM::bci() {
    return ByteCodeIter (
        &ifs_peek,
        &ifs_get
    );
}

void CaraVM::start() {
    panic_unimplemented("CaraVM::start()");
    
    if (!CaraVM::ifs || CaraVM::ifs->fail() || !CaraVM::ifs->good()) {
        panic_ifs_failue(CaraVM::path);
    }
    CaraVM::init_refbufs();
}

byte* CaraVM::drefptr(byte idx) {
    if (CaraVM::error)
        return nullptr;
    if (idx > LEN_REF_BUFS) {
        CaraVM::error = true;
        CaraVM::error_msg = &refidxOB;
        return nullptr;
    }

    byte* ret = CaraVM::program_data;

    for (byte i = CaraVM::refbytes -1, j = 0; i >= 0; i--, j++) {
        ret += CaraVM::refbufs[idx][i] << j;
    }

    if (ret == CaraVM::program_data)
        panic_nullptr__deref();

    return ret;
}

//FIXME: I don't remember writing this 3;

// unsigned long long CaraVM::numerateptr(byte idx) {
//     if (CaraVM::error)
//         return -1;
//     if (idx > LEN_REF_BUFS) {
//         CaraVM::error = true;
//         CaraVM::error_msg = &refidxOB;
//         return -1;
//     }

//     ull ret = 0;

//     for (byte i = (CaraVM::refbytes <= sizeof(ull)? CaraVM::refbytes -1 : sizeof(ull) -1), j = 0; i >= 0; i--, j++) {
//         ret |= CaraVM::refbufs[idx][i] << j;
//     }

//     return ret;
// }

void CaraVM::parse_opening_headers(BCI& bci) {
    panic_unimplemented("CaraVM::parse_opening_headers(ByteCodeIter&)");
} 

void CaraVM::init_refbufs() {
    CaraVM::refbufs = new byte* [LEN_REF_BUFS];
    for (int i = 0; i < LEN_REF_BUFS; i++) {
        CaraVM::refbufs[i] = new byte[CaraVM::refbytes];
    }
}

void CaraVM::clean_refbufs() {
    for (int i = 0; i < LEN_REF_BUFS; i++) {
        delete[] CaraVM::refbufs[i];
        CaraVM::refbufs[i] = nullptr;
    } 
}
