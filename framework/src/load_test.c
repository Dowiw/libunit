#include "libunit.h"

void    load_test(t_unit_test **list, char *name, int (*f)(void))
{
    t_unit_test *new;
    t_unit_test *tmp;

    new = (t_unit_test *)malloc(sizeof(t_unit_test));
    if (!new)
        return ;
    new->name = name;
    new->f = f;
    new->next = NULL;

    if (!*list)
        *list = new;
    else
    {
        tmp = *list;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}
