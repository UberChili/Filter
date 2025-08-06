#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "filter.h"

int main(int argc, char *argv[]) {
    // Checking correct usage and getting input filename
    if (argc != 2) {
        printf("Usage: ./filter filename.png\n");
        return 1;
    }
    char *filename = get_filename(argv[1]);
    char *out_filename = get_out_filename(filename);
    printf("filename: %s", filename);
    printf("out filename: %s", out_filename);

    // Freeing memory and exiting
    free(filename);
    return 0;
}
