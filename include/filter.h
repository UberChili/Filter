/* #ifndef FILTER_H_ */
/* #define FILTER_H_ */

#include <stdint.h>
#include <stdio.h>
extern const uint8_t signatureHeader[];
extern const int signatureHeaderLen;

// helpers
char *get_filename(char *text);
char *get_out_filename(char *text);

// PNG
int isValidPNG(FILE *fp);

/* #endif // FILTER_H_ */
