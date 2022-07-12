#include "libft.h"
#include <stdlib.h>

void ft_lstadd_front(t_list **lst, t_list *new)
{
    t_list *curr;

    curr = new;
    curr -> next = *lst;
    *lst = curr;
}