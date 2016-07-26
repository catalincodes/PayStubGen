#include "Model.h"
#include "ViewMainMenu.h"

typedef unsigned int unint;
Model::Model()
{
	this->attach(new ViewMainMenu(this));
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


/*************************************************************
* Method: addEntry()
* Parameters:	StubEntry *newEntry - existing StubEntry object
*
* Return:		Returns true if successful or false
*				if it was not possbile to add the object
*				or the object already exists
*
* Description:	Attempts to add the entry to entryList
*************************************************************/
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

/*************************************************************
* Method: findEntry()
* Parameters:	unint date - date of starting time
*				unint month - month of starting time
*				unint year - year of starting time
*				unint hr - hour of starting time
*				unint min - minute of start time
*
* Return:		Returns the position in the list of the 
*				first found target, OR the size of the 
*				array, if target not found.
*
* Description:	Attempts to find the entry in entryList 
*				that STARTS at the date, month, year, hour 
*				and minute given.
*************************************************************/ 
unint Model::findEntry(unint date, unint month, unint year, unint hr, unint min)
{ 
	for (unint i = 0; i < entryList.size();++i) {
		boost::posix_time::ptime startTime = entryList[i]->getStartTime();
		boost::gregorian::date startDate = startTime.date();
		if (((unsigned int)startDate.day_number() == date) &&
			((unsigned int)startDate.month().as_number() == month) &&
			((unsigned int)startDate.year() == year) &&
			((unsigned int)startTime.time_of_day().hours() == hr) &&
			((unsigned int)startTime.time_of_day().minutes() == min))
		{
			return i;
		}

	}
	return entryList.size();
}


bool Model::addEntry(unint date, unint month, unint year, unint startHr, unint startMin, unint endHr, unint endMin, double rate)
{
	StubEntry* newEntry = new StubEntry( //creates a new StubEntry
		StubEntry::generateTimeString(date,month, year, startHr, startMin), //generates a TimeString from the taken parameters for the start time
		StubEntry::generateTimeString(date, month, year, endHr, endMin), // generates a TimeString from the taken parameters for the end time
		rate); //
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
