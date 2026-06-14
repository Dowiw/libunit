#include "tests.h"

int test_01_fail(void)
{
    UNIT_ASSERT_EQ(42, 0);
    return (0);
}
