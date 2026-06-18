#include <unistd.h>

static void ft_putstr_fd(char *s, int fd)
{
    int i = 0;
    while (s && s[i])
        i++;
    if (i > 0)
        write(fd, s, i);
}

static void ft_putnbr_fd(int n, int fd)
{
    long ln = n;
    char c;

    if (ln < 0)
    {
        write(fd, "-", 1);
        ln = -ln;
    }
    if (ln > 9)
    {
        ft_putnbr_fd(ln / 10, fd);
        ft_putnbr_fd(ln % 10, fd);
    }
    else
    {
        c = ln + '0';
        write(fd, &c, 1);
    }
}

void unit_print_error(const char *file, int line, const char *cond)
{
    ft_putstr_fd("  [ASSERT FAILED: ", 2);
    ft_putstr_fd((char *)file, 2);
    ft_putstr_fd(":", 2);
    ft_putnbr_fd(line, 2);
    ft_putstr_fd(" (", 2);
    ft_putstr_fd((char *)cond, 2);
    ft_putstr_fd(")] ", 2);
}
