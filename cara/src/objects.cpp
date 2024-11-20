#include "objects.h"

/*
 * Vertex Array Object
 * */

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

void Vbo::data(const std::vector<byte>& vec, GLenum type) {
    glBufferData(
        GL_ARRAY_BUFFER,
        vec.size(),
        vec.data(),
        type
    );
}

void Vbo::data(const std::vector<ushort>& vec, GLenum type) {
    glBufferData(
        GL_ARRAY_BUFFER,
        vec.size() *sizeof(ushort),
        vec.data(),
        type
    );
}

void Vbo::data(const std::vector<uint>& vec, GLenum type) {
    glBufferData(
        GL_ARRAY_BUFFER,
        vec.size() *sizeof(uint),
        vec.data(),
        type
    );
}

/*
 * Index Buffer Object
 * */
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

void Ibo::data(const std::vector<byte>& vec, GLenum type) {
    glBufferData(
        GL_ARRAY_BUFFER,
        vec.size(),
        (void*)vec.data(),
        type
    );
}
void Ibo::data(const std::vector<ushort>& vec, GLenum type) {
    glBufferData(
        GL_ARRAY_BUFFER,
        vec.size() *sizeof(ushort),
        (void*)vec.data(),
        type
    );
}
void Ibo::data(const std::vector<uint>& vec, GLenum type) {
    glBufferData(
        GL_ARRAY_BUFFER,
        vec.size() *sizeof(uint),
        (void*)vec.data(),
        type
    );
}

/*
 * Data Object Group
 * */
Vao DataObjectGroup::get_vao() {
    return this -> vao;
}
Vbo DataObjectGroup::get_vbo() {
    return this -> vbo;
}
Ibo DataObjectGroup::get_ibo() {
    return this -> ibo;
}

void DataObjectGroup::set_vao(Vao vao) {
    this->vao = vao;
}
void DataObjectGroup::set_vbo(Vbo vbo) {
    this->vbo = vbo;
}
void DataObjectGroup::set_ibo(Ibo ibo) {
    this->ibo = ibo;
}


