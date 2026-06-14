#include "tests.h"

int main(void)
{
    t_unit_test *testlist;

    testlist = NULL;

    ft_putstr("*********************************\n");
    ft_putstr("          LIBUNIT TESTS          \n");
    ft_putstr("*********************************\n");

    load_test(&testlist, "Basic OK Test", &test_00_ok);
    load_test(&testlist, "Basic Fail Test", &test_01_fail);
    load_test(&testlist, "Segmentation Fault Test", &test_02_segv);
    load_test(&testlist, "Bus Error Test", &test_03_bus);
    load_test(&testlist, "Timeout Test", &test_04_timeout);

    return (launch_tests(&testlist));
}
