// This Project is all my messing around with Modern OpenGL
#include <GLFW/glfw3.h>
#include "views/viewController.h"

// debug
#include <iostream>
using namespace std;

// openGL methods
void display();
void reshape(int w,int h);
void keyboard(GLFWwindow* window,int key,int scancode,int action,int mods);
void mouseMove(int x,int y);
void mouseClick(int button,int state,int x,int y);
void error(int error, const char* description);

// variables
ViewController* viewController;

int main(int argc,char** argv) {
	//cout << "Starting" << endl;
	ViewController::initialize();
  viewController = ViewController::getInstance();
	//viewController = ViewController::getInstance();
	//cout << "Got View Controller" << endl;

  if(!glfwInit())
    exit(EXIT_FAILURE);
  GLFWwindow* window = glfwCreateWindow(1000,1000,"Zack Misso - ModernGL",NULL,NULL);
  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  int width;
  int height;
  glfwSetErrorCallback(error);
  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window,keyboard);
  glfwGetFramebufferSize(window, &width, &height);
  glViewport(0,0,width,height);
  glfwSwapInterval(1);

  while (!glfwWindowShouldClose(window))
  {
    // Main Loop
    display();
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}

void display() {
	//cout << "HI" << endl;
  glClearColor(0.0,0.0,0.0,1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	viewController->getCurrentView()->display();
	//glutSwapBuffers();
}

void reshape(int w,int h) {
	glViewport(0,0,w,h);
}

void keyboard(GLFWwindow* window,int key,int scancode,int action,int mods) {
  if(key==GLFW_KEY_ESCAPE && action==GLFW_PRESS)
    glfwSetWindowShouldClose(window,GL_TRUE);
  // to be implemented
}

void mouseMove(int x,int y) {
	viewController->getCurrentView()->mouseMove(x,y);
}

void mouseClick(int button,int state,int x,int y) {
	viewController->getCurrentView()->mouseClick(button,state,x,y);
}

void error(int error, const char* description) {
    fputs(description, stderr);
}
