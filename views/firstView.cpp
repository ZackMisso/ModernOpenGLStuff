#include "firstView.h"
#include <iostream>

using namespace std;

FirstView::FirstView() {
  clearColor[0] = 1.0f;
  clearColor[1] = 1.0f;
  clearColor[2] = 1.0f;
  clearColor[3] = 1.0f;
}

void FirstView::display() {
  cout << "HELLO" << endl;
  glClearBufferfv(GL_COLOR,0,clearColor);
	glColor3f(1.0,0.0,0.0);
}

void FirstView::reshape(int w,int h) {
  glViewport(0,0,w,h);
}

void FirstView::keyboard(unsigned char key,int x,int y) {

}

void FirstView::mouseMove(int x,int y) {

}

void FirstView::mouseClick(int button,int state,int x,int y) {

}

void FirstView::initialize() {

}

void FirstView::destroy() {

}
