#include "firstView.h"
#include <iostream>

using namespace std;

FirstView::FirstView() {
  cout << "FIRST VIEW" << endl;
  clearColor[0] = 0.0f;
  clearColor[1] = 1.0f;
  clearColor[2] = 1.0f;
  clearColor[3] = 1.0f;
  cout << "FIRST VIEW" << endl;
  glClearColor(clearColor[0],clearColor[1],clearColor[2],clearColor[3]);
  cout << "FIRST VIEW" << endl;
}

void FirstView::display() {
  cout << "First View Display" << endl;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //glClearBufferfv(GL_COLOR,0,clearColor);
  //glClearBufferfv(GL_DEPTH,0,clearColor);
	//glColor3f(1.0,0.0,0.0);
  glutSwapBuffers();
}

GLuint FirstView::compileShaders() {
  //GLuint vertShader;
  //GLuint fracShader;
  //GLuint program;
  return 0;
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
  // probably will do nothing
}

void FirstView::destroy() {
  // probably will do nothing
}
