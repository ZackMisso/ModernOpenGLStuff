#include "view.h"
#include <iostream>
#include <vector>

using namespace std;

View::View() { }

View::~View() { }

GLuint View::compileShader(const Shader* vert,const Shader* frag) {
  // shader ids
  GLuint vertShader;
  GLuint fragShader;
  GLuint program;
  // create and compile vert shader
  cout << "Creating Vertex Shader" << endl;
  vertShader = glCreateShader(GL_VERTEX_SHADER);
  cout << "Shader Source" << endl;
  const GLchar* vertSource = vert->getSource();
  const GLint vertLength = vert->getBytes();
  glShaderSource(vertShader,1,&vertSource,&vertLength);
  cout << "Compiling Vert Shader" << endl;
  glCompileShader(vertShader);
  GLint success = 0;
  glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);
  if(success == GL_FALSE) {
    cout << "ERROR COMPILING VERTEX SHADER" << endl;
    GLint logSize = 0;
    glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &logSize);
	  vector<GLchar> errorLog(logSize);
	  glGetShaderInfoLog(vertShader, logSize, &logSize, &errorLog[0]);
    for(int i=0;i<errorLog.size()-1;i++) {
      cout << errorLog[i];
    }
    cout << endl;
  }
  // create and compile frag shader
  cout << "Creating Frag Shader" << endl;
  fragShader = glCreateShader(GL_FRAGMENT_SHADER);
  const GLchar* fragSource = frag->getSource();
  const GLint fragLength = frag->getBytes();
  glShaderSource(fragShader,1,&fragSource,&fragLength);
  cout << "Compiling Frag Shader" << endl;
  glCompileShader(fragShader);
  success = 0;
  glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
  if(success == GL_FALSE) {
    cout << "ERROR COMPILING FRAGMENT SHADER" << endl;
    GLint logSize = 0;
    glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &logSize);
	  vector<GLchar> errorLog(logSize);
	  glGetShaderInfoLog(fragShader, logSize, &logSize, &errorLog[0]);
    for(int i=0;i<errorLog.size()-1;i++) {
      cout << errorLog[i];
    }
    cout << endl;
  }
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
