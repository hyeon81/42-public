/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:41:50 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/13 17:56:20 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	search_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	search_s_idx(const char *s1, const char *set)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (search_set(s1[i], (char *) set) == 0)
			break ;
		i++;
	}
	return (i);
}

int	search_e_idx(const char *s1, const char *set, int start)
{
	int i;

	i = start;
	while (s1[i] != 0)
		i++;
	while (start < i - 1)
	{
		if (search_set(s1[i - 1], (char *) set) == 0)
			break ;
		i--;
	}
	return (i - 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		start;
	int		end;

	start = search_s_idx(s1, set);
	end = search_e_idx(s1, set, start);
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (0);
	i = 0;
	while (start <= end)
	{
		str[i] = s1[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int main() {
//     printf("%s", ft_strtrim("1232355", "1234"));
// }