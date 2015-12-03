/*
 * MString.cpp
 *
 *  Created on: 02.12.2015
 *      Author: JohnD_2
 */

#include "MString.h"
#include <cstring>
#include <iostream>



using namespace std;

MString::MString(unsigned int cLen)
{
	len = 0;
	maxlen = cLen;
	cp = new char[maxlen];
}

MString::MString(const char *string)
{
	if(string != NULL)
	{
		len = strlen(string);
		maxlen = len;
		cp = new char[maxlen];
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
	cp[0] = c;
}

MString::MString(const MString &copy)
{
	len = copy.len;
	maxlen = copy.maxlen;
	cp = new char[maxlen];
	strncpy(cp, copy.cp, maxlen);
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
		cout << endl;
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
		strncpy(cp, zstring.cp, len);
	}
	return *this;
}
MString& MString::operator+=(const MString &pstring)
{
	if((len + pstring.len) > maxlen)
	{
		char tempArr[len];
		memcpy(tempArr, cp, len * sizeof(char));
		delete [] cp;
		maxlen = len + pstring.len;
		cp = new char[maxlen];
		memcpy(cp, tempArr, len*sizeof(char));
		delete [] tempArr;
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
	}
	return ret;
}
bool MString::operator==(const MString& cstring) const
{
	bool ret = false;
	if(len == cstring.len)
	{
		ret = true;
		for(unsigned i = 0; i < len; i++)
		{
			if(cp[i] != cstring.cp[i])
			{
				ret = false;
				break;
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
