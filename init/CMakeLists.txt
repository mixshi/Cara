cmake_minimum_required(VERSION 3.30.5)

project(cara LANGUAGES CXX)

# LEGACY for old gl, or GLVND for newer versions works
set(OpenGL_GL_PREFERENCE GLVND)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

set(SRC_DIR $(CMAKE_CURRENT_SOURCE_DIR)/../cara/src)

add_executable( run
    ${SRC_DIR}/main.cpp 

    ${SRC_DIR}/cvm.cpp 
    ${SRC_DIR}/objects.cpp 
    ${SRC_DIR}/cara.cpp 
    ${SRC_DIR}/instrs.cpp
)


# add_executable( _test 
#     ${SRC_DIR}/tests.cpp 
# )

# TODO: implement tests dummy!

target_link_libraries(run glfw OpenGL::GL GLEW::GLEW)
# target_link_libraries(_test glfw OpenGL::GL GLEW::GLEW)

