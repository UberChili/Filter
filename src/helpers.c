#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filter.h"

// Just a function to get a string more cleanly inside main
char *get_filename(char *text) {
    size_t len = strlen(text);

    char *result = malloc(len + 1);
    if (result == NULL) {
        printf("Error allocating memory for string\n");
        return NULL;
    }

    strcpy(result, text);
    return result;
}

char *get_out_filename(char *text) {
    char *result = malloc(256);
    if (result == NULL) {
        printf("Error allocating memory for string\n");
        return NULL;
    }

    sprintf(result, "out_%s", text);

    return result;
}
