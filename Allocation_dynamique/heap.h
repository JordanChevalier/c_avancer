#ifndef __HEAP_H__
#define __HEAP_H__
#include <stdint.h>
typedef enum
{
    HEAP_BLOCK_FREE = 0,
    HEAP_BLOCK_USED = 1
} heap_block_attribute_t;

#define HEAP_BLOCK_SIZE_BYTES 16
#define HEAP_NB_BLOCKS 1024
#define HEAP_SIZE_BYTES (HEAP_NB_BLOCKS * HEAP_BLOCK_SIZE_BYTES)

extern __uint8_t heap_data[HEAP_SIZE_BYTES];
extern heap_block_attribute_t heap_attributes[HEAP_NB_BLOCKS];
void heap_init(void);

#endif /* __HEAP_H__ */