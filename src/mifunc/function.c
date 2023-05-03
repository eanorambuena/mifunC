#include "function.h"

Function *newFunction (char *name, pointer (*func)(int argc, pointer argv)) {
    Function *f = calloc(1, sizeof(Function));
    f->name = name;
    f->call = func;
    f->result = NULL;
    return f;
}

void freeFunction (Function *f) {
    free(f->result);
    free(f);
}

pointer callFunction (Function *f, int argc, pointer argv) {
    f->result = f->call(argc, argv);
    return f->result;
}

