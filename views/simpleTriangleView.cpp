#include "simpleTriangleView.h"

SimpleTriangleView::SimpleTriangleView() {
	clearColor[0] = 0.0f;
	clearColor[1] = 0.0f;
	clearColor[2] = 0.0f;
	clearColor[3] = 1.0f;
}

void SimpleTriangleView::display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearBufferfv(GL_COLOR,0,clearColor);
	glUseProgram(simpleProgram);
	glDrawArrays(GL_TRIANGLES,0,3);
}

void SimpleTriangleView::keyboard(int key,int scancode,int action,int mods) {
	// to be implemented
}

void SimpleTriangleView::initialize() {
	// initialize shaders
	simpleFrag = new FragShader();
	simpleVert = new VertShader();
	// read in the shader files
	simpleFrag->readFile("fragShaders/pos.frag");
	simpleVert->readFile("vertShaders/pos.vert");
	// compile shaders
	simpleProgram = Shader::compileShader(simpleVert,simpleFrag);
	// create and link empty vao
	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);
	// set the start time
	start = clock();
}

void SimpleTriangleView::destroy() {
	glDeleteVertexArrays(1,&vao);
	glDeleteProgram(simpleProgram);
	glDeleteVertexArrays(1,&vao);
	simpleFrag->deleteShader();
	simpleVert->deleteShader();
}
