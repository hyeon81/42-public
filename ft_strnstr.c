/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:41:39 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/13 16:57:02 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == 0)
		return ((char *)haystack);
	i = 0;
	j = 0;
	while ((haystack[i] != 0) && (i < len))
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && (i + j < len))
		{
			j++;
			if (needle[j] == 0)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}

// int main()
// {
//     char *s1 = "12345689234";
//     char *s2 = "234";

//     printf("%s : %s\n", ft_strnstr(s1, s2, 10), strnstr(s1, s2, 10));
//     printf("%s : %s\n", ft_strnstr(s1, "89", 2), strnstr(s1, "89", 2));
//     printf("%s : %s\n", ft_strnstr(s1, "89", 10), strnstr(s1, "89", 10));
//     printf("%s : %s\n", ft_strnstr(s1, "89", 0), strnstr(s1, "89", 0));
//     printf("%s : %s\n", ft_strnstr(s1, "", 10), strnstr(s1, "", 10));
// }