#include "viewController.h"
#include "firstView.h"
#include <iostream>

using namespace std;

ViewController* ViewController::instance = 0x0;

ViewController::ViewController() {
  currentView = new FirstView();
  currentView->initialize();
}

ViewController::~ViewController() {
  delete currentView;
}

void ViewController::initialize() {
  cout << "Initializing View Controller" << endl;
  if(!instance)
    instance = new ViewController();
  cout << "View Controller Initialized" << endl;
}

void ViewController::destroy() {
  if(instance)
    delete instance;
}

ViewController* ViewController::getInstance() {
  return instance;
}

void ViewController::switchToView(View* view) {
  currentView->destroy();
  delete currentView;
  currentView = view;
}

View* ViewController::getCurrentView() { return currentView; }
