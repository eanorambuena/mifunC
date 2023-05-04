#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define C(type) *(type*)

typedef int *pointer;

typedef struct function {
    char *name;
    pointer (*call)(int argc, pointer argv);
    pointer result;
} Function;


Function *newFunction (char *name, pointer (*func)(int argc, pointer argv));
void freeFunction (Function *f);
pointer callFunction (Function *f, int argc, pointer argv);

#define CALL(type, f, c, v) (C(type)callFunction((f), (c), (pointer) (v)))