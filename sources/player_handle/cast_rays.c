/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:04:12 by feralves          #+#    #+#             */
/*   Updated: 2023/08/15 17:58:03 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	single_ray(t_vars *vars, t_rays *ray, int nbr)
{
	float	inc_x;
	float	inc_y;
	t_pos	a;
	t_pos	b;

	inc_x = vars->player->x;
	inc_y = vars->player->y;
	a.x = vars->player->x;
	a.y = vars->player->y;
	while (!map_wall(vars->fullmap, inc_x, inc_y))
	{
		inc_x += vars->player->x * MAP_SCALE + cos(vars->player->angle)
			* 50;
		inc_y += vars->player->y * MAP_SCALE + sin(vars->player->angle)
			* 50;
	}
	b.x = inc_x;
	b.y = inc_y;
	print_line(&vars->img, a, b, 0x00FF00);
}

void	cast_all_rays(t_vars *vars)
{
	int		col;
	float	dist_proj;
	float	map_w;

	col = 0;
	map_w = (vars->fullmap->x_len) / 2;
	dist_proj = map_w / tan(FOV / 2);
	while (col < vars->nbr_rays)
	{
		vars->rays[col].angle = vars->player->angle + atan((col -
			vars->nbr_rays) / dist_proj);
		single_ray(vars, rays[col], col);
		col++;
	}
}