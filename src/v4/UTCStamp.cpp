/*
 * UTCStamp.cpp
 *
 *  Created on: 04.12.2015
 *      Author: JohnD_2
 */

#include "UTCStamp.h"
#include "Timestamp.h"
#include <ctime>

UTCStamp::UTCStamp(const Date &d, const Time &t)
{
	Timestamp ts(d, t);
	timestamp = ts(true);
	if (timestamp < (SECS_A_DAY/2))
		timestamp = SECS_A_DAY/2;
}

struct tm UTCStamp::createTMStruct() const
{
	return *gmtime(&timestamp);
}

Time UTCStamp::getTime() const
{
	struct tm tStamp = createTMStruct();
	return Time(tStamp.tm_hour, tStamp.tm_min, tStamp.tm_sec);
}
Date UTCStamp::getDate() const
{
	struct tm tStamp = createTMStruct();
	return Date(tStamp.tm_mday, tStamp.tm_mon + 1, tStamp.tm_year + 1900);
}

void UTCStamp::tickSecs(int seconds)
{

	timestamp += seconds;
	if (timestamp < (SECS_A_DAY/2))
		timestamp = SECS_A_DAY/2;


}
void UTCStamp::tickHours(int hours)
{

	timestamp += hours*3600;
	if (timestamp < (SECS_A_DAY/2))
		timestamp = SECS_A_DAY/2;

}

void UTCStamp::displayStamp(ostream &out) const
{
	Time t = getTime();
	Date d = getDate();
	out << d << " - " << t;
}

ostream &operator<<(ostream &out, const UTCStamp &stamp)
{
	stamp.displayStamp(out);
	return out;
}
