#include "Controller.h"

Controller::Controller(Model* myModel, View* myView)
{
	this->myModel = myModel;
	this->myView = myView;
	inputHandle = GetStdHandle(STD_INPUT_HANDLE);
	Events = 0;
	EventsRead = 0;
}


Controller::~Controller()
{}

void Controller::run()
{
	running = true;
}
