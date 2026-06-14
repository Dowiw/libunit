#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>

# define C_RED     "\x1B[31m"
# define C_GREEN   "\x1B[32m"
# define C_YELLOW  "\x1B[33m"
# define C_BLUE    "\x1B[34m"
# define C_MAGENTA "\x1B[35m"
# define C_CYAN    "\x1B[36m"
# define C_RESET   "\x1B[0m"

# include "libunit_assert.h"

typedef struct s_unit_test
{
    char                *name;
    int                 (*f)(void);
    struct s_unit_test  *next;
}   t_unit_test;

typedef struct s_test_suite
{
    char                *name;
    t_unit_test         *tests;
    struct s_test_suite *next;
}   t_test_suite;

t_test_suite *load_suite(t_test_suite **suites, char *name);
void    load_test(t_test_suite *suite, char *name, int (*f)(void));
int     launch_tests(t_test_suite **suites);

void    ft_putstr(char *s);
void    ft_putnbr(int n);

void    capture_stdout_start(void);
char    *capture_stdout_end(void);

#endif
