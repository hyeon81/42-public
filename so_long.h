#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	int		w;
	int		h;
	int     img_width;
	int     img_height;
	int		escape_x;
	int		escape_y;
	int     pos;
    int     pos_x;
    int     pos_y;
	int		item;
	int		get_item;
	int		move_count;
	void    *img;
	void	*img3;
	void	*bg;
	void	*img4;
}				t_vars;

#endif
