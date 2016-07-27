#pragma once
#include "Subject.h"
#include "StubEntry.h"



using std::vector;

class Model :
	public Subject
{
public:
	typedef unsigned int unint;
	//constructor
	Model();
	~Model();
	
	//getters
	StubEntry* getEntry(unint date, unint month, unint year, unint hr, unint min);

	//setters
	bool addEntry(unint date, unint month, unint year, unint startHr, unint startMin, unint endHr, unint endMin, double rate);
	bool removeEntry(unint date, unint month, unint year, unint hr, unint min);
	void removeEntry(unint i);
private:
	//private methods
	bool addEntry(StubEntry* newEntry);
	unint findEntry(unint date, unint month, unint year, unint hr, unint min);

	//core data
	vector <StubEntry*> entryList;
};