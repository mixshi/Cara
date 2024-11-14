#include "objects.hpp"

/*
 * Vertex Array Object
 * */
void Vao::bind() {
    glBindVertexArray(this->id);
}

Vao Vao::gen() {
    GLuint id;
    glGenVertexArrays(1, &id);
    return Vao(id);
}

std::vector<Vao> Vao::gen(int n) {
    std::vector<Vao> v(n +1);
    GLuint* ids = new GLuint[n];
    
    glGenVertexArrays(n, ids);

    for (int i = 0; i < n; i++)
        v.push_back(Vao(ids[i]));

    delete[] ids;
    return v;
}

/*
 * Vertex Buffer Object
 * */
void Vbo::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, this -> id);
}

void Vbo::data(int size, void* data, GLenum type) {
    glBufferData (
        GL_ARRAY_BUFFER,
        size,
        data,
        type
    );
}

Vbo Vbo::gen() {
    GLuint id;
    glGenBuffers(1, &id);
    return Vbo(id);
}

std::vector<Vbo> Vbo::gen(int n) {
    std::vector<Vbo> v(n +1);
    GLuint* ids = new GLuint[n];
    
    glGenBuffers(n, ids);

    for (int i = 0; i < n; i++)
        v.push_back(Vbo(ids[i]));

    delete[] ids;
    return v;
}

/*
 * Index Buffer Object
 * */
void Ibo::bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this -> id);
}

void Ibo::data(int size, void* data, GLenum type) {
    glBufferData (
        GL_ELEMENT_ARRAY_BUFFER,
        size,
        data,
        type
    );
}

Ibo Ibo::gen() {
    GLuint id;
    glGenBuffers(1, &id);
    return Ibo(id);
}

std::vector<Ibo> Ibo::gen(int n) {
    std::vector<Ibo> v(n +1);
    GLuint* ids = new GLuint[n];
    
    glGenBuffers(n, ids);

    for (int i = 0; i < n; i++)
        v.push_back(Ibo(ids[i]));

    delete[] ids;
    return v;
}

Vao DOG::get_vao() {
    return this -> vao;
}
Vbo DOG::get_vbo() {
    return this -> vbo;
}
Ibo DOG::get_ibo() {
    return this -> ibo;
}

void DOG::set_vao(Vao vao) {
    this->vao = vao;
}
void DOG::set_vbo(Vbo vbo) {
    this->vbo = vbo;
}
void DOG::set_ibo(ibo ibo) {
    this->ibo = ibo;
}


