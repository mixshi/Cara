#include "objects.h"

/*
 * Vertex Array Object
 * */
VAO VAO::gen() {
    GLuint id;
    glGenVertexArrays(1, &id);
    return Vao(id);
}

std::vector<VAO> VAO::gen(int n) {
    std::vector<VAO> v(n +1);
    GLuint* ids = new GLuint[n];
    
    glGenVertexArrays(n, ids);

    for (int i = 0; i < n; i++)
        v.push_back(VAO(ids[i]));

    delete[] ids;
    return v;
}



/*
 * Vertex Buffer Object
 * */
VBO VBO::gen() {
    GLuint id;
    glGenBuffers(1, &id);
    return VBO(id);
}

std::vector<VBO> VBO::gen(int n) {
    std::vector<VBO> v(n +1);
    GLuint* ids = new GLuint[n];
    
    glGenBuffers(n, ids);

    for (int i = 0; i < n; i++)
        v.push_back(VBO(ids[i]));

    delete[] ids;
    return v;
}

void VBO::data(const std::vector<byte>& vec, GLenum type) {
    glBufferData(
        GL_ARRAY_BUFFER,
        vec.size(),
        vec.data(),
        type
    );
}

void VBO::data(const std::vector<ushort>& vec, GLenum type) {
    glBufferData(
        GL_ARRAY_BUFFER,
        vec.size() *sizeof(ushort),
        vec.data(),
        type
    );
}

void VBO::data(const std::vector<uint>& vec, GLenum type) {
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
IBO IBO::gen() {
    GLuint id;
    glGenBuffers(1, &id);
    return IBO(id);
}

std::vector<IBO> IBO::gen(int n) {
    std::vector<IBO> v(n +1);
    GLuint* ids = new GLuint[n];
    
    glGenBuffers(n, ids);

    for (int i = 0; i < n; i++)
        v.push_back(IBO(ids[i]));

    delete[] ids;
    return v;
}

void IBO::data(const std::vector<byte>& vec, GLenum type) {
    glBufferData(
        GL_ARRAY_BUFFER,
        vec.size(),
        (void*)vec.data(),
        type
    );
}
void IBO::data(const std::vector<ushort>& vec, GLenum type) {
    glBufferData(
        GL_ARRAY_BUFFER,
        vec.size() *sizeof(ushort),
        (void*)vec.data(),
        type
    );
}
void IBO::data(const std::vector<uint>& vec, GLenum type) {
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
VAO DOG::get_vao() {
    return this -> vao;
}
VBO DOG::get_vbo() {
    return this -> vbo;
}
IBO DOG::get_ibo() {
    return this -> ibo;
}

void DOG::set_vao(Vao vao) {
    this->vao = vao;
}
void DOG::set_vbo(Vbo vbo) {
    this->vbo = vbo;
}
void DOG::set_ibo(Ibo ibo) {
    this->ibo = ibo;
}


