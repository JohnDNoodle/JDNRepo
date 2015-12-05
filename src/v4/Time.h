/*
 * Time.h
 *
 *  Created on: 16.11.2014
 *      Author: Tasin
 */

#ifndef TIME_H_
#define TIME_H_

#include <iostream>
using namespace std;

#define	SECS_A_DAY	86400

class Time
{
	int sectime;
public:
	Time(int t=0);
	Time(int, int, int =0);

	virtual void displayTime(ostream &out =cout) const;
	virtual int getHour() const;
	int getMin() const;
	int getSec() const;

	int getSecondsOfDay() const { return sectime; }
	virtual ~Time() { };
};

// freie Funktion
ostream &operator<<(ostream &, const Time &);

#endif /* TIME_H_ */
