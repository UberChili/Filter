#include <stdint.h>
#include <stdio.h>

#include "filter.h"

const uint8_t signatureHeader[] = {137, 80, 78, 71, 13, 10, 26, 10};
const int signatureHeaderLen = 8;

int isValidPNG(FILE *fp) {
    uint8_t buff[8];

    // Read values from file stream
    if (fread(buff, sizeof(signatureHeader), 1, fp) != 1) {
        printf("Error reading bytes for Signature Header. Damaged file?\n");
        return 0;
    }

    // Compare values to Signature Header
    for (size_t i = 0; i < (size_t) signatureHeaderLen; i++) {
        printf("%d, ", buff[i]);
        if (buff[i] != signatureHeader[i]) {
            printf("Mismatch in Signature Header values.\n");
            return 0;
        }
    }
    printf("\n");
    return 1;
}
