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
    if (size == 0 || size > HEAP_SIZE_BYTES)
    {
        return NULL;
    }

    uint32_t nb_blocks_needed = (size + HEAP_BLOCK_SIZE_BYTES - 1) / HEAP_BLOCK_SIZE_BYTES;

    for (uint32_t block_index = 0; block_index < nb_blocks_needed; block_index++)
    {
        heap_attributes[block_index] = HEAP_BLOCK_USED;
    }
    return heap_data;
}
