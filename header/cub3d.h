/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:29:45 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/17 18:52:21 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// # include <mlx.h>
# include <stdlib.h>
# include "../get_next_line/get_next_line.h"

# define ERROR -1

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef enum e_identifier_type
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
}	t_identifier_type;



// typedef	struct	s_tex
// {
//     char		*path;
//     int			*tex;
// 	//width / height
// }               t_tex;

//raycast

//parse

//graphic

typedef struct s_check
{
	int	*mapset;
	int	path_count;
	int	count;
	int	mapflag;
	int	id;

}	t_check;



typedef struct s_vars
{
	int		floor_color;
	int		ceiling_color;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	// int		row;
	// int 	col;
    char	**map;
}t_vars;



int			init_map(t_vars	*vars, int fd, t_check *check);
void		*ft_memset(void *b, int c, size_t len);
int			check_arg(char *filename);
char		**ft_split(char const *s, char c);
char		**free_all(char **arr);
int			ft_strncmp(const char *s1, const char *s2, size_t len);
int			strs_len(char	**strs);
void		*ft_calloc(size_t count, size_t size);
int			print_err(char	*str);
int			exit_with_err(char	*str);
char		**split_for_map(char const *s, char c);
int			ft_atoi(const char *str);
int 		set_map(char	*line, t_vars *vars, t_check *check);
int			exit_with_err(char	*str);
int			print_err(char	*str);
void		print(t_vars *vars);


#endif
