#include <stdio.h>
#include <stdlib.h>

typedef int *pointer;

typedef struct function {
    char *name;
    pointer (*call)(int argc, pointer argv);
    pointer result;
} Function;


Function *newFunction (char *name, pointer (*func)(int argc, pointer argv));
void freeFunction (Function *f);
pointer callFunction (Function *f, int argc, pointer argv);