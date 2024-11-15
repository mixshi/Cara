# Cara

Cara is a student project game engine being written in C++, using OpenGL, GLEW, and GLFW.

__As of Nov 14, and likely stemming well into the new year of 2025 as development is slow when going solo, there is no stable/running version of Cara.__

## Intentions

- Cara is intended to be a loose abstraction around OpenGL, providing easy access to it's functionality through a static context

- I plan to expand it to more then just that but such as variations for directX, vulcan, etc., but again, Development is slow.

## Example

_Not yet stable, or even possible for that matter._

``` C++
#include <cara>
#include <vector>

const char* vertex_shader = R"(
#version 330 core

layout (location = 0) in vec3 vertex_position;
layout (location = 2) in vec3 vertex_normal;

uniform vec3 global_position;

out vec3 color;

void main() {
  //...
}

)";

const char* fragment_shader = R"(
#version 330 coreCara

in vec3 color;
out vec4 fragColor;

void main() {
  //...
  fragColor = vec4(color, 1.0);
}

)";

int main(void)
{
  Cara::init();

  std::vector <float> vertex_data_0 = { /* .. */ }
  std::vector <ushort> index_data_0 = { /* .. */ }

  std::vector <float> vertex_data_1 = { /* .. */ }
  std::vector <ushort> index_data_1 = { /* .. */ }

  //for glVertexAttribPointer(..), each index of `sizes` is enabled using glEnableVertexAttribArray(..), unless size in sizes == 0.
  //this means at location = 0, size = 3, location = 1 is not enabled, and at location = 3, size == 3. total stride = 3 + 0 + 3,  
  std::vector <ushort> sizes = { 3, 0, 3 }



  Program program = Cara::gen_prog({vertex_shader, fragment_shader});
  Cara::use_program(program);

  //ran for each VAO with no bound drawFN
  drawFN default_drawFN = [/*capture data*/] (Vao curr) -> void {
    glUniformXX(/*...*/);
    glDrawElements (
      //...
    );
  };
  Cara::set_default_drawFN(&default_drawFN);


  //Data Object Groups, i.e., Vao, Vbo, Ibo
  DOG dog_0 = DOG::gen();
  DOG dog_1 = DOG::gen();

  dog_0.setup(vertex_data_0, GL_STATIC_DRAW, index_data_0, GL_DYNAMIC_DRAW, sizes);
  dog_1.setuo(vertex_data_1, GL_STATIC_DRAW, index_data_1, GL_DYNAMIC_DRAW, sizes);

  Cara::add_vao(dog_0.vao());
  Cara::add_vao(dog_1.vao());

  drawFN other_drawFN = [/*...*/] (Vao curr) -> void {
    glUniformXX(/*..*/);
    glDrawArrays(
      //...
    );
  };
  
  Cara::bind_drawFN ( Cara::find_vao_idx(dog_0.vao), &other_drawFN );

  while (Cara::is_open()) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
    //`draw()` binds dog_0's VAO and calls to other_drawFN as it was bound to it via the VAO's Index.
    //It then binds dog_1's VAO and calls to default_drawFN as no drawFN was bound to dog_1's VAO's Index. 
    Cara::draw();

    glfwSwapBuffers();
    glfwPollEvents();
  }

}

```
