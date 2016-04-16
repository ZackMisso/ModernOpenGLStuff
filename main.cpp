// This Project is all my messing around with Modern OpenGL
#include <OpenGL/gl.h>
 #include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include "views/viewController.h"

// openGL methods
void display();
void reshape(int w,int h);
void keyboard(unsigned char key,int x,int y);
void mouseMove(int x,int y);
void mouseClick(int button,int state,int x,int y);

// variables
ViewController* viewController;

int main(int argc,char** argv) {
	ViewController::initialize();
	viewController = ViewController::getInstance();
  glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("Zack Misso - ModernGL");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMove);
  glutMainLoop();
  return 0;
}

void display() {
	viewController->getCurrentView()->display();
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
