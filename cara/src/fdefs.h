
/*
    Function Definitions

    -- Implemented on an "as needed" basis --
*/

#ifndef __FDEFS_H__
#define __FDEFS_H__

#define STVD static void
#define STLONG static long int
#define STLLONG static long long int
#define STULONG static unsigned long int
#define STULLONG static unsigned long long int
#define STINT static int
#define STUINT static unsigned int
#define STSHORT static short
#define STUSHORT static unsigned short
#define STCHAR static char
#define STCNSTCHAR static const char
#define STUCHAR static unsigned char
#define STBYTE static unsigned char
//lol
#define STCNSTXPRUCHAR static constexpr unsigned char
#define STBOOL static bool

#endif

#ifndef TYPES
    #define TYPES

    typedef unsigned long long int ull;
    typedef unsigned long int ul;
    typedef unsigned int uint;
    typedef unsigned short int ushort;
    typedef unsigned char uchar;
    typedef unsigned char byte;
#endif /* TYPES */

#if !defined(GL_DEFS) && defined(__GLEW_H__) && defined(__GL_H__)
    #define  GL_DEFS

    #define STGLINT static GLint
    #define STGLUINT static GLuint
    #define STGLENUM static GLenum
    #define STGLCHAR static GLchar

#endif /* GL_DEFS */

#if !defined(GLFW_DEFS) && defined(GLFW_DONT_CARE)
    #define  GLFW_DEFS

    #define STWIN static GLFWwindow*
#endif /* GLFW_DEFS */

#if !defined(OBJ_DEFS) && defined(__OBJECTS__)
    #define  OBJ_DEFS
    
    #define DOG DataObjectGroup
    #define STVAO static Vao
    #define STVBO static Vbo
    #define STIBO static Ibo
    #define STDOG static DataObjectGroup
    #define STPROG static Program
    #define STSHDR static Shader
//  #define STUNIF static Uniform
#endif /* OBJ_DEFS */

#if !defined(CARA_DEFS) && defined(__CARA__)
    #define  CARA_DEFS

    typedef std::function<void()> drawFN;
    #define STDFN static drawFN

#endif /* CARA_DEFS */

#if !defined(VECT_DEFS) && defined(__VECTOR__)
    #define  VECT_DEFS
    
    #define STVEC(T) static std::vector<T>
    #define CNSTVEC(T) const std::vector<T>
    #define STCNSTVEC(T) static const std::vector<T>
    #define CNSTXPRVEC(T) constexpr std::vector<T>
    #define STCNSTXPRVEC(T) static constexpr std::vector<T>
#endif /* VECT_DEFS */

#if !defined(STR_DEFS) && defined(__STRING__)
    #define  STR_DEFS

    #define STSTR static std::string
#endif /* STR_DEFS */


#if !defined(STRSTR_DEFS) && defined(__SSTREAM__) 
    #define  STRSTR_DEFS

    #define STSSTR static std::stringstream
#endif /* STRSTR_DEFS */

#if !defined(FSTR_DEFS) && defined(__FSTREAM__) 
    #define  FSTR_DEFS
    
    #define STIFS static std::ifstream
    #define STOFS static std::ofstream
    #define STFS static std::fstream
    #define CNSTIFS const std::ifstream
    #define CNSTOFS const std::ofstream
    #define CNSTFS static std::fstream
#endif /* FSTR_DEFS */

#if !defined(VMFDEFS) && defined(__VMDEFS_H__)
    #define  VMFDEFS

    #define BCI ByteCodeIter
    #define STBCI static ByteCodeIter
    #define CNSTBCI const ByteCodeIter
    #define STCNSTBCI static const ByteCodeIter
#endif /* VMFDEFS */
