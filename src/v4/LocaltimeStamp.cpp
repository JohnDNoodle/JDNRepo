/*
 * LocaltimeStamp.cpp
 *
 *  Created on: 04.12.2015
 *      Author: JohnD_2
 */

#include "LocaltimeStamp.h"

LocaltimeStamp::LocaltimeStamp()
{
	UTCStamp::sync();
	calcTimeZone();
}

LocaltimeStamp::LocaltimeStamp(time_t t) : UTCStamp(t)
{
	calcTimeZone();
}

LocaltimeStamp::LocaltimeStamp(const Date &d, const Time &t)
{
	Timestamp ts(d, t);
	timestamp = ts(false);
	calcTimeZone();
	if (timestamp < (SECS_A_DAY/2))
		timestamp = SECS_A_DAY/2;
}

LocaltimeStamp::LocaltimeStamp(const UTCStamp &u)
{
	timestamp = u.getTimestamp();
	calcTimeZone();
}

void LocaltimeStamp::calcTimeZone()
{
	int korr = Timestamp(timestamp)(true) - Timestamp(timestamp)(false);
	hoursTZ = korr/3600.0;
}

struct tm LocaltimeStamp::createTMStruct() const
{
	return *localtime(&timestamp);
}

void LocaltimeStamp::tickSecs(int seconds)
{
	UTCStamp::tickSecs(seconds);
	calcTimeZone();
}

void LocaltimeStamp::tickHours(int hours)
{
	UTCStamp::tickHours(hours);
	calcTimeZone();
}
