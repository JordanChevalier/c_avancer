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
    uint32_t block_index;
    if (size == 0 || size > HEAP_SIZE_BYTES)
    {
        return NULL;
    }

    uint32_t nb_blocks_needed = (size + HEAP_BLOCK_SIZE_BYTES - 1) / HEAP_BLOCK_SIZE_BYTES;

    for (block_index = 0; block_index < HEAP_NB_BLOCKS;)
    {
        for (uint32_t free_block_index = 0; free_block_index < nb_blocks_needed; free_block_index++)
        {
            if (block_index + free_block_index >= HEAP_NB_BLOCKS)
                return NULL;

            if (heap_attributes[block_index + free_block_index] == HEAP_BLOCK_USED)
            {
                block_index++; // Skip the used blocks
                break;
            }
        }
        break; // Found a suitable block
    }

    for (uint32_t i = 0; i < nb_blocks_needed; i++)
    {
        heap_attributes[block_index + i] = HEAP_BLOCK_USED;
    }
    return &heap_data[block_index * HEAP_BLOCK_SIZE_BYTES];
}
