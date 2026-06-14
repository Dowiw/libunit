#include "tests.h"

int test_03_bus(void)
{
#if defined(__APPLE__) || defined(__linux__)
    char *ptr = "Read-only string";
    *ptr = 42;
#else
    char *ptr = NULL;
    *ptr = 42;
#endif
    return (0);
}
