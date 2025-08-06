#include "filter.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint32_t swap_endian(uint32_t val) {
    return ((val >> 24) & 0xff) | ((val >> 8) & 0xff00) |
           ((val << 8) & 0xff0000) | ((val << 24) & 0xff000000);
}

void parseIHDR(Chunk *chunk) {
    uint8_t *ptr = chunk->data;
    uint32_t width = swap_endian(*(uint32_t *)(ptr));
    uint32_t height = swap_endian(*(uint32_t *)(ptr + 4));
    uint8_t bit_depth = *(ptr + 8);
    uint8_t color_type = *(ptr + 9);
    uint8_t compression_method = *(ptr + 10);
    uint8_t filter_method = *(ptr + 11);
    uint8_t interlace_method = *(ptr + 12);

    printf("Width: %d\n", width);
    printf("Height: %d\n", height);
    printf("Bit Depth: %d\n", bit_depth);
    printf("Color type: %d\n", color_type);
    printf("Compression method: %d\n", compression_method);
    printf("Filter method: %d\n", filter_method);
    printf("Interlace method: %d\n", interlace_method);
}

Chunk *read_chunk(FILE *fp) {
    if (fp == NULL) {
        printf("Error reading Chunk. Invalid file?\n");
        return NULL;
    }

    // Allocating memory for Chunk
    Chunk *chunk = malloc(sizeof(Chunk));
    if (chunk == NULL) {
        printf("Error allocating memory for Chunk.\n");
        return NULL;
    }

    // Reading Length
    uint32_t length;
    if (fread(&length, sizeof(uint32_t), 1, fp) != 1) {
        printf("Error reading length.\n");
        free(chunk);
        return NULL;
    }
    chunk->length = swap_endian(length);

    // Reading Chunk Type
    ChunkType chunktype;
    if (fread(&chunktype.type, sizeof(ChunkType), 1, fp) != 1) {
        free(chunk);
        printf("Error reading Chunk Type.\n");
        return NULL;
    }
    chunk->type = chunktype;

    // Reading data
    chunk->data = malloc(sizeof(uint8_t) * chunk->length);
    if (chunk->data == NULL) {
        printf("Error allocating memory for Chunk Data.\n");
        free(chunk);
        return NULL;
    }
    if (fread(chunk->data, sizeof(uint8_t), chunk->length, fp) !=
        chunk->length) {
        free(chunk->data);
        free(chunk);
        printf("Error reading into Chunk Data.\n");
        return NULL;
    }

    // Reading CRC into temporary buffer, then copy
    uint32_t temp_crc;
    if (fread(&temp_crc, sizeof(uint32_t), 1, fp) != 1) {
        free(chunk->data);
        free(chunk);
        printf("Error reading CRC.\n");
        return NULL;
    }
    chunk->CRC = temp_crc;

    return chunk;
}
