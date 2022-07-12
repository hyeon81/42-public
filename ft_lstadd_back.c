#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *curr;
    curr = *lst;
    if (*lst == 0)
    {
        *lst = new;
        return ;
    }
    while (curr -> next != 0)
    {
        curr = curr -> next;
    }
    curr -> next = new;
    new -> next = 0;
}