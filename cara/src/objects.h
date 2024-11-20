#ifndef __VECTOR__
#define __VECTOR__
#include <vector>
#endif

#include "defs.h"
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#ifndef __OBJECTS_H__
#define __OBJECTS_H__

//VAO
class Vao {
private:
    GLuint id;
public:
    inline GLuint get_id() {
        return this->id; 
    }
    void bind();
    static Vao gen();
    static std::vector<Vao> gen(int);

    Vao() : id(0) {}
    Vao(GLuint id) : id(id) {}
    ~Vao() {}

};

//VBO
class Vbo {
private:
    GLuint id;
public:
    inline GLuint get_id() {
        return this->id;
    }
    inline void bind() {
        glBindBuffer(GL_ARRAY_BUFFER, this -> id);
    }
    inline void data(int size, void* data, GLenum type) {
        glBufferData (
            GL_ARRAY_BUFFER,
            size,
            data,
            type
        );
    }
    void data(const std::vector<byte>&, GLenum);
    void data(const std::vector<ushort>&, GLenum);
    void data(const std::vector<uint>&, GLenum);

    static Vbo gen();
    static std::vector<Vbo> gen(int);

    Vbo() : id(0) {}
    Vbo(GLuint id) : id(id) {}
    ~Vbo() {}
};

//IBO
class Ibo {
private:
    GLuint id;
public:
    inline GLuint get_id() {
        return this->id;
    }
    inline void bind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this -> id);
    }
    inline void data(int size, void* data, GLenum type) {
        glBufferData (
            GL_ELEMENT_ARRAY_BUFFER,
            size,
            data,
            type
        );
    }
    void data(const std::vector<byte>&, GLenum);
    void data(const std::vector<ushort>&, GLenum);
    void data(const std::vector<uint>&, GLenum);
    
    static Ibo gen();
    static std::vector<Ibo> gen(int);

    Ibo() : id(0) {}
    Ibo(GLuint id) : id(id)  {}
    ~Ibo() {}
};

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

    static DataObjectGroup gen();
    static std::vector<DataObjectGroup> gen(int);

    static void set_sizes(const std::vector<ushort>&);
    static void set_sizes(int, ushort*);

    

    DataObjectGroup (
    ) : 
        vao(Vao()),
        vbo(Vbo()),
        ibo(Ibo()) 
    { }

    DataObjectGroup (
        Vao vao,
        Vbo vbo,
        Ibo ibo
    ) : 
        vao(vao), 
        vbo(vbo), 
        ibo(ibo) 
    { }
    
    ~DataObjectGroup (
    ) 
    { }
};

//PROGRAM

//SHADER

//UNIFORM?

#endif