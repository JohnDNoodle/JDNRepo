/*
 * UTCStamp.h
 *
 *  Created on: 16.11.2014
 *      Author: Tasin
 */

#ifndef UTCSTAMP_H_
#define UTCSTAMP_H_


#include "Time.h"
#include "Date.h"

class UTCStamp
{
protected:
	time_t timestamp;

public:
	UTCStamp() { sync(); }
	UTCStamp(time_t t) : timestamp(t)
	{ if (timestamp<SECS_A_DAY/2)
		  timestamp=SECS_A_DAY/2;
	}
	UTCStamp(const Date &d, const Time &t=0);

	virtual struct tm createTMStruct() const;
	virtual time_t getTimestamp() const { return timestamp; }

	virtual void sync() { timestamp=time(NULL); }
	virtual void tickSecs(int seconds);
	virtual void tickHours(int hours);

	virtual Time getTime() const;
	virtual Date getDate() const;
	virtual void displayStamp(ostream &out=cout) const;

	virtual ~UTCStamp() { };

};

// freie Funktionen
//   Vergleichsoperatoren als inline Funktionen inkludieren

#include "UTCStamp_inline.h"

//   Ausgabe-Schiebeoperation
ostream &operator<<(ostream &out, const UTCStamp &stamp);

#endif /* UTCSTAMP_H_ */
