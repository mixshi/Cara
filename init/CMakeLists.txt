cmake_minimum_required(VERSION 3.30.5)

project(cara LANGUAGES CXX)

#LEGACY for old gl, or GLVND for newer versions works
set(OpenGL_GL_PREFERENCE GLVND)
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

add_executable(run ../src/main.cpp ../src/cara.cpp ../src/objects.cpp)

target_link_libraries(run glfw OpenGL::GL GLEW::GLEW)



