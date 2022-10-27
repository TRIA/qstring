//
//  qstring.h
//  qstring
//
//  Created by Steve Bunch on 10/26/22.
//

#ifndef qstring_h
#define qstring_h

#define qsSTRING0(x)	(x)
#define qsSTRING1(x)	pcQsGetPart((x),1)
#define qsSTRING2(x)	pcQsGetPart((x),2)
#define qsSTRING3(x)	pcQsGetPart((x),3)
#define qsDELIMITER		'|'

typedef char * qstring_t;

char * pcQsGetPart(qstring_t qs, int index);
qstring_t pcQsNewQstring (const char *a, const char *b, const char *c, const char *d);
qstring_t pcQsNewPrintableQstring (qstring_t oldqs, char delim);

#endif /* qstring_h */
