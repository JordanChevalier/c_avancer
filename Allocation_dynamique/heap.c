#include "heap.h"
__uint8_t heap_data[HEAP_SIZE_BYTES];
void heap_init(void)
{
    for (__uint32_t i = 0; i < HEAP_SIZE_BYTES; i++)
    {
        heap_data[i] = 0;
    }
}
