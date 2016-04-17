#ifndef __SHADER_H__
#define __SHADER_H__

#include <GLFW/glfw3.h>

class Shader {
private:
  GLenum shaderType;
  GLint bytes;
  GLchar* source;
  GLuint shaderObj;
  bool dirty;
public:
  Shader(GLenum type,int len,const char* s);
  Shader(GLenum type);
  ~Shader();
  bool readFile(const char* file);
  void validate();
  void showInfo(const char* msg);
  void reset();
  void release();
  // getter methods
  GLuint getShaderObj();
};

#endif
