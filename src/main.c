#include <stdio.h>
#include <stdlib.h>

#include "filter.h"

int main(int argc, char *argv[]) {
    // Checking correct usage
    if (argc != 2) {
        printf("Usage: ./filter filename.png\n");
        return 1;
    }
    // Getting filename and output filename
    char *filename = get_filename(argv[1]);
    char *out_filename = get_out_filename(filename);

    // Opening file
    FILE *in_fp = fopen(filename, "rb");
    if (in_fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    // Check if valid PNG file
    if (isValidPNG(in_fp)) {
        printf("Valid PNG file.\n");
    } else {
        printf("Invalid PNG file.\n");
        return 1;
    }

    // Freeing memory and exiting
    free(filename);
    free(out_filename);
    return 0;
}
