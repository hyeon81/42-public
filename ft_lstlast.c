#include "libft.h"
#include <stdlib.h>

t_list *ft_lstlast(t_list *lst)
{
    t_list *curr;

    curr = lst;
    if (!curr)
        return (curr);

    while (curr -> next != 0)
    {
        curr = curr -> next;
    }
    return (curr);
}