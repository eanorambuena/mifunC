#include "math.h"

pointer add (int argc, pointer argv) {
    int *sum = calloc(1, sizeof(int));
    for (int i = 0; i < argc; i++) {
        *sum += (int) argv[i];
    }
    return (pointer) sum;
}