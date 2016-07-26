#pragma once
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/access.hpp>
#include <boost/date_time/gregorian/greg_serialize.hpp>
#include <boost/date_time/posix_time/time_serialize.hpp>
#include <string>

using namespace boost::posix_time;
using namespace boost::gregorian;

using std::string;
typedef unsigned int unint;

class StubEntry
{
	ptime startTime;
	ptime endTime;
	double rate;
public:
	friend class boost::serialization::access;
	StubEntry();
	StubEntry(string, string, double);
	~StubEntry();

	inline ptime getStartTime() { return startTime; }
	inline ptime getEndTime() { return endTime; }

	static bool validateTimeString(string inputString);
	static string generateTimeString(unint date, unint month, unint year, unint hr, unint min);
	template<class Archive>
	void serialize (Archive &ar, const unsigned int version) {
		cout << "inside the serialize function";
		ar & startTime;
		ar & endTime;
	}
};

