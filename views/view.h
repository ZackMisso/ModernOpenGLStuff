#ifndef __VIEW_H__
#define __VIEW_H__

#include <OpenGL/gl.h>
 #include <OpenGL/glu.h>
#include <GLUT/glut.h>

class View {
private:
public:
  View();
  virtual void display();
  virtual void reshape(int w,int h);
  virtual void keyboard(unsigned char key,int x,int y);
  virtual void mouseMove(int x,int y);
  virtual void mouseClick(int button,int state,int x,int y);
  virtual void initialize();
  virtual void destroy();
};

#endif
