/*
 * LocaltimeStamp.h
 *
 *  Created on: 04.12.2015
 *      Author: JohnD_2
 */

#ifndef LOCALTIMESTAMP_H_
#define LOCALTIMESTAMP_H_

#include "UTCStamp.h"
#include "Timestamp.h"

class LocaltimeStamp: public UTCStamp
{
private:
	double hoursTZ;
public:
	LocaltimeStamp();
	LocaltimeStamp(time_t t);
	LocaltimeStamp(const Date &d, const Time &t=0);
	LocaltimeStamp(const UTCStamp &);

	double getTimeZone() { return hoursTZ;};
	virtual void calcTimeZone();
	virtual struct tm createTMStruct() const;

	virtual void tickSecs(int seconds);
	virtual void tickHours(int hours);
	virtual void sync();

	virtual ~LocaltimeStamp() {};
};

#endif /* LOCALTIMESTAMP_H_ */
