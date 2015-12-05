/*
 * v4_main.cpp
 *
 *  Created on: 16.11.2014
 *      Author: Tasin
 */
/*
#include "Time.h"
#include "Date.h"

int main(int argc, char *argv[])
{
	Time t1;
	Time t2(13,45,30);
	Time t3(25,65,0);
	Time t4(25,-3,0);

	Date d1(5,12,1970);
	Date d2(-10,30,1900);
	Date d3(40,-30,9000);
	Date d4(29,2,2000);
	Date d5(29,2,2100);

	cout << "Ausgabe t1: " << t1 << endl;
	cout << "Ausgabe t2: " << t2 << endl;
	cout << "Ausgabe t3: " << t3 << endl;
	cout << "Ausgabe t4: " << t4 << endl;
	cout << "Ausgabe temp: " << Time(1,35,35) << endl << endl;

	cout << "Ausgabe d1: " << d1 << endl;
	cout << "Ausgabe d2: " << d2 << endl;
	cout << "Ausgabe d3: " << d3 << endl;
	cout << "Ausgabe d4: " << d4 << endl;
	cout << "Ausgabe d5: " << d5 << endl;

	cout << endl << "Monatstest (max):" << endl;
	for (int mon=1; mon<=12; mon++)
	{
		Date(40,mon,2000).displayDate();
		if (mon % 6 == 0)
			cout << endl;
		else
			cout << ' ';
	}

	cout << endl << "Monatstest (min):" << endl;
	for (int mon=1; mon<=12; mon++)
	{
		Date(-50,mon,2000).displayDate();
		if (mon % 6 == 0)
			cout << endl;
		else
			cout << ' ';
	}

	cout << endl << "Schaltjahrtest:" << endl;
	for (int year=1991; year<=2005; year++)
	{
		Date(30,2,year).displayDate();
		if (year % 5 == 0)
			cout << endl;
		else
			cout << ' ';
	}

	return 0;
}

*/
