
#ifndef __VECTOR__
#define __VECTOR__
#include <vector>
#endif

#include <iostream>
#include <functional>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h> 

#ifndef __CARA__
#define __CARA__

#include "cvm.hpp"
#include "objects.hpp"
#include "fdefs.h"
#include "instrs.hpp"


class Cara {
public:
    /*
     * 
     * Initializes Static Context
     * 
     * */
    STVD init(const char*);
    STVD init_verbose(const char*);

    STVD start();

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
    
    STVD dbg();

private:
    /*
     *
     * Collection of the VAOs of the static context.
     *
     * */
    STVEC(Vao) vaos;

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
