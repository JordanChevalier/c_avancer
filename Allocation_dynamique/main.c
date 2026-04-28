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
}

MU_TEST_SUITE(heap_test_suite)
{
    MU_RUN_TEST(test_check);
}

int main(int argc, char *argv[])
{
    MU_RUN_SUITE(heap_test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
