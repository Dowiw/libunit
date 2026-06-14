#include "tests.h"

int test_02_segv(void)
{
    char *ptr = NULL;
    *ptr = 42;
    return (0);
}
