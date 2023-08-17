/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:23:57 by feralves          #+#    #+#             */
/*   Updated: 2023/08/17 00:22:47 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	draw_rays(t_vars *vars)
// {
// 	t_pos	player;

// 	player.x = floor(vars->player->x * MAP_SCALE);
// 	player.y = floor(vars->player->y * MAP_SCALE);
// }

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
	print_circle(&vars->img, a.x, a.y, P_SIZE);
	draw_line(&vars->img, a, b, 0xFF0000);
	// draw_rays(vars);
}

void	draw_mini_map(t_vars *vars, t_map *map)
{
	t_pos	id;

	id.y = 0;
	while (id.y < W_HEIGHT)
	{
		id.x = 0;
		while (id.x < W_WIDTH)
		{
			if ((id.y / MAP_SCALE) <= map->y_len)
			{
				if ((id.x / MAP_SCALE) <= map->x_len)
				{
					if (map->map[id.y / MAP_SCALE][id.x / MAP_SCALE] == 0)
						print_square(&vars->img, id, MAP_SCALE, 0x000000);
					else
						print_square(&vars->img, id, MAP_SCALE, 0xFFFFFF);
				}
			}
			id.x += MAP_SCALE;
		}
		id.y += MAP_SCALE;
	}
	draw_player(vars);
}
