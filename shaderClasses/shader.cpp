#include "shader.h"
#include <stdio.h>
#include <stdlib.h>
#include <cassert>

using namespace std;

Shader::Shader(GLenum type,int len,const char* s)
      :shaderType(type),bytes(len),shaderObj(0),dirty(true)
{
  source = new GLchar[bytes];
  if(source)
    for(int i=0;i<bytes;i++)
      source[i]=s[i];
}

Shader::Shader(GLenum type)
      :shaderType(type),source(NULL),shaderObj(0),dirty(true)
{ }

Shader::~Shader() {
  reset();
  delete source;
}

bool Shader::readFile(const char* filename) {
  FILE *file = fopen(filename,"rb");
  if(file) {
    long size;
    fseek(file,0L,SEEK_END);
    size = ftell(file);
    fseek(file,0L,SEEK_SET);
    if(source)
      delete source;
    source = new GLchar[size];
    if(!source) {
      fprintf(stderr,"Error Reading Shader File\n");
      return false;
    }
    bytes = (int)fread(source,1,size,file);
    assert(bytes==size);
    fclose(file);
    dirty=true;
  } else {
    fprintf(stderr,"Could Not Open File\n");
    return false;
  }
  return true;
}

void Shader::validate() {
  if(dirty||!shaderObj) {
    if(!shaderObj)
      shaderObj = glCreateShader(shaderType);
    if(shaderObj) {
      const GLchar** s = (const GLchar**)&source;
      glShaderSource(shaderObj,1,s,&bytes);
      glCompileShader(shaderObj);
      dirty = false;
      GLint compiled = 0;
      glGetShaderiv(shaderObj,GL_COMPILE_STATUS,&compiled);
      if(!compiled)
        showInfo("shader");
    }
  }
}

void Shader::showInfo(const char* msg) {
  validate();
  GLint maxLength;
  GLint length;
  GLchar* info;
  glGetShaderiv(shaderObj,GL_INFO_LOG_LENGTH,&maxLength);
  if(maxLength>1) {
    info = (GLchar*)malloc(maxLength);
    if(info) {
      glGetShaderInfoLog(shaderObj,maxLength,&length,info);
      printf("///// %s info log contents /////\n",msg);
      printf("%s",info);
      printf("///// end /////\n");
      free(info);
    }
  } else {
    // not an error, good thing
    printf("///// %s has an empty info log /////\n",msg);
  }
}

void Shader::reset() {
  if(shaderObj) {
    glDeleteShader(shaderObj);
    shaderObj = 0;
  }
}

void Shader::release() {
  shaderObj = 0;
}

GLuint Shader::getShaderObj() {
  validate();
  return shaderObj;
}
