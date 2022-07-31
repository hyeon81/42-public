/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:58:46 by hyeokim2          #+#    #+#             */
/*   Updated: 2022/07/29 19:56:36 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define OPEN_MAX 2560
char	*get_next_line(int fd);
char	*ft_make_line(char **backup, char **buf);
char	*ft_return_last(char **backup, char **buf);
char	*ft_split_line(char *s1, int start, int end);
void	ft_free(char **s1, char **s2, int flag);
int		ft_strlen(char *s);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, int c);

#endif
