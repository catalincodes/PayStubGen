#include "View.h"




View::View(Model *m)
{
	m->attach(this);
	this->myModel = m;
	this->myController = makeController();
}

Controller * View::makeController()
{
	Controller* n = new Controller(myModel, this);
	return n;
}

View::~View()
{
	myModel->detach(this);
}
