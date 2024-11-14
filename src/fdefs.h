

#define STVD static void
#define STINT static int
#define STUINT static uint
#define STCHAR static char

#if !defined(GL_DEFS) && defined(__GLEW_H__) && defined(__GL_H__)
    #define  GL_DEFS

    #define STGLINT static GLint
    #define STGLUINT static GLuint
    #define STGLENUM static GLenum
    #define STGLCHAR static GLchar


#endif

#if !defined(OBJ_DEFS) && defined(__OBJECTS_HPP__)
    #define  OBJ_DEFS
    
    #define STVAO static Vao
    #define STVBO static Vbo
    #define STIBO static Ibo
    #define STDOG static DataObjectGroup
    #define STPROG static Program
    #define STSHDR static Shader
//  #define STUNIF static Uniform
#endif

#if !defined(CARA_DEFS) && defined(__CARA_HPP__)
    #define  CARA_DEFS

    #define STDFN static drawFN
#endif

#if !defined(VECT_DEFS) && defined(__VECTOR__)
    #define  VECT_DEFS
    
    #define STVEC(T) static std::vector<T>
    #define CNSTVEC(T) const std::vector<T>
    #define CXPRVEC(T) constexpr std::vector<T>
#endif

#if !defined(STR_DEFS) && defined(__STRING__)
    #define  STR_DEFS

    #define STSTR static std::string
#endif


#if !defined(STRSTR_DEFS) && defined(__SSTREAM__) 
    #define  STRSTR_DEFS

    #define STSSTR static std::stringstream
#endif

#if !defined(IFSTR_DEFS) && defined(__IFSTREAM__) 
    #define  IFSTR_DEFS
    
    #define STIFS static std::ifstream
    #define STOFS static std::ofstream
    #define STFS static std::fstream
#endif

