#pragma once
#include "Model.h"
#include "View.h"

class View;
class Model;

class Controller
{
public:
	Controller(Model* usedModel);
	~Controller();

	void run();

private:
	Model* myModel;
};

