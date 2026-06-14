#include "libunit.h"

static int  ft_strlen(char *s)
{
    int i = 0;
    while (s && s[i])
        i++;
    return (i);
}

void    ft_putstr(char *s)
{
    if (s)
        write(1, s, ft_strlen(s));
}

static void ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int n)
{
    long ln = n;

    if (ln < 0)
    {
        ft_putchar('-');
        ln = -ln;
    }
    if (ln > 9)
    {
        ft_putnbr(ln / 10);
        ft_putnbr(ln % 10);
    }
    else
        ft_putchar(ln + '0');
}
