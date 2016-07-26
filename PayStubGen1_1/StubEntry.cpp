#include "StubEntry.h"
#include <iostream>

//Create a StubEntry using current time values
using boost::gregorian::date;
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
StubEntry::StubEntry(string newStartTime, string newEndTime)
{
	try {
		if (newStartTime == "" || newEndTime == "") {
			*this = StubEntry();
		}
		else {
			startTime = time_from_string(newStartTime);
			endTime = time_from_string(newEndTime);
		}
		

	}
	catch (std::exception& e) {
		std::cout << "Exception Error: " << e.what() << std::endl;
	}
}


StubEntry::~StubEntry()
{}
