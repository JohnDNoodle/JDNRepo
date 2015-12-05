/*
 * v4b_main.cpp
 *
 *  Created on: 16.11.2014
 *      Author: Tasin
 */

#include "UTCStamp.h"
#include "LocaltimeStamp.h"

int main()
{
	UTCStamp actual;
	LocaltimeStamp actualLocal;
	UTCStamp zeroUTC(0);
	LocaltimeStamp zeroLocal(zeroUTC);

	cout << "Erster moeglicher Zeitstempel: " << zeroLocal << " (" << zeroLocal.getTimeZone() << " h)" << endl;
	cout << "                               " << zeroUTC << " UTC" <<
			endl << endl;

	cout << "Aktueller Zeitstempel: " << actualLocal.getTimestamp() << " = ";
	cout << actualLocal << " (" << actualLocal.getTimeZone() << " h)" << endl;
	cout << "                       " << UTCStamp(actualLocal).getTimestamp() << " = ";
	cout << UTCStamp(actualLocal) << " UTC" << endl;

	actualLocal=LocaltimeStamp(Date(12,6,2014));
	actual=UTCStamp(Date(12,6,2014));

	cout << endl << "Zeitstempel ueber Datums-/Zeitangaben:" << endl;
	cout << "12.06.2014 0:00 Lokal: " << actualLocal.getTimestamp() << " = ";
	cout << actualLocal << " (" << actualLocal.getTimeZone() << " h)" << endl;
	cout << "12.06.2014 0:00   UTC: " << actual.getTimestamp() << " = ";
	cout << actual << " UTC" << endl;


	actualLocal=LocaltimeStamp(Date(12,12,2014), Time(1,0,0));
	actual=UTCStamp(Date(12,12,2014));

	cout << "12.12.2014 1:00 Lokal: " << actualLocal.getTimestamp() << " = ";
	cout << actualLocal << " (" << actualLocal.getTimeZone() << " h)" << endl;
	cout << "12.12.2014 0:00   UTC: " << actual.getTimestamp() << " = ";
	cout << actual << " UTC" << endl;

	cout << endl << "Konstruktion ueber Sekunden:" << endl;
	cout << "1418342400 s: " << LocaltimeStamp(1418342400) << " Local" << endl;
	cout << "1418342400 s: " << UTCStamp(1418342400) << "   UTC" << endl;

	cout << endl << "Simulation des Wechsels Winter- zu Sommerzeit:" << endl;
	actualLocal=LocaltimeStamp(Date(30,3,2014), Time(1,0,0));
	actual=actualLocal;
	for (int hours=0; hours<3; hours++)
	{
		cout << "Zeitstempel: " << actualLocal.getTimestamp() << " = ";
		cout << actualLocal.getDate() << " - " << actualLocal.getTime() <<
			" (" << actualLocal.getTimeZone() << " h)" << endl;
		cout << "             " << actual.getTimestamp() << " = ";
		cout << actual.getDate() << " - " << actual.getTime() <<
				" UTC" << endl;
		actualLocal.tickHours(1);
		actual.tickHours(1);
	}

	cout << endl << "Simulation des Wechsels Sommer- zu Winterzeit:" << endl;
	actualLocal=LocaltimeStamp(Date(26,10,2014), Time(1,0,0));
	for (int hours=0; hours<3; hours++)
	{
		actual=actualLocal;
		cout << "Zeitstempel: " << actualLocal.getTimestamp() << " = ";
		cout << actualLocal.getDate() << " - " << actualLocal.getTime() <<
			" (" << actualLocal.getTimeZone() << " h)" << endl;
		cout << "             " << actual.getTimestamp() << " = ";
		cout << actual.getDate() << " - " << actual.getTime() <<
				" UTC" << endl;
		actualLocal.tickHours(1);
	}

	Date d1(1,1,2014), d2(29,12,2014);
	UTCStamp utc1(d2);
	LocaltimeStamp local1(d2);

	cout << "Vergleiche:" << endl;
	cout << d1 << " < " << d2 << " => " << (d1<d2) << endl;
	cout << d1 << " != " << d2 << " => " << (d1!=d2) << endl;
	cout << d1 << " != " << d1 << " => " << (d1!=d1) << endl;
	cout << d1 << " > " << d1 << " => " << (d1>d1) << endl;
	cout << utc1 << " (UTC)       == " << d2 << " => " << (utc1==d2) << endl;
	cout << local1 << " (LocalTime) == " << d2 << " => " << (local1==d2) << endl;
	cout << local1 << " (LocalTime) <  " << d2 << " => " << (local1<d2) << endl;

	return 0;
}

