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
	virtual ~View();

	virtual void update() = 0;
		
private:
	Model* myModel;
};

