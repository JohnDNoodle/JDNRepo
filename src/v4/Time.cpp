/*
 * Time.cpp
 *
 *  Created on: 04.12.2015
 *      Author: JohnD_2
 */

#include "Time.h"
#include <iomanip>
#include <ios>

using namespace std;

Time::Time(int sec)
{
	if (sec < 0)
	{
		sectime = 0;
	}
	else if (sec < SECS_A_DAY)
	{
		sectime = sec;
	}
	else
		sectime = SECS_A_DAY - 1;
}

Time::Time(int h, int m, int s)
{
	if (h < 0)
	{
		sectime = 0;
	}
	else if (h < 24)
	{
		sectime = h * 3600;
	}
	else
		sectime = 23 * 3600;

	if (m < 0)
	{
		sectime += 0;
	}
	else if (m < 60)
	{
		sectime += m * 60;
	}
	else
		sectime += 59 * 60;

	if (s < 0)
	{
		sectime += 0;
	}
	else if (s < 60)
	{
		sectime += s;
	}
	else
		sectime += 59 ;
}

int Time::getHour() const
{
	return sectime/3600;
}
int Time::getMin()const
{
	return (sectime%3600)/60;
}
int Time::getSec() const
{
	return (sectime%3600)%60;
}

void Time::displayTime(ostream &out) const
{
	out << setfill('0') << setw(2) << getHour() << ':';
	out << setfill('0') << setw(2) << getMin() << ':';
	out << setfill('0') << setw(2) << getSec();

}

ostream &operator<<(ostream & stream, const Time & daySeconds)
{
	daySeconds.displayTime(stream);
	return stream;
}

/*
int main()
{
	Time t1 = SECS_A_DAY +10;
	Time t2(25, 20, 30);
	cout << t1;
	cout << t2;
}
*/


