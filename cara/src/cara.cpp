
#include "cara.hpp"


std::vector<Vao> 
    
    Cara::vaos;

drawFN* 
    
    Cara::default_drawFN;

std::vector<drawFN*> 
    
    Cara::drawFNs;

void Cara::add_vao(GLuint vao) {
    Cara::vaos.push_back(vao);
    Cara::drawFNs.push_back(nullptr);
}


void Cara::add_vao(GLuint vao, drawFN* dfn) {
    Cara::vaos.push_back(vao);
    Cara::drawFNs.push_back(dfn);
}


void Cara::add_vaos(int vaoc, GLuint* vao) {
    if (vaoc <= 0)
        return;
    
    Cara::vaos.reserve(Cara::vaos.size() + vaoc);
    
    for (int i = 0; i < vaoc; i++) {
        Cara::vaos.push_back(vao[i]);
    }
}

void Cara::add_vaos(int vaoc, GLuint* vao, drawFN** dfns) {
    if (vaoc <= 0)
        return;
    
    Cara::vaos.reserve(Cara::vaos.size() + vaoc);
    Cara::drawFNs.reserve(Cara::drawFNs.size() + vaoc);

    for (int i = 0; i < vaoc; i++) {
        Cara::vaos.push_back(vao[i]);
        Cara::drawFNs.push_back(dfns[i]);
    }
}

void Cara::add_vaos(CNSTVEC(Vao)& vaos) {
    Cara::vaos.insert(Cara::vaos.end(), vaos.begin(), vaos.end());
}

int Cara::find_vao_idx(GLuint vao) {
    for (int i = 0; i < Cara::vaos.size(); i++)
        if (Cara::vaos.at(i).get_id() == vao)
            return i;    
    return -1;
}

void Cara::rm_vao(int idx) {
    if (idx < 0)
        return;
    Cara::vaos.erase(Cara::vaos.begin() + idx);
}
void Cara::rm_vaos(int start, int end) {
    Cara::vaos.erase(Cara::vaos.begin() + start, Cara::vaos.begin() + end);
}

void Cara::dbg_vaos() {
    std::cout << "`Cara::vaos`: ";
    for (int i = 0; i < Cara::vaos.size(); i++) {
        std::cout << Cara::vaos.at(i).get_id() << (((i +1) == Cara::vaos.size())? "" : ", ");
    }
    std::cout << std::endl;
}
void Cara::dbg() {
    //Debug everything...
    Cara::dbg_vaos();
}

void Cara::bind_drawFN(int idx, drawFN* dfn) {
    Cara::drawFNs.at(idx) = dfn;
}

void Cara::bind_drawFN(GLuint vao, drawFN* dfn) {
    Cara::bind_drawFN(Cara::find_vao_idx(vao), dfn);
}

void Cara::set_default_drawFN(drawFN* dfn) {
    Cara::default_drawFN = dfn;
}

void Cara::init(const char* path) {
    panic_unimplemented("Cara::init(const char*)");

    Cara::vaos = {};
    Cara::drawFNs = {};
    Cara::default_drawFN = nullptr;
    CaraVM::path = (char*)path;
    CaraVM::ifs = new std::ifstream(path);
}
void Cara::init_verbose(const char*) {
    panic_unimplemented("Cara::init_verbose(const char*)");    
}

void Cara::draw() {
    
    for (int i = 0; i < Cara::vaos.size(); i++) {

        glBindVertexArray(Cara::vaos.at(i).get_id());
        
        if (Cara::drawFNs.at(i) != nullptr)
            (*(Cara::drawFNs.at(i)))();
        else if (Cara::default_drawFN != nullptr)
            (*(Cara::default_drawFN))();
        else {
            std::cerr << "Error; No draw function bound to VAO at index `" << i << "`, nor has any drawFN been bound to default." << std::endl;   
        }
    }

}


void Cara::start() {
    CaraVM::start();
}


Cara::Cara() {
    exit(-1);
}
Cara::~Cara(){
}
