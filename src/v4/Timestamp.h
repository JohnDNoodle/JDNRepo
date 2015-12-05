/*
 * Timestamp.h
 *
 *  Created on: 15.12.2014
 *      Author: Tasin
 */

#ifndef TIMESTAMP_H_
#define TIMESTAMP_H_

#include "Time.h"
#include <ctime>

using namespace std;

class Date;

/*
 *  Konvertierklasse Timestamp
 *  Dient dazu einen Zeitstempel (Sekunden seit 1.1.1970) zu 
 *  erstellen bzw. zu konvertieren (lokale Zeit -> UTC-Zeit).
 *
 *  Timestamp(time_t):       Uebertraegt den lokalen Zeitstempel in die
 *                           Datenkomponente
 *  
 *  Timestamp(const Date &, const Time &t):
 *  						 Ermittelt aus dem Datum und der Uhrzeit
 *  						 den Zeitstempel (lokale Zeit)
 *
 *  operator()(false):       Gibt den in der Datenkomponente gesicherten
 *                           Zeitstempel (Lokalzeit) zurueck.
 *
 *  operator()(true):        Konvertiert den in der Datenkomponente 
 *                           gesicherten Zeitstempel in UTC-Zeit  
 *                           und uebergibt ihn an den Aufrufer.
 *
 */
class Timestamp
{
	time_t timestamp;

public:
	Timestamp(time_t t);
	Timestamp(const Date &d, const Time &t=0);
	time_t operator()(bool bUTC=false) const;
};

#endif /* TIMESTAMP_H_ */
