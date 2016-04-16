#ifndef __FIRSTVIEW_H__
#define __FIRSTVIEW_H__

#include "view.h"

class FirstView : public View {
private:
  GLfloat clearColor[4];
  GLuint compileShaders();
public:
  FirstView();
  virtual void display();
  virtual void reshape(int w,int h);
  virtual void keyboard(unsigned char key,int x,int y);
  virtual void mouseMove(int x,int y);
  virtual void mouseClick(int button,int state,int x,int y);
  virtual void initialize();
  virtual void destroy();
};

#endif
