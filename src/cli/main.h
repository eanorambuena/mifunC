#include <string.h>
#include <ctype.h>
#include "../mifunc/math.h"

bool string_equals (char* string1, char* string2);
char *strstrip (char *s);
void strslice (const char * str, char * buffer, size_t start, size_t end);
char *scan_phrase ();
int main (int argc, char* argv[]);