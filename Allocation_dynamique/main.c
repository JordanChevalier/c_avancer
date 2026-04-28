#include "heap.h"
#include "minunit.h"
#include <stdio.h>

MU_TEST(test_check)
{
    heap_init();
    for (__uint32_t i = 0; i < HEAP_SIZE_BYTES; i++)
    {
        mu_assert_int_eq(heap_data[i], 0);
    }
    for (__uint32_t i = 0; i < HEAP_NB_BLOCKS; i++)
    {
        mu_assert_int_eq(heap_attributes[i], HEAP_BLOCK_FREE);
    }
}

MU_TEST(test_heap_malloc_null_size)
{
    heap_init();
    void *result = heap_malloc(0);
    mu_assert(result == NULL, "Expected NULL for zero size allocation");
}

MU_TEST(test_heap_malloc_too_large)
{
    heap_init();
    void *result = heap_malloc(HEAP_SIZE_BYTES + 1);
    mu_assert(result == NULL, "Expected NULL for allocation larger than heap size");
}

MU_TEST(test_heap_malloc_nominal)
{
    heap_init();
    void *result = heap_malloc(64);
    mu_assert(result == heap_data, "Expected non-NULL for valid allocation");
    for (__uint8_t block_index = 0; block_index < (64 / HEAP_BLOCK_SIZE_BYTES); block_index++)
    {
        mu_assert_int_eq(heap_attributes[block_index], HEAP_BLOCK_USED);
    }
}

MU_TEST_SUITE(heap_test_suite)
{
    MU_RUN_TEST(test_check);
    MU_RUN_TEST(test_heap_malloc_null_size);
    MU_RUN_TEST(test_heap_malloc_too_large);
    MU_RUN_TEST(test_heap_malloc_nominal);
}

int main(int argc, char *argv[])
{
    MU_RUN_SUITE(heap_test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
