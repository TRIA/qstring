//
//  main.c
//  qstring
//
//  Created by Steve Bunch on 10/26/22.
//

#include <stdlib.h>
#include <stdio.h>
#include "qstring.h"

int main(int argc, const char * argv[]) {
	qstring_t s = pcQsNewQstring ("a", "bc", "def", "ghij");
	qstring_t s2 = pcQsNewQstring ("", "", "", "x"), s3;
	
	printf ("should be 'abcdefghij' '%s%s%s%s'\n",
			qsSTRING0(s), qsSTRING1(s), qsSTRING2(s), qsSTRING3(s));
	s3 = pcQsNewPrintableQstring (s, '|');
	printf ("Should be 'a|bc|def|ghij' was '%s'\n", s3);
	free (s3);
	s3 = pcQsNewPrintableQstring (s2, '|');
	printf ("Should be '|||x' was '%s'\n", s3);
	free(s3);
	
	return 0;
}

