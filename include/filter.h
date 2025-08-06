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

// Chunk Type
typedef struct {
    char type[4];
} __attribute__((__packed__)) ChunkType;

// Chunk
typedef struct {
    uint32_t length;
    ChunkType type;
    uint8_t *data;
    uint32_t CRC;
} __attribute__((__packed__)) Chunk;

// Reads a single Chunk
Chunk *read_chunk(FILE *fp);

// Parses the IHDR Chunk
void parseIHDR(Chunk *chunk);

/* #endif // FILTER_H_ */
