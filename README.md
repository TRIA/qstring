# qstring
Storing 4 ("quad") null-teminated strings in one

Use pcQsNewQstring(string1, string2, string3, string4) to create a new qstring.  This will malloc() a single piece of memory to hold the 4 input strings, each terminated with a NUL.  Be sure to free() it when finished to avoid a memory leak.

Once you have a qstring, you can access its fields with pcQsGetPart (qstring, index), where index is 0, 1, 2, or 3, to return a char* pointer to the corresponding embedded NUL-terminated string.  (Note that accessing the 0'th string is the same as using the qstring name itself, so no operation is needed to access it.)

You can also equivalently use the macros qsSTRING0(x), qsSTRING1(x), qsSTRING2(x), or qsSTRING3(x).

You can concatenate the four strings embedded in a qstring using pcQsNewPrintableQstring (qstring_t oldqs, char delim), passing it an existing qstring and a delimiter character to use to separate the strings.  This returns a string allocated with malloc(), so free() it when finished to avoid a memory leak.

The naming convention is from FreeRTOS.
