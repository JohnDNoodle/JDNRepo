/*
 * MString.h
 *
 *  Created on: 02.12.2015
 *      Author: JohnD_2
 */

#ifndef MSTRING_H_
#define MSTRING_H_

#define DEFAULTLEN 10

class MString {
public:
	explicit MString(unsigned int = DEFAULTLEN);
	MString(char , unsigned int = 1);
	MString(const char*);
	MString(const MString&);
	virtual ~MString();

	MString& operator=(const MString&);
	MString& operator+=(const MString&);
	char operator[](unsigned) const;
	bool operator==(const MString&) const;

	virtual void conOut() const;
	unsigned length() const {return len;};
	unsigned capacity() const {return maxlen;};

private:
	char *cp;
	unsigned len;
	unsigned maxlen;
};

MString operator+(const MString&, const MString&);

#endif /* MSTRING_H_ */
