#ifndef __VECTOR__
#define __VECTOR__
#include <vector>
#endif

#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#ifndef __OBJECTS_HPP__
#define __OBJECTS_HPP__
#define DOG DataObjectGroup

#include "fdefs.h"

template <typename T>

//VAO
class Vao {
private:
    GLuint id;
public:
    void bind();
    STVAO gen();
    STVEC(Vao) gen(int);

    Vao() : id(0) {}
    Vao(GLuint id) : id(id) {}
    ~Vao() {}

};

//VBO
class Vbo {
private:
    GLuint id;
public:
    void bind();
    void data(int, void*, GLenum);
    STVBO gen();
    STVEC(Vbo) gen(int);

    Vbo() : id(0) {}
    Vbo(GLuint id) : id(id) {}
    ~Vbo() {}

};

//IBO
class Ibo {
private:
    GLuint id;
public:
    void bind();
    void data(int, void*, GLenum);
    void data(CNSTVEC(ushort)&, GLenum);
    void data(CNSTVEC(uint)&, GLenum);
    STIBO gen();
    STVEC(Ibo) gen(int);

    Ibo() : id(0) {}
    Ibo(GLuint id) : id(id)  {}
    ~Ibo() {}
};

//DOG
class DataObjectGroup {
private:
    Vao vao;
    Vbo vbo;
    Ibo ibo;
public:
    
    Vao get_vao();
    Vbo get_vbo();
    Ibo get_ibo();

    void set_vao(Vao);
    void set_vbo(Vbo);
    void set_ibo(Ibo);

    STDOG gen();
    STVEC(DOG) gen(int);

    STVD set_sizes(CNSTVEC(ushort)&);
    STVD set_sizes(int, ushort*);

    
    /*
     * NOTE: macro expansion DOG => DataObjectGroup
     * */
    DOG (
    ) : 
        vao(Vao()),
        vbo(Vbo()),
        ibo(Ibo()) 
    { }

    DOG (
        Vao vao,
        Vbo vbo,
        Ibo ibo
    ) : 
        vao(vao), 
        vbo(vbo), 
        ibo(ibo) 
    { }
    
    ~DOG (
    ) 
    { }
};

//PROGRAM

//SHADER

//UNIFORM?

#endif