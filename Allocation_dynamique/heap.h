#ifndef __HEAP_H__
#define __HEAP_H__
#include <stdint.h>

#define HEAP_BLOCK_SIZE_BYTES 16
#define HEAP_NB_BLOCKS 1024
#define HEAP_SIZE_BYTES (HEAP_NB_BLOCKS * HEAP_BLOCK_SIZE_BYTES)

extern __uint8_t heap_data[HEAP_SIZE_BYTES];

void heap_init(void);

#endif /* __HEAP_H__ */