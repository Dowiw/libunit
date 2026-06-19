#include "libunit.h"
#include <stdlib.h>

static void    free_tests(t_unit_test **list)
{
    t_unit_test *tmp;

    while (*list)
    {
        tmp = *list;
        *list = (*list)->next;
        free(tmp);
    }
}

static void    free_suites(t_test_suite **suites)
{
    t_test_suite *tmp;

    while (*suites)
    {
        tmp = *suites;
        free_tests(&tmp->tests);
        *suites = (*suites)->next;
        free(tmp);
    }
}

static void print_status(int status, int *success)
{
    if (WIFEXITED(status))
    {
        if (WEXITSTATUS(status) == 0)
        {
            ft_putstr(C_GREEN"[OK]"C_RESET"\n");
            (*success)++;
        }
        else
            ft_putstr(C_RED"[FAIL]"C_RESET"\n");
    }
    else if (WIFSIGNALED(status))
    {
        if (WTERMSIG(status) == SIGSEGV)
            ft_putstr(C_YELLOW"[SIGSEGV]"C_RESET"\n");
        else if (WTERMSIG(status) == SIGBUS)
            ft_putstr(C_YELLOW"[SIGBUS]"C_RESET"\n");
        else if (WTERMSIG(status) == SIGALRM)
            ft_putstr(C_CYAN"[TIMEOUT]"C_RESET"\n");
        else
            ft_putstr(C_RED"[SIGNAL ERROR]"C_RESET"\n");
    }
}

static int  run_test(t_unit_test *test)
{
    pid_t   pid;
    int     status;

    ft_putstr("    > ");
    ft_putstr(test->name);
    ft_putstr(" : ");

    pid = fork();
    if (pid < 0)
    {
        ft_putstr("Fork error\n");
        return (0);
    }
    if (pid == 0)
    {
        alarm(3); // Timeout of 3 seconds
        exit(test->f());
    }
    wait(&status);
    return (status);
}

int     launch_tests(t_test_suite **suites)
{
    t_test_suite *s_tmp;
    t_unit_test  *t_tmp;
    int         total;
    int         success;
    int         status;

    s_tmp = *suites;
    total = 0;
    success = 0;
    ft_putstr("*********************************\n");
    ft_putstr("          LIBUNIT TESTS          \n");
    ft_putstr("*********************************\n");
    while (s_tmp)
    {
        ft_putstr("\n[");
        ft_putstr(s_tmp->name);
        ft_putstr("]\n");

        if (s_tmp->setup)
        {
            if (s_tmp->setup() == -1)
            {
                ft_putstr(C_RED"    > Setup Failed! Skipping suite.\n"C_RESET);
                s_tmp = s_tmp->next;
                continue;
            }
        }

        t_tmp = s_tmp->tests;
        while (t_tmp)
        {
            status = run_test(t_tmp);
            print_status(status, &success);
            total++;
            t_tmp = t_tmp->next;
        }

        if (s_tmp->teardown)
            s_tmp->teardown();

        s_tmp = s_tmp->next;
    }
    ft_putstr("\n");
    ft_putnbr(success);
    ft_putstr("/");
    ft_putnbr(total);
    ft_putstr(" tests passed\n\n");
    
    free_suites(suites);
    
    if (total > 0 && success == total)
        return (0);
    return (-1);
}
