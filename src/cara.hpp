
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

    STVD init();
    STVD init_verbose();

    STVD set_default_drawFN(drawFN*);
    
    STVD add_vao(GLuint);
    STVD add_vao(GLuint, drawFN*);
    STVD add_vaos(int, GLuint*);
    STVD add_vaos(int, GLuint*, drawFN**);
    STVD add_vaos(CNSTVEC(Vao))

    STINT find_vao_idx(GLuint);

    STVD rm_vao(int);
    STVD rm_vaos(int, int);

    STVD draw();

    STVD bind_drawFN(GLuint, drawFN*);
    STVD bind_drawFN(int, drawFN*);

    STVD dbg_vaos();
    STVD dbg();

private:

    STVEC(GLuint) vaos;
    STDFN* default_drawFN;
    STVEC(drawFN*) drawFNs;

    Cara();
    ~Cara();
};

#endif
