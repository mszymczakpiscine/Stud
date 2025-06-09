#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct    s_list
{
	struct s_list *next;
	void          *data;
}                 t_list;

#endif

#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
    int i = 0;
    while (begin_list->next)
    {
        begin_list = begin_list->next;
        i++;
    }
    return (i);
}
