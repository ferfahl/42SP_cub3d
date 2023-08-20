/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:23:57 by feralves          #+#    #+#             */
/*   Updated: 2023/08/20 17:38:45 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rays(t_cub *cub, t_rays *rays)
{
	t_pos	test;
	t_pos	hit_test;
	int		col;

	col = 0;
	while (col < cub->nbr_rays)
	{
		test.x = floor(rays[col].init[X] * MAP_SCALE);
		test.y = floor(rays[col].init[Y] * MAP_SCALE);
		hit_test.x = floor(rays[col].hit[X] * MAP_SCALE);
		hit_test.y = floor(rays[col].hit[Y] * MAP_SCALE);
		draw_line(&cub->img, test, hit_test, 0x0000FF);
		col++;
	}
}

void	draw_player(t_cub *cub)
{
	int		next_x;
	int		next_y;
	t_pos	a;
	t_pos	b;

	next_x = cub->player->pos[X] * MAP_SCALE + cos(cub->player->angle)
		* 10;
	next_y = cub->player->pos[Y] * MAP_SCALE + sin(cub->player->angle)
		* 10;
	a.x = floor(cub->player->pos[X] * MAP_SCALE);
	a.y = floor(cub->player->pos[Y] * MAP_SCALE);
	b.x = floor(next_x);
	b.y = floor(next_y);
	draw_circle(&cub->img, a.x, a.y, P_SIZE);
	draw_line(&cub->img, a, b, 0xFF0000);
	draw_rays(cub, cub->rays);
}

void	draw_mini_map(t_cub *cub, t_map *map)
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
			if (map_wall(cub->fullmap, id.x, id.y))
				draw_square(&cub->img, scale, map_tile, 0xFFFFFF);
			else if (map_floor(cub->fullmap, id.x, id.y))
				draw_square(&cub->img, scale, map_tile, 0x000000);
			id.x += TILE_SIZE;
		}
		id.y += TILE_SIZE;
	}
	draw_player(cub);
}
