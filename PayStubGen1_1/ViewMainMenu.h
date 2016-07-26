#pragma once
#include "View.h"
class ViewMainMenu :
	public View
{
	void displayMenu();
public:
	virtual void update();
	ViewMainMenu(Model* usedModel);
	virtual ~ViewMainMenu();
};

