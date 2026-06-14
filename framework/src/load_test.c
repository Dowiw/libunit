#include "libunit.h"

t_test_suite *load_suite(t_test_suite **suites, char *name)
{
    t_test_suite *new;
    t_test_suite *tmp;

    new = (t_test_suite *)malloc(sizeof(t_test_suite));
    if (!new)
        return (NULL);
    new->name = name;
    new->tests = NULL;
    new->setup = NULL;
    new->teardown = NULL;
    new->next = NULL;

    if (!*suites)
        *suites = new;
    else
    {
        tmp = *suites;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
    return (new);
}

void    load_test(t_test_suite *suite, char *name, int (*f)(void))
{
    t_unit_test *new;
    t_unit_test *tmp;

    if (!suite)
        return ;
    new = (t_unit_test *)malloc(sizeof(t_unit_test));
    if (!new)
        return ;
    new->name = name;
    new->f = f;
    new->next = NULL;

    if (!suite->tests)
        suite->tests = new;
    else
    {
        tmp = suite->tests;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}
