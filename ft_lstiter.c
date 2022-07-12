#include "libft.h"

void            ft_lstiter(t_list *lst, void (*f)(void *))
{
    t_list  *curr;

    curr = lst;
    while (curr != 0)
    {
        f(curr->content);
        curr = curr->next;
    }
}