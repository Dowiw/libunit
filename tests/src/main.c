#include "tests.h"

int my_setup(void)
{
    ft_putstr(C_MAGENTA"      (Running Setup Hook)\n"C_RESET);
    return (0);
}

int my_teardown(void)
{
    ft_putstr(C_MAGENTA"      (Running Teardown Hook)\n"C_RESET);
    return (0);
}

int main(void)
{
    t_test_suite *suites = NULL;
    t_test_suite *s1;
    t_test_suite *s2;

    s1 = load_suite(&suites, "Standard Tests");
    s1->setup = my_setup;
    s1->teardown = my_teardown;
    load_test(s1, "Basic OK Test", &test_00_ok);
    load_test(s1, "Basic Fail Test", &test_01_fail);
    load_test(s1, "Capture Stdout Test", &test_05_capture);

    s2 = load_suite(&suites, "Crash Tests");
    load_test(s2, "Segmentation Fault Test", &test_02_segv);
    load_test(s2, "Bus Error Test", &test_03_bus);
    load_test(s2, "Timeout Test", &test_04_timeout);

    return (launch_tests(&suites));
}
