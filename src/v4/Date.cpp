/*
 * Date.cpp
 *
 *  Created on: 04.12.2015
 *      Author: JohnD_2
 */

#include "Date.h"
#include <iomanip>
#include <ios>

Date::Date(int d, int m, int y)
{
	if (y < 1970)
	{
		year = 1970;
	}
	else if (y < 4000)
	{
		year = y;
	}
	else
		year = 3999;

	if (m < 1)
	{
		month = 1;
	}
	else if (m < 13)
	{
		month = m;
	}
	else
		month = 12;

	int maxDays = -1;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		maxDays = 31;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		maxDays = 30;
	}
	else
	{
		maxDays = 28;
		if (isLeapYear())
			maxDays =29;
	}

	if (d < 1)
	{
		day = 1;
	}
	else if (d < maxDays + 1)
	{
		day = d;
	}
	else
		day = maxDays;

}

void Date::displayDate(ostream &out) const
{
	char prev;

	out << setw(2) << day << '.';
	prev= out.fill('0');
	out << setw(2) << month << '.';
	out << setw(4) << year << setfill(prev);
}

ostream &operator<<(ostream & stream, const Date & date)
{
	date.displayDate(stream);
	return stream;
}
/*
int main()
{
	Date d1(0,0,0);
	Date d2(4000,4000,4000);
	cout << d1;
	cerr << d2;
}
*/
