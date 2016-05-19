#include "firstView.h"
#include <iostream>

using namespace std;

FirstView::FirstView() {
  clearColor[0] = 0.0f;
  clearColor[1] = 0.0f;
  clearColor[2] = 0.0f;
  clearColor[3] = 1.0f;
}

void FirstView::display() {
  glPointSize(40.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(clearColor[0],clearColor[1],clearColor[2],clearColor[3]);
  glUseProgram(renderProgram);
  glDrawArrays(GL_POINTS,0,1);
}

void FirstView::reshape(int w,int h) {
  glViewport(0,0,w,h);
}

void FirstView::keyboard(unsigned char key,int x,int y) {
  // probably will do nothing
}

void FirstView::mouseMove(int x,int y) {
  // probably will do nothing
}

void FirstView::mouseClick(int button,int state,int x,int y) {
  // probably will do nothing
}

void FirstView::initialize() {
  // initialize shaders
  frag = new FragShader();
  vert = new VertShader();
  // read in the shader files
  frag->readFile("fragShaders/pos.frag");
  vert->readFile("vertShaders/pos.vert");
  // compile shaders
  renderProgram = Shader::compileShader(vert,frag);
  // create and link empty vao
  glGenVertexArrays(1,&vao);
  glBindVertexArray(vao);
}

void FirstView::destroy() {
  glDeleteVertexArrays(1,&vao);
  glDeleteProgram(renderProgram);
  glDeleteVertexArrays(1,&vao);
  frag->deleteShader();
  vert->deleteShader();
}
