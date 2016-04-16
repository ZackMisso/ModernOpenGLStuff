// This Project is all my messing around with Modern OpenGL
#include <OpenGL/gl.h>
 #include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include "views/viewController.h"

// debug
#include <iostream>
using namespace std;

// openGL methods
void display();
void reshape(int w,int h);
void keyboard(unsigned char key,int x,int y);
void mouseMove(int x,int y);
void mouseClick(int button,int state,int x,int y);

// variables
ViewController* viewController;

int main(int argc,char** argv) {
	//cout << "Starting" << endl;
	//ViewController::initialize();
	//viewController = ViewController::getInstance();
	//cout << "Got View Controller" << endl;
  glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("Zack Misso - ModernGL");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMove);
	ViewController::initialize();
	viewController = ViewController::getInstance();
  glutMainLoop();
  return 0;
}

void display() {
	cout << "HI" << endl;
	viewController->getCurrentView()->display();
	//glutSwapBuffers();
}

void reshape(int w,int h) {
	glViewport(0,0,w,h);
}

void keyboard(unsigned char key,int x,int y) {
	viewController->getCurrentView()->keyboard(key,x,y);
}

void mouseMove(int x,int y) {
	viewController->getCurrentView()->mouseMove(x,y);
}

void mouseClick(int button,int state,int x,int y) {
	viewController->getCurrentView()->mouseClick(button,state,x,y);
}
