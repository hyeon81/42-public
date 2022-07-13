/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:37:02 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/13 14:12:36 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void ft_lstdelone(t_list *lst, void (*del)(void *))
// {
//     if (lst == NULL || del == NULL)
//         return ;
//     del(lst->content);
//     free(lst);
// }

void	ft_lstclear(t_list **lst, void (del)(void *))
{
	t_list	*cur;

	if ((lst == 0) || (del == 0))
		return ;
	while (*lst)
	{
		cur = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = cur;
	}
	*lst = 0;
}
