/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:23:57 by feralves          #+#    #+#             */
/*   Updated: 2023/08/17 20:17:38 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rays(t_vars *vars, t_rays *rays)
{
	t_pos	test;
	t_pos	hit_test;
	int		col;

	col = 0;
	// while (col < W_WIDTH)
	// {
		test.x = floor(rays[col].init.x * MAP_SCALE);
		test.y = floor(rays[col].init.y * MAP_SCALE);
		hit_test.x = floor(rays[col].wall_hit.x * MAP_SCALE);
		hit_test.y = floor(rays[col].wall_hit.y * MAP_SCALE);
		draw_line(&vars->img, test, hit_test, 0x0000FF);
	// 	col++;
	// }
}

void	draw_player(t_vars *vars)
{
	int		next_x;
	int		next_y;
	t_pos	a;
	t_pos	b;

	next_x = vars->player->x * MAP_SCALE + cos(vars->player->angle)
		* 10;
	next_y = vars->player->y * MAP_SCALE + sin(vars->player->angle)
		* 10;
	a.x = floor(vars->player->x * MAP_SCALE);
	a.y = floor(vars->player->y * MAP_SCALE);
	b.x = floor(next_x);
	b.y = floor(next_y);
	draw_circle(&vars->img, a.x, a.y, P_SIZE);
	draw_line(&vars->img, a, b, 0xFF0000);
	draw_rays(vars, vars->rays);
}

void	draw_mini_map(t_vars *vars, t_map *map)
{
	t_pos	id;
	t_pos	scale;
	int		map_tile;

	id.y = 0;
	map_tile = TILE_SIZE * MAP_SCALE;
	while (id.y < map->y_len)
	{
		id.x = 0;
		while (id.x < map->x_len)
		{
			scale.x = id.x * MAP_SCALE;
			scale.y = id.y * MAP_SCALE;
			if (map_wall(vars->fullmap, id.x, id.y))
				draw_square(&vars->img, scale, map_tile, 0xFFFFFF);
			else
				draw_square(&vars->img, scale, map_tile, 0x000000);
			id.x += TILE_SIZE;
		}
		id.y += TILE_SIZE;
	}
	draw_player(vars);
}
