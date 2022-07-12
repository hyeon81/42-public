#include "libft.h"
#include <stdlib.h>

int ft_lstsize(t_list *lst)
{
    t_list *curr;
    int cnt = 0;

    curr = lst;
    while (curr != 0)
    {
        cnt ++;
        curr = curr -> next;
    }
    return (cnt);
}