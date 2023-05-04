#include "../mifunc/math.h"

int main (int argc, char *argv[]) {
    Function *f = newFunction("add", add);
    int a[3] = {1, 2, 3};

    printf("Suma: %i\n", CALL(int, f, 3, a));

    freeFunction(f);
    return 0;
}