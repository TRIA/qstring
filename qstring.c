//
//  qstring.c
//  qstring
//
//  Created by Steve Bunch on 10/26/22.
//

#include <stdlib.h>
#include <string.h>
#include "qstring.h"

char * pcQsGetPart(qstring_t qs, unsigned index)
{
	if (index > 3)
		return (NULL);
	for (; index>0; --index) {
		while (*qs++)
			;
		// qs points past the nul
	}
	return (qs);
}

qstring_t pcQsNewQstring (const char *a, const char *b, const char *c, const char *d)
{
	size_t len = strlen(a)+strlen(b)+strlen(c)+strlen(d);
	qstring_t newq = (qstring_t)malloc(len + 4);
	qstring_t tq = newq;
	
	if (newq) {
		while ((*tq++ = *a++)) ;
		while ((*tq++ = *b++)) ;
		while ((*tq++ = *c++)) ;
		while ((*tq++ = *d++)) ;
	}
	return (newq);
}

qstring_t pcQsNewPrintableQstring (qstring_t oldqs, char delim)
{
	size_t len = 0;
	qstring_t qs;
	
	// dry run, just counting length of oldqs and its NULs
	for (int i = 0; i < 4; i++) {
		while (oldqs[len++])
			;
	}
	
	qs = malloc(len);
	// this time with copying
	if (qs) {
		len = 0;
		for (int i = 0; i < 4; i++) {
			for (;(qs[len] = oldqs[len]); len++) {
			}
			// there is a null at oldqs[len]
			if (i != 3)
				qs[len] = delim;
			len++;
		}
	}
	return (qs);
}
