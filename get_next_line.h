/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:58:46 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/10/12 15:24:46 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line2(int fd);
char	*ft_make_line(char **backup, char **buf);
char	*ft_return_last(char **backup, char **buf);
char	*ft_split_line(char *s1, int start, int end);
void	ft_free2(char **s1, char **s2, int flag);
int		ft_strlen2(char *s);
char	*ft_strdup(char *s1);
char	*ft_strjoin2(char *s1, char *s2);
int		ft_strchr(char *s, int c);

#endif
