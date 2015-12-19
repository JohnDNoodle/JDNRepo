// versuch5.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "Assembly.h"
#include "Load.h"
#include "Load2.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	try
	{
		Load swischerVorne("M1", 38.0, 0.6);
		Load spritzPumpe("P1", 53.0, 0.43);
		Load swischerHinten("M2", 32.0, 0.65);

		Assembly komplett("Anlage: komplett");
		Assembly vorne("Anlage: vorne"), hinten("Anlage: hinten");

		/* Aufbau der Einzel-Assemblies */
		vorne.addComponent(&swischerVorne);
		vorne.addComponent(&spritzPumpe);
		hinten.addComponent(&swischerHinten);
		hinten.addComponent(&spritzPumpe);

		/* Aufbau des komplett-Assemblys */
		komplett.addComponent(&vorne); komplett.addComponent(&hinten);
		cout << "Gesamtleistung: " << komplett.consumption() << " W" << endl;

		Component::Collection coll;
		komplett.collectAllLoads(coll);
		/* Ausgabe der Collection */
		cout << "Unsortierte Ausgabe:" << endl;
		cout << coll << endl;

        /* Hier folgt Ihre Ergaenzung Teil 3 */
		LoadSet set = transferCollection(coll);
		cout << "Sortierte Ausgabe:" << endl;
		cout << set << endl;


	}
	catch (const exception &ex)
	{
		cerr << "Exception: " << ex.what() << endl;
	}
	catch (...)
	{
		cerr << "Unbekannte Exception!" << endl;
	}
	return 0;
}

