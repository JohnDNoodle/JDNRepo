/*
 * UTCStamp_inline.h
 *
 *  Created on: 04.12.2015
 *      Author: JohnD_2
 */

#ifndef UTCSTAMP_INLINE_H_
#define UTCSTAMP_INLINE_H_


bool inline operator<(const UTCStamp &a, const UTCStamp &b)	//warum braucht man hier inline-modifier aber innerhalb der classenheader, außerhalb der eigentlichen klasse nicht?
{
	return a.getTimestamp()<b.getTimestamp();
};

bool inline operator>=(const UTCStamp &a, const UTCStamp &b)
{
	return !(a<b);
};

bool inline operator>(const UTCStamp &a, const UTCStamp &b)
{
	return b<a;
};

bool inline operator==(const UTCStamp &a, const UTCStamp &b)
{
	return (!(a<b) && !(a>b));
};

bool inline operator<=(const UTCStamp &a, const UTCStamp &b)
{
	return ((a==b) || (a<b));
};

bool inline operator!=(const UTCStamp &a, const UTCStamp &b)
{
	return !(a==b);
};

#endif /* UTCSTAMP_INLINE_H_ */
