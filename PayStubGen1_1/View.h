#pragma once
#include "Observer.h"
#include "Model.h"
#include "Controller.h"

class Model;
class Controller;


class View :
	public Observer
{
public:
	View(Model *m);
	~View();

	void update() {}

	Controller* makeController();
	Controller* getController() { return myController; }
	
private:
	Model* myModel;
	Controller* myController;
};

