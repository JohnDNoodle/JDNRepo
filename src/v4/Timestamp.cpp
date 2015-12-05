/*
 * Timestamp.cpp
 *
 *  Created on: 15.12.2014
 *      Author: Tasin
 */

#include "Timestamp.h"
#include "Date.h"

Timestamp::Timestamp(time_t t) : timestamp(t)
{
}

Timestamp::Timestamp(const Date &d, const Time &t)
{
	struct tm check={0};
	check.tm_mday=d.getDay();
	check.tm_mon=d.getMonth()-1;
	check.tm_year=d.getYear()-1900;
	check.tm_hour=t.getHour();
	check.tm_min=t.getMin();
	check.tm_sec=t.getSec();
	check.tm_isdst=-1;
	timestamp=mktime(&check);

}

time_t Timestamp::operator()(bool bUTC) const
{
	time_t korr=0;
	if (bUTC)
	{
		time_t ts=(timestamp<SECS_A_DAY/2) ? SECS_A_DAY/2 : timestamp ;
		struct tm localinfo=*localtime(&ts);
		struct tm utcinfo=*gmtime(&ts);
		korr=ts-mktime(&utcinfo);
		if (localinfo.tm_isdst==1)
			korr+=3600;
	}
	return timestamp+korr;
}
