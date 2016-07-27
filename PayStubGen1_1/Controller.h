#pragma once
#include "Model.h"

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

