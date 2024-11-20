
#ifndef __VECTOR__
#define __VECTOR__
#include <vector>
#endif

#include <iostream>
#include <functional>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h> 

#ifndef __CARA_H__
#define __CARA_H__

#include "cvm.h"
#include "objects.h"
#include "instrs.h"


typedef std::function<void()> drawFN;

class Cara {
public:
    /*
     * 
     * Initializes Static Context
     * 
     * */
    static void init(const char*);
    static void init_verbose(const char*);

    static void start();

    //sets default draw function
    static void set_default_drawFN(drawFN*);
    
    //VAO Management Tools
    static void add_vao(GLuint);
    static void add_vao(GLuint, drawFN*);
    static void add_vaos(int, GLuint*);
    static void add_vaos(int, GLuint*, drawFN**);
    static void add_vaos(const std::vector<Vao>&);
    
    static int find_vao_idx(GLuint);
    
    static void rm_vao(int);
    static void rm_vaos(int, int);

    static void bind_drawFN(GLuint, drawFN*);
    static void bind_drawFN(int, drawFN*);
    
    /*
     *
     * Draws the content of the VAOs to the screen using their respective Draw Functions
     * 
     * */
    static void draw();

    static void dbg_vaos();
    
    static void dbg();

private:
    /*
     *
     * Collection of the VAOs of the static context.
     *
     * */
    static std::vector<Vao> vaos;

    /*
     *
     * Default draw function to be called for all VAO's with a null corresponding draw Function
     *
     * */
    static drawFN* default_drawFN;

    /*
     *
     * Collection of draw functions to be paired with the VAOs
     *
     * */
    static std::vector<drawFN*> drawFNs;

    Cara();
    ~Cara();
};

#endif
