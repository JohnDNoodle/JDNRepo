/*
 * MString.cpp
 *
 *  Created on: 02.12.2015
 *      Author: JohnD_2
 */

#include "MString.h"
#include <cstring>
#include <iostream>
#include <cstdlib>



using namespace std;

MString::MString(unsigned int cLen)
{
	len = 0;
	maxlen = cLen;
	cp = new char[maxlen];
	if(cp == NULL)
	{
		cerr << "Error with string allocation!" << endl;
		exit(1);
	}
}

MString::MString(const char *string)
{
	if(string != NULL)
	{
		len = strlen(string);
		maxlen = len;
		cp = new char[maxlen];
		if(cp == NULL)
		{
			cerr << "Error with string allocation!" << endl;
			exit(1);
		}
		strncpy(cp, string, maxlen);
	}
	else
	{
		len = 0;
		maxlen = 0;
		cp = NULL;
		cerr << "Given string is Nullpointer!" << endl;
	}
}

MString::MString(const char c, unsigned cLen)
{
	len = 1;
	if(cLen > 0)
	{
		maxlen = cLen;
	}
	else
	{
		maxlen = len;
	}
	cp = new char[maxlen];
	if(cp == NULL)
	{
		cerr << "Error with string allocation!" << endl;
		exit(1);
	}
	cp[0] = c;
}

MString::MString(const MString &copy)
{
	len = copy.len;
	maxlen = copy.maxlen;
	cp = new char[maxlen];
	if(cp == NULL)
	{
		cerr << "Error with string allocation!" << endl;
		exit(1);
	}
	memcpy(cp, copy.cp, maxlen * sizeof(char));
}

MString::~MString()
{
	delete []cp;
}

void MString::conOut() const
{
	if (len > 0)
	{
		for(unsigned i = 0; i < len; i++)
			cout << cp[i];
	}
}

MString& MString::operator=(const MString& zstring)
{
	if(this != &zstring)
	{
		len = zstring.len;
		if(maxlen < zstring.maxlen)
		{
			delete [] cp;
			maxlen = zstring.maxlen;
			cp = new char[maxlen];
		}
		memcpy(cp, zstring.cp, len * sizeof(char));
	}
	return *this;
}
MString& MString::operator+=(const MString &pstring)
{
	if((len + pstring.len) > maxlen)
	{
		maxlen = len + pstring.len;
		char *tempArr = new char[maxlen];
		memcpy(tempArr, cp, len * sizeof(char));
		delete [] cp;
		cp = tempArr;
	}
	memcpy(cp+len, pstring.cp, pstring.len*sizeof(char));
	len+=pstring.len;
	return *this;
}
char MString::operator[](unsigned i) const
{
	char ret = 0;
	if(i < len)
	{
		ret = cp[i];
	}
	else
	{
		cerr << "Index not in range!" << endl;
		exit(EXIT_FAILURE);
	}
	return ret;
}
bool MString::operator==(const MString& cstring) const
{
	bool ret = false;
	if(len == cstring.len)
	{
		ret = true;
		for(unsigned i = 0; i < len && ret; i++)
		{
			if(cp[i] != cstring.cp[i])
			{
				ret = false;

			}
		}
	}
	return ret;
}

MString operator+(const MString& a, const MString& b)
{
	MString ret = a;
	ret+=b;
	return ret;
}
