#pragma once

// This View Displays a Single Triangle

#include "view.h"
#include "../shaderClasses/fragShader.h"
#include "../shaderClasses/vertShader.h"
#include <ctime>

class SimpleTriangleView : public View {
private:
	FragShader* simpleFrag;
	VertShader* simpleVert;
	GLfloat clearColor[4];
	GLuint simpleProgram;
	GLuint vao;
	clock_t start;
public:
	SimpleTriangleView();
	virtual void display();
	virtual void keyboard(int key,int scancode,int action,int mods);
	virtual void initialize();
	virtual void destroy();
};
