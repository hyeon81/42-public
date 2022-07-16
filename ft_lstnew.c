/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:37:32 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/16 13:21:14 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*curr;

	curr = (t_list *)malloc(sizeof(t_list));
	if (!curr)
		return (0);
	curr -> next = 0;
	curr -> content = content;
	return (curr);
}
