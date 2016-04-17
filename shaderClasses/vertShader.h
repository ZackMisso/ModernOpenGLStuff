#ifndef __VERTSHADER_H__
#define __VERTSHADER_H__

#include "shader.h"

class VertShader : public Shader {
private:
public:
  VertShader(int len,const char* s);
  VertShader();
  ~VertShader();
};

#endif
