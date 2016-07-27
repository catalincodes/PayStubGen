#pragma once
#include "Observer.h"

class Controller;


class View :
	public Observer
{
public:
	View();
	virtual ~View();

	virtual void update() = 0;
		
private:
};

