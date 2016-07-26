#include <iostream>
//#include "Observer.h"
//#include "Model.h"
//#include "View.h"
#include "StubEntry.h"
#include <fstream>




using std::cout;
using std::endl;
using std::cin;


int main()
{
	string startTime, endTime;
	cout << "Provide start time : "; getline(cin, startTime);
	cout << "Provide end time : "; getline(cin, endTime);
	
	StubEntry* test = new StubEntry(startTime, endTime);
	
	cout << to_simple_string(test->getStartTime()) << endl;
	cout << to_simple_string(test->getEndTime()) << endl;
	time_duration difference = test->getEndTime() - test->getStartTime();
	cout << "The difference is : " << to_simple_string(difference) << endl;
	try
	{
		std::ofstream ofs("test.txt");
		boost::archive::text_oarchive outputArchive(ofs);
		(*test).getStartTime();
		outputArchive << (*test);
		ofs.close();
	}
	catch (std::exception &e) {
		cout << "Exception caught:" << e.what() << endl;
	}

	delete test;
	test = new StubEntry();
	try
	{
		std::ifstream ifs("test.txt");
		if (ifs.is_open()) {
			cout << "File was opened correctly!" << endl;
		}
		else {
			cout << "Problem opening file!" << endl;
		}
		boost::archive::text_iarchive inputArchive(ifs);
		inputArchive >> (*test);
		
		ifs.close();
	}
	catch (std::exception &e) {
		cout << "Exception caught:" << e.what() << endl;
	}

	cout << to_simple_string(test->getEndTime()) << endl;
	
	delete test;
	test = nullptr;

	
	
	/*
	Model* m = new Model();
	View* v = new View(m);
	Controller *c = v->getController();
	
	delete c;
	delete v;
	delete m;
	*/

	/*
	tm* startTimeTM = new tm();
	time_t currentTime;
	time(&currentTime);

	int day = 22;
	int month = 3;
	int year = 2012;
	int hr = 17;
	int min = 30;

	localtime_s(startTimeTM, &currentTime);

	cout << currentTime << endl;

	startTimeTM->tm_mday = day;
	startTimeTM->tm_mon = month - 1;
	startTimeTM->tm_year = year - 1900;
	startTimeTM->tm_hour = hr;
	startTimeTM->tm_min = min;

	cout << mktime(startTimeTM) << endl;

	delete startTimeTM;
	*/
	return 0;
}