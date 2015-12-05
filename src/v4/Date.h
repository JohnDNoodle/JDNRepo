/*
 * Date.h
 *
 *  Created on: 20.11.2014
 *      Author: Tasin
 */

#ifndef DATE_H_
#define DATE_H_

#include <ctime>
#include <iostream>

using namespace std;

class Date
{
	int day, month, year;

public:
	Date(int d=1, int m=1, int y=1970);

	bool isLeapYear() const
	{
		return (year % 400==0) - (year % 100==0) +
				(year % 4==0);
	}
	virtual int getDay() const { return day; }
	virtual int getMonth() const { return month; }
	virtual int getYear() const { return year; }

	virtual void displayDate(ostream &out=cout) const;
	virtual ~Date() { };
};

// freie Funktion
ostream &operator<<(ostream &, const Date &);

#endif /* DATE_H_ */
