#include <iostream>
#include "View.h"
#include "Model.h"




using std::cout;
using std::endl;
using std::cin;


int main()
{
	Model* model = new Model();
//	model->init();
	
	delete model;
	
	/*
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

	*/


	
	return 0;
}