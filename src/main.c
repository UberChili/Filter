#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    // Need to read chunks over and over again until EOF
    // For now, let's just print the Chunk values, maybe only the chunk type
    // TODO
    while (1) {
        // Read Chunk
        Chunk *curr_chunk = read_chunk(in_fp);
        if (curr_chunk == NULL) {
            printf("Exiting.\n");
            free(filename);
            free(out_filename);
            fclose(in_fp);
            return 1;
        }

        if (strncmp(curr_chunk->type.type, "IEND", 4) == 0) {
            printf("IEND reached.\n");
            free(curr_chunk->data);
            free(curr_chunk);
            break;
        }

        printf("Chunk Type: %.4s\n", curr_chunk->type.type);
        free(curr_chunk->data);
        free(curr_chunk);
    }

    // Freeing memory and exiting
    fclose(in_fp);
    free(filename);
    free(out_filename);
    return 0;
}
