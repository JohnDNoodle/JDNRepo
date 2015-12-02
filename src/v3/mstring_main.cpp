//mstring_main.cpp

#include "MString.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

void format(const MString &Ls);
template <typename T> void check(const char *mess, T expr, T result)
{
	if (expr!=result)
	{
		ios::fmtflags flags=cout.flags(ios::boolalpha);
		cout << endl << ">>> " << mess << endl;
		cout << ">>> Wert soll " << result << " sein." << endl;
		cout.flags(flags);
		exit(-1);
	}
}


int main()  {

	unsigned int uiL=40;
	MString a("Krautsalat");
	const MString &acr=a;
	MString b = "Blumentopferde";
	MString c ='Q';
	MString d(uiL);
	MString e = a;
	MString f('x', 0);
	MString g(reinterpret_cast<const char *>(NULL));

	acr.conOut(); format(acr);
	b.conOut();	format(b);
	c.conOut();	format(c);
	d.conOut();	format(d);
	e.conOut();	format(e);
	check("&a==&e", &a==&e, false);
	f.conOut();	format(f);
	check("f.capacity()", f.capacity(), 1u);
	check("f.length()", f.length(), 1u);
	g.conOut();	format(g);
	check("g.capacity()", g.capacity(), 0u);
	check("g.length()", g.length(), 0u);


	//Zu Teilaufgabe b

	MString sonder=MString("hallo");
	sonder.conOut();	format(sonder);
	check("sonder -> sonder.length(): ", sonder.length(), 5u);
	check("sonder -> sonder.capacity(): ", sonder.capacity(), 5u);

	cout << "Zuweisung d=b :   ";
	d=b;
	d.conOut();	format(d);
	
	d+=a;
	cout << "Operator d+=a :   ";
	d.conOut();	format(d);

	cout << "Operator d+=d :   ";
	d+=d;
	d.conOut();	format(d);
	check("d+=d -> d.length(): ", d.length(), 48u);
	check("d+=d -> d.capacity(): ", d.capacity(), 48u);

	cout << "Operator d[]  :   ";
	for(unsigned i= 0 ; i < d.length(); i++) {
		cout << d[i];
	}
	cout << endl;

	cout << "Operator a[]  :   ";
	for(unsigned i= 0 ; i < acr.length(); i++) {
		cout << acr[i];
	}
	cout << endl;

	cout << "Operator sonder[]  :   ";
	sonder+=MString('\0');
	sonder+=MString("\3");
	sonder+=MString('\0');
	sonder+=MString('\0');
	check("sonder[5]                : ", sonder[5], '\0');
	//check("sonder[6]                : ", sonder[6], '\3');
	check("sonder[7]                : ", sonder[7], '\0');
	check("sonder[8]                : ", sonder[8], '\0');
	check("sonder -> sonder.length(): ", sonder.length(), 9u);
	check("sonder -> sonder.capacity(): ", sonder.capacity(), 9u);
	for(unsigned i= 0 ; i < sonder.length(); i++) {
		cout << sonder[i];
	}
	cout << endl;

	cout << endl << "Vergleiche:" << endl;
	cout << "Vergleich e==a: " << (e==a) << endl;
	check("Vergleich e==a: ", e==a, true);
	cout << "Vergleich acr==a: " << (acr==a) << endl;
	check("Vergleich acr==a: ", acr==a, true);
	cout << "Vergleich zweier Leerstrings: " << (MString(static_cast<unsigned int>(0))==MString("")) << endl;
	check("Vergleich zweier Leerstrings: ", MString(static_cast<unsigned int>(0))==MString(""), true);
	cout << "Vergleich \"hallo\"==\"hallo\\0\\3\\0\\0du da\": " << (MString("hallo")==sonder+"du da") << endl;
	check("Vergleich \"hallo\"==\"hallo\\0\\3\\0\\0du da\": ", MString("hallo")==sonder+"du da", false);
	cout << "Vergleich \"hallo\\0\\3\\0\\0du da\"==\"hallo\": " << (sonder+"du da"==MString("hallo")) << endl;
	check("Vergleich \"hallo\\0\\3\\0\\0du da\"==\"hallo\": ", sonder+"du da"==MString("hallo"), false);
	cout << "Vergleich \"hallo\\0\\3\\0\\0\" mit sich: " << (sonder==sonder) << endl;
	check("Vergleich \"hallo\\0\\3\\0\\0\" mit sich: ", sonder==sonder, true);
	cout << "Vergleich \"hallo\"==\"huela\": " << (MString("hallo")==MString("huela")) << endl;
	check("Vergleich \"hallo\"==\"huela\": ", MString("hallo")==MString("huela"), false);
	cout << "Vergleich \"hallo\"==\"Thilo\": " << (MString("hallo")==MString("Thilo")) << endl;
	check("Vergleich \"hallo\"==\"Thilo\": ", MString("hallo")==MString("Thilo"), false);
	cout << endl;

	cout << endl << "Zuweisung:" << endl;
	d=a+b;
	cout << "Operator Addition d=a+b:   ";
	d.conOut();	format(d);
	if (d.capacity()>24)
		check("d=a+b -> d.capacity(): ", d.capacity(), 48u);
	else
		check("d=a+b -> d.capacity(): ", d.capacity(), 24u);
	
	char  mstr[40];
	strcpy (mstr,"Ja_so_was!!");

	d =  b  = a;
	check("d=b=a -> d.length()==a.length(): ", d.length()==a.length(), true);

	d = "Ja_so_was!!";
	cout << "Zuweisung d=\"Ja_so_was!!\":   ";
	d.conOut();	format(d);

	d = 'N';
	cout << "Zuweisung d='N':   ";
	d.conOut();	format(d);
	check("d=\'N\' -> d.length(): ", d.length(), 1u);
	if (d.capacity()>1)
		check("d=\'N\' -> d.capacity(): ", d.capacity(), 48u);
	else
		check("d=\'N\' -> d.capacity(): ", d.capacity(), 1u);

	cout << endl << "Konkatenieren:" << endl;
	d += "Ja_so_was!!";
	cout << "Verlaengern um  \"Ja_so_was!!\":   ";
	d.conOut();	format(d);
	check("d += \"Ja_so_was!!\" -> d.length(): ", d.length(), 12u);

	d += 'X';
	cout << "Verlaengern um  'X':   ";
	d.conOut();	format(d);
	check("d += \'X\' -> d.length(): ", d.length(), 13u);

	d = a + "Ja_so_was!!";
	cout << "Anhaengen von   \"Ja_so_was!!\":   ";
	d.conOut();	format(d);

	d = d + "Ja_so_was!!";
	cout << "Anhaengen von   \"Ja_so_was!!\":   ";
	d.conOut();	format(d);

	d = "Ja_so_was_kann_doch_nicht_sein_oder?!!" + a ;
	cout << "Anhaengen vorne \"Ja_so_was_kann_doch_nicht_sein_oder?!!\":";
	cout << endl << "                 ";
	d.conOut();	format(d);
	check(" -> d.capacity(): ", d.capacity(), 48u);

	e = MString('K', 10) + "rautsalat" + '5';
	cout << "2x operator+():       ";
	e.conOut();	format(e);
	check("Krautsalat5 -> e.length(): ", e.length(), 11u);
	check("Krautsalat5 -> e.capacity(): ", e.capacity(), 11u);

	f = '7' + a + '7';
	cout << "MString \'7\'+a+\'7\':   ";
	f.conOut();	format(f);
	check("f.length(): ", f.length(), 12u);
	check("f.capacity(): ", f.capacity(), 12u);

	return EXIT_SUCCESS;
}

void format(const MString &Ls) {
	cout << " (" << Ls.length() << "|" 
		 << Ls.capacity() << ")" << endl;
}

