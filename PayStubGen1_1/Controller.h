#pragma once
#include "Model.h"
#include "View.h"
#include "Windows.h"

class View;
class Model;

class Controller
{
public:
	Controller(Model*, View*);
	~Controller();

	HANDLE inputHandle;
	DWORD Events;
	DWORD EventsRead;

	void run();

private:
	bool running;
	Model* myModel;
	View* myView;
};

