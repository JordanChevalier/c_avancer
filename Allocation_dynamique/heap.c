#include "heap.h"

heap_block_attribute_t heap_attributes[HEAP_NB_BLOCKS];
__uint8_t heap_data[HEAP_SIZE_BYTES];

void heap_init(void)
{
    for (__uint32_t i = 0; i < HEAP_SIZE_BYTES; i++)
    {
        heap_data[i] = 0;
    }
}

void *heap_malloc(__uint32_t size)
{
    return NULL;
}
