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
  cout << "Creating Vertex Shader" << endl;
  vertShader = glCreateShader(GL_VERTEX_SHADER);
  cout << "Shader Source" << endl;
  glShaderSource(vertShader,1,&vert,NULL);
  cout << "Compiling Shader" << endl;
  glCompileShader(vertShader);
  // create and compile frag shader
  cout << "Creating Frag Shader" << endl;
  fragShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragShader,1,&frag,NULL);
  glCompileShader(fragShader);
  // create program, attach it, and link
  cout << "Creating Program" << endl;
  program = glCreateProgram();
  glAttachShader(program,vertShader);
  glAttachShader(program,fragShader);
  glLinkProgram(program);
  // delete the shaders
  cout << "Deleting Shaders" << endl;
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
