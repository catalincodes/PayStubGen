#include "Model.h"
typedef unsigned int unint;
Model::Model()
{

}

Model::~Model()
{
	for (StubEntry* current : entryList) {
		if (current != nullptr)
			delete current;
	}
}

StubEntry * Model::getEntry(unint date, unint month, unint year, unint hr, unint min)
{
	unint pos = findEntry(date, month, year, hr, min);
	if (pos < entryList.size()) {
		return entryList[pos];
	}
	else {
		return nullptr;
	}
}



bool Model::addEntry(StubEntry * newEntry)
{
	vector<StubEntry*>::iterator pos = std::find(entryList.begin(), entryList.end(), nullptr);
	
	if (pos != entryList.end()) {
		*pos = newEntry;
	}
	else {
		entryList.push_back(newEntry);
	}
	return true;
}


unint Model::findEntry(unint date, unint month, unint year, unint hr, unint min)
{ /*

	for (unint i = 0; i < entryList.size();++i) {
		
		if ((entryList[i]->getDay() == date) &&
			(entryList[i]->getMonth() == month) &&
			(entryList[i]->getYear() == year) &&
			(entryList[i]->getStartHr() == hr) &&
			(entryList[i]->getStartMin() == min)) {
			return i;
		}

	}
	*/
	return entryList.size();
}


bool Model::addEntry(unint date, unint month, unint year, unint startHr, unint startMin, unint endHr, unint endMin, double rate)
{
	
	StubEntry* newEntry = new StubEntry();
	/*
	newEntry->setRate(rate);
	newEntry->setStartTime(date, month, year, startHr, startMin);
	newEntry->setEndTime(date, month, year, endHr, endMin);
	*/
	return addEntry(newEntry);
}



bool Model::removeEntry(unint date, unint month, unint year, unint hr, unint min)
{
	unint pos = findEntry(date, month, year, hr, min);
	if (pos < entryList.size())
	{
		delete entryList[pos];
		entryList[pos] = NULL;
		return true;
	}
	else {
		return false;
	}
}

void Model::removeEntry(unint i)
{
	if (entryList[i] != nullptr) {
		delete entryList[i];
		entryList[i] = nullptr;
	}
}