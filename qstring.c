//
//  qstring.c
//  qstring
//
//  Created by Steve Bunch on 10/26/22.
//

#include <stdlib.h>
#include <string.h>
#include "qstring.h"

char * pcQsGetPart(qstring_t qs, int index)
{
	for (; index>0; --index) {
		while (*qs++)
			;
		// qs points past the nul
	}
	return (qs);
}

qstring_t pcQsNewQstring (const char *a, const char *b, const char *c, const char *d)
{
	size_t lena = strlen(a), lenb = strlen(b), lenc = strlen(c), lend = strlen(d);
	size_t len = lena + lenb + lenc + lend + 4;
	qstring_t newq = (qstring_t)malloc(len);
	
	strcpy(newq,a);
	strcpy(&newq[lena+1],b);
	strcpy(&newq[lena+lenb+2],c);
	strcpy(&newq[lena+lenb+lenc+3],d);
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
	for (int i = 0, len = 0; i < 4; i++) {
		for (;(qs[len] = oldqs[len]); len++) {
		}
		// there is a null at oldqs[len]
		if (i != 3)
			qs[len] = delim;
		len++;
	}
	return (qs);
}
