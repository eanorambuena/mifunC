# MifunC

The official C implementation of the Minimal Function Notation (Mifun)

## Benefits

- **Minimal**: The MifunC library is a single header file with no dependencies.
- **Simple**: The MifunC library is easy to use and understand.

## Examples

```c
#include "../mifunc/math.h"

int main (int argc, char *argv[]) {
    // Create function
    Function *f = newFunction("add", add);

    // Create array
    int a[3] = {1, 2, 3};

    // Example 1
    printf("Suma: %i\n", CALL(int, f, 3, a));

    // Free function f
    freeFunction(f);
    return 0;
}
```

```c
#include "../mifunc/math.h"

int main (int argc, char *argv[]) {
    // Create function
    Function *f = newFunction("add", add);

    // Create array
    int a[3] = {1, 2, 3};

    // Example 2
    printf("Suma: %i\n", C(int) callFunction(f, 3, (pointer) a));

    // Free function f
    freeFunction(f);
    return 0;
}
```

```c
#include "../mifunc/math.h"

int main (int argc, char *argv[]) {
    // Create function
    Function *f = newFunction("add", add);

    // Create array
    int a[3] = {1, 2, 3};

    // Example 3
    printf("Suma: %i\n", *(int*) callFunction(f, 3, (pointer) a));

    // Free function f
    freeFunction(f);
    return 0;
}
```

```c
#include "../mifunc/math.h"

int main (int argc, char *argv[]) {
    // Create function
    Function *f = newFunction("add", add);

    // Create array
    int a[3] = {1, 2, 3};

    // Example 4
    int* result = (int*) f->call(3, (pointer) a);
    printf("Suma: %i\n", *result);
    free(result); // Because we not use callFunction, we need to free the result manually

    // Free function f
    freeFunction(f);
    return 0;
}
```