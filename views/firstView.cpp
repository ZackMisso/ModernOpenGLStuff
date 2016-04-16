#include "firstView.h"

FirstView::FirstView() {

}

void FirstView::display() {
  glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5,0.5);
	glVertex2f(0.5,0.5);
	glVertex2f(0.0,0.0);
	glEnd();
	glutSwapBuffers();
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
