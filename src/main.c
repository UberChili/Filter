#include <stddef.h>
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
    // TODO delete these prints, we won't need them later
    printf("filename: %s", filename);
    printf("out filename: %s", out_filename);

    // Freeing memory and exiting
    free(filename);
    free(out_filename);
    return 0;
}
