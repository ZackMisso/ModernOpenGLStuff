#ifndef __FRAGSHADER_H__
#define __FRAGSHADER_H__

#include "shader.h"

class FragShader : public Shader {
private:
public:
  FragShader(int len,const char* s);
  FragShader();
  ~FragShader();
};

#endif
