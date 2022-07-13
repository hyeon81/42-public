/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:37:21 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/13 14:16:12 by hyeokim2         ###   ########.fr       */
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

// void ft_lstclear(t_list **lst, void (del)(void *)) {
//     t_list *cur;

//     if (lst == NULL || del == NULL) {
//         return;
//     }
//     while (*lst) {
//         cur = (*lst)->next;
//         ft_lstdelone(*lst, del);
//         *lst = cur;
//     }
//     *lst = 0;
// }

// t_list *ft_lstnew(void *content)
// {
//     t_list* curr;
//     curr = (t_list*)malloc(sizeof(t_list));

//     curr -> next = 0;
//     curr -> content = content;
//     return (curr);
// }

// void ft_lstadd_back(t_list **lst, t_list *new)
// {
//     t_list *curr;
//     curr = *lst;
//     while (curr -> next != 0)
//     {
//         curr = curr -> next;
//     }
//     curr -> next = new;
//     new -> next = 0;
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*node;

	node = NULL;
	while (lst)
	{
		newnode = ft_lstnew(f(lst->content));
		if (!newnode)
		{
			ft_lstclear(&node, del);
			return ((void *)(0));
		}
		ft_lstadd_back(&node, newnode);
		lst = lst->next;
	}
	newnode = NULL;
	return (node);
}
