#include "libft.h"
t_list *ft_lstnew(void *content)
{
    t_list* curr;
    curr = (t_list*)malloc(sizeof(t_list));
    if (!curr)
        return 0;
    
    curr -> next = 0;
    curr -> content = content;
    return (curr);
}