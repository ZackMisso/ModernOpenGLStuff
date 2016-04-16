#include "view.h"
#include <iostream>

using namespace std;

View::View() { }

void View::display() { cout << "WHAT" << endl; }

void View::reshape(int w,int h) { }

void View::keyboard(unsigned char key,int x,int y) { }

void View::mouseMove(int x,int y) { }

void View::mouseClick(int button,int state,int x,int y) { }

void View::initialize() { }

void View::destroy() { }
