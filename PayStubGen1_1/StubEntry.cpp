#include "StubEntry.h"
#include <iostream>
#include <string>

//Create a StubEntry using current time values
using boost::gregorian::date;
using std::stringstream;
StubEntry::StubEntry()
{
	try {
		startTime = second_clock::local_time();
		endTime = startTime + seconds(1);
	}
	catch (std::exception& e) {
		std::cout << "Exception Error: " << e.what() << std::endl;
	}
}


//Create a StubEntry using two string values containing the startTime and the endTime
StubEntry::StubEntry(string newStartTime, string newEndTime, double newRate)
{
	try {
		if (newStartTime == "" || newEndTime == "") {
			*this = StubEntry();
		}
		else {
			startTime = time_from_string(newStartTime);
			endTime = time_from_string(newEndTime);
			rate = newRate;
		}
		

	}
	catch (std::exception& e) {
		std::cout << "Exception Error: " << e.what() << std::endl;
	}
}


StubEntry::~StubEntry()
{}

bool StubEntry::validateTimeString(string inputString)
{
	try {
		ptime testPTime = time_from_string(inputString);
	}
	catch (std::exception &e) {
		std::cerr << "Bad Input Received! Error: " << e.what() << std::endl;
		return false;
	}
	return true;
}

string StubEntry::generateTimeString(unint date, unint month, unint year, unint hr, unint min)
{
	string finalResult = "";
	
	finalResult += std::to_string(year);
	finalResult += "-";
	finalResult += std::to_string(month);
	finalResult += "-";
	finalResult += std::to_string(date);
	finalResult += " ";
	finalResult += std::to_string(hr);
	finalResult += ":";
	finalResult += std::to_string(min);

	std::cout << finalResult << std::endl;
	if (validateTimeString(finalResult))
	{
		return finalResult;
	}
	else {
		return "ERR";
	}
}
