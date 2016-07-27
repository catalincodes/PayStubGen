#pragma once
#include "View.h"
#include "Model.h"

class ViewMainMenu :
	public View
{
	void display();
	Model* usedModel;
public:
	virtual void update();
	ViewMainMenu();
	virtual ~ViewMainMenu();
	void setModel(Model* givenModel) { usedModel = givenModel; }
};

