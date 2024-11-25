#include "cvm.h"

std::ifstream* CVM::ifs = nullptr;
const char* CVM::path = nullptr;

bool CVM::error = false; 
char const** CVM::error_msg;

unsigned long long int CVM::pPtr;
std::vector<Register> CVM::bufs(REGCT +1);
byte CVM::refbytes = 0;

byte* CVM::program_data;

void CVM::__Validate__() {

	if (REGCT < 12) {
		panic("Register Count Not High Enough.");			
    }
	
 	if ( DEFAULT_REGISTER_RESERVE < 0 || DEFAULT_REGISTER_RESERVE > 0xff ) {
		panic("Default Register Reserve must be between 0 and 255");
	}

	if (sizeof(Pointer_t) > 32 || sizeof(Pointer_t) < 1) {

		panic("Poninter size (RegPtr_t) must be between 1 and 32 bytes");

	}
}

byte* CVM::refptr(Pointer_t ptr) {
    
    byte* rv = (byte*) (CVM::pPtr + ptr);

	return rv;

}

BCI CVM::bci() {
    return ByteCodeIter (
         []() -> byte {
            if (!CVM::ifs->good()) {
                CVM::error = true;
                CVM::error_msg = &prematureEOF;   
                return -1;
            }
            return CVM::ifs->peek();
        },
        []() -> byte {
            if (!CVM::ifs->good()) {
                CVM::error = true;
				CVM::error_msg = &prematureEOF;
                return -1;
            }
            return CVM::ifs->get();
        },
        []() -> bool {
            return CVM::ifs->good();
        }
    );
}


void CVM::drefptr(Pointer_t memPtr, byte target) {
    if (CVM::error)
        return;
    if (target >= REGCT) {
        CVM::error = true;
        CVM::error_msg = &refidxOB;
        return;
    }

    byte* ptr = CVM::refptr(memPtr);

	
	// Remember size
	byte size = CVM::bufs.at(target).size();
	
	// Clear buffer to refill with same size
	CVM::bufs.at(target).clear();
	
	// Add each byte to target for until size
	for (byte i = 0; i < size; i++, ptr++)
		CVM::bufs.at(target).push_back(*ptr);
    
	

};

void CVM::start() {
    panic_unimplemented("CaraVM::start()");
		
}

void CVM::parse_opening_headers(BCI& bci) {
    panic_unimplemented("CaraVM::parse_opening_headers(ByteCodeIter&)");
} 

void CVM::init_bufs() {
    CVM::__Validate__();
    if (CVM::bufs.size() > 0)
		CVM::clear_bufs();

    for (int i = 0; i < REGCT; i++) {
        CVM::bufs.push_back({});
		CVM::bufs.at(i).reserve(DEFAULT_REGISTER_RESERVE);
	}
}


void CVM::clear_bufs() {
    for (int i = 0; i < REGCT; i++) {
        CVM::bufs[i].clear();
	} 
}

void CVM::bind_ifs() {
	if (CVM::ifs) //Delete heap allocation every renewal so we don't eat ourselves
		delete CVM::ifs;
    CVM::ifs = new std::ifstream(CVM::path);
}
