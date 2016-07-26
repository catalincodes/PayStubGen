#include "Subject.h"



Subject::Subject()
{}


Subject::~Subject()
{
	for (vector<Observer*>::iterator currentObserver = listObservers.begin();
	currentObserver != listObservers.end(); ++currentObserver) {
		delete (*currentObserver);
		(*currentObserver) = nullptr;
	}
}
