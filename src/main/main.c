#include "../mifunc/math.h"

int main (int argc, char *argv[]) {
    Function *f = newFunction("add", add);
    int a[3] = {1, 2, 3};
    int* s = (int*) f->call(3, (pointer) a);
    printf("Suma: %i\n", *s);
    free(s); // Because we not use callFunction, we need to free the result manually

    int b[3] = {4, 5, 6};
    printf("Suma: %i\n", *(int*) callFunction(f, 3, (pointer) b));
    freeFunction(f);
    return 0;
}