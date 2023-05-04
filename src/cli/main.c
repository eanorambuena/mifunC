#include "main.h"

bool string_equals (char* string1, char* string2) {
    return !strcmp(string1, string2);
}

char *strstrip (char *s) { // From linux kernel: https://stackoverflow.com/questions/352055/best-algorithm-to-strip-leading-and-trailing-spaces-in-c
    size_t size;
    char *end;
    size = strlen(s);
    if (!size) return s;
    end = s + size - 1;
    while (end >= s && isspace(*end)) end--;
    *(end + 1) = '\0';
    while (*s && isspace(*s)) s++;
    return s;
}

void strslice (const char * str, char * buffer, size_t start, size_t end) { // From https://stackoverflow.com/questions/26620388/c-substrings-c-string-slicing
    size_t j = 0;
    for ( size_t i = start; i <= end; ++i ) {
        buffer[j++] = str[i];
    }
    buffer[j] = 0;
}

char *scan_phrase () {
    bool run = true;
    char *phrase = calloc(100, sizeof(char));
    while (run) {
        char *word = calloc(100, sizeof(char));
        scanf("%s", word);
        if (string_equals(&word[strlen(word) - 1], ";")) run = false;
        strcat(phrase, " ");
        strcat(phrase, word);
        free(word);
    }
    return phrase;
}

int main (int argc, char* argv[]) {
    bool run = true;
    Function *Add = newFunction("add", add);
    int a[3] = {1, 2, 3};

    while (run) {
        char* line = scan_phrase();
        char* sliced = calloc(100, sizeof(char));
        strslice(line, sliced, 0, strlen(line) - 2);
        char* command = strstrip(sliced);
        if (string_equals(command, "exit")) {
            run = false;
        }
        else if (string_equals(command, "add")) {
            printf("%i\n", CALL(int, Add, 3, a));
        }
        free(sliced);
        free(line);
    }
    freeFunction(Add);
    return 0;
}