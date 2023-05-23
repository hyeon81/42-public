/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim2 <hyeokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:54:01 by hyeokim2          #+#    #+#             */
/*   Updated: 2023/05/23 13:37:19 by hyeokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clac_draw_line(t_raycast *r)
{
	if (r->side == 0)
		r->prep_dist = (r->map_x - r->p->pos.x + (1 - r->step.x) / 2) \
		/ r->ray_dir.x;
	else
		r->prep_dist = (r->map_y - r->p->pos.y + (1 - r->step.y) / 2) \
		/ r->ray_dir.y;
	r->line_h = (int)(HEIGHT / r->prep_dist);
	r->start = (HEIGHT / 2) - (r->line_h / 2);
	if (r->start < 0)
		r->start = 0;
	r->end = (r->line_h / 2) + (HEIGHT / 2);
	if (r->end >= HEIGHT)
		r->end = HEIGHT - 1;
}

void	calc_tex_x(t_raycast *r)
{
	double	wall_x;

	if (r->side == 0)
		wall_x = r->p->pos.y + r->prep_dist * r->ray_dir.y;
	else
		wall_x = r->p->pos.x + r->prep_dist * r->ray_dir.x;
	wall_x -= floor(wall_x);
	r->tex_x = (int)(wall_x * (double)TEX_W);
	if (r->side == 0 && r->ray_dir.x < 0)
		r->tex_x = TEX_W - r->tex_x;
	if (r->side == 1 && r->ray_dir.y > 0)
		r->tex_x = TEX_W - r->tex_x;
}

void	set_draw_map(t_raycast *r, int x, t_img *map_img, int **tex)
{
	double	step;
	double	tex_pos;
	int		tex_y;
	int		tex_num;
	int		y;

	step = (double)TEX_H / (double)r->line_h;
	tex_pos = (r->start - (HEIGHT / 2) + (r->line_h / 2)) * step;
	y = r->start;
	while (y < r->end)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		if (r->ray_dir.x > 0 && r->side == 0)
			tex_num = 0;
		else if (r->ray_dir.x < 0 && r->side == 0)
			tex_num = 1;
		else if (r->ray_dir.y > 0 && r->side == 1)
			tex_num = 2;
		else
			tex_num = 3;
		map_img->data[y * WIDTH + x] = tex[tex_num][TEX_H * tex_y + r->tex_x];
		y++;
	}
}

void	set_draw(t_raycast *r)
{
	clac_draw_line(r);
	calc_tex_x(r);
}
