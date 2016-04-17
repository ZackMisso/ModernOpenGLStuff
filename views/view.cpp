#include "view.h"
#include <iostream>

using namespace std;

View::View() { }

View::~View() { }

GLuint View::compileShader(const GLchar* vert,const GLchar* frag) {
  // shader ids
  GLuint vertShader;
  GLuint fragShader;
  GLuint program;
  // create and compile vert shader
  vertShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertShader,1,&vert,NULL);
  glCompileShader(vertShader);
  // create and compile frag shader
  fragShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragShader,1,&frag,NULL);
  glCompileShader(fragShader);
  // create program, attach it, and link
  program = glCreateProgram();
  glAttachShader(program,vertShader);
  glAttachShader(program,fragShader);
  glLinkProgram(program);
  // delete the shaders
  glDeleteShader(vertShader);
  glDeleteShader(fragShader);
  return program;
}

void View::display() { }

void View::reshape(int w,int h) { }

void View::keyboard(unsigned char key,int x,int y) { }

void View::mouseMove(int x,int y) { }

void View::mouseClick(int button,int state,int x,int y) { }

void View::initialize() { }

void View::destroy() { }
