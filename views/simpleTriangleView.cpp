#include "simpleTriangleView.h"
#include <tgmath.h>

SimpleTriangleView::SimpleTriangleView() {
	clearColor[0] = 0.0f;
	clearColor[1] = 0.0f;
	clearColor[2] = 0.0f;
	clearColor[3] = 1.0f;
}

void SimpleTriangleView::display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearBufferfv(GL_COLOR,0,clearColor);
	double dt = (clock()-start)/(double)CLOCKS_PER_SEC*10;
	glUseProgram(simpleProgram);
	GLfloat attrib[] = { (float)sin(dt) * 0.5f,
											 (float)cos(dt) * 0.6f,
											 0.0f, 0.0f };
	const GLfloat color[] = { (float)sin(dt) * 0.5f + 0.5f,
											 (float)cos(dt) * 0.5f + 0.5f,
										 	 0.0f, 1.0f };
	glVertexAttrib4fv(0,attrib);
	glVertexAttrib4fv(1,color);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glDrawArrays(GL_TRIANGLES,0,3);
}

void SimpleTriangleView::keyboard(int key,int scancode,int action,int mods) {
	// to be implemented
}

void SimpleTriangleView::initialize() {
	// initialize shaders
	simpleFrag = new FragShader();
	simpleVert = new VertShader();
	simpleTessC = new TessCShader();
	simpleTessE = new TessEShader();
	// read in the shader files
	simpleFrag->readFile("fragShaders/simpleTriangle.frag");
	simpleVert->readFile("vertShaders/simpleTriangle.vert");
	simpleTessC->readFile("tessControlShaders/simpleTriangle.tessc");
	simpleTessE->readFile("tessEvaluationShaders/simpleTriangle.tesse");
	// compile shaders
	simpleProgram = Shader::compileShader(simpleVert,simpleFrag);
	//simpleProgram = Shader::compileShader(simpleVert,simpleFrag,simpleTessC,simpleTessE);
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
