
#ifndef __VECTOR__
#define __VECTOR__
#include <vector>
#endif

#include <iostream>
#include <functional>
#include <GL/glew.h>
#include <GL/gl.h>

#ifndef __CARA_HPP__
#define __CARA_HPP__

#include "objects.hpp"
#include "fdefs.h"

typedef std::function<void()> drawFN;

class Cara {
public:
    /*
     * 
     * Initializes Static Context
     * 
     * */
    STVD init();
    STVD init_verbose();

    //sets default draw function
    STVD set_default_drawFN(drawFN*);
    
    //VAO Management Tools
    STVD add_vao(GLuint);
    STVD add_vao(GLuint, drawFN*);
    STVD add_vaos(int, GLuint*);
    STVD add_vaos(int, GLuint*, drawFN**);
    STVD add_vaos(CNSTVEC(Vao)&);
    
    STINT find_vao_idx(GLuint);
    
    STVD rm_vao(int);
    STVD rm_vaos(int, int);

    STVD bind_drawFN(GLuint, drawFN*);
    STVD bind_drawFN(int, drawFN*);
    
    /*
     *
     * Draws the content of the VAOs to the screen using their respective Draw Functions
     * 
     * */
    STVD draw();

    STVD dbg_vaos();
    STVD add_vao(GLuint);
    STVD add_vao(GLuint, drawFN*);
    STVD add_vaos(int, GLuint*);
    STVD add_vaos(int, GLuint*, drawFN**);
    STVD add_vaos(CNSTVEC(Vao)&);
    STVD dbg();

private:
    /*
     *
     * Collection of the VAOs of the static context.
     *
     * */
    STVEC(GLuint) vaos;

    /*
     *
     * Default draw function to be called for all VAO's with a null corresponding draw Function
     *
     * */
    STDFN* default_drawFN;

    /*
     *
     * Collection of draw functions to be paired with the VAOs
     *
     * */
    STVEC(drawFN*) drawFNs;

    Cara();
    ~Cara();
};

#endif
