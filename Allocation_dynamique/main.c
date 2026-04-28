#include "heap.h"
#include "minunit.h"
MU_TEST(test_check)
{
    heap_init();
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
