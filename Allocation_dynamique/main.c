#include "heap.h"
#include "minunit.h"
MU_TEST(test_check)
{
    mu_check(5 == 7);
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
