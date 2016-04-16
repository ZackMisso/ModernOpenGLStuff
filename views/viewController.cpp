#include "viewController.h"
#include "firstView.h"

ViewController* ViewController::instance = 0x0;

ViewController::ViewController() {
  currentView = new FirstView();
}

ViewController::~ViewController() {
  delete currentView;
}

void ViewController::initialize() {
  if(!instance)
    instance = new ViewController();
}

void ViewController::destroy() {
  if(instance)
    delete instance;
}

ViewController* ViewController::getInstance() {
  return instance;
}

View* ViewController::getCurrentView() { return currentView; }
