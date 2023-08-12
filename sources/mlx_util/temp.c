/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:02:14 by feralves          #+#    #+#             */
/*   Updated: 2023/08/12 14:58:18 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <sys/time.h>

void	draw_background(t_vars *vars)
{
	int	x;
	int	y;
	int	ceiling;
	int	floor;

	y = 0;
	floor = vars->fullmap->floor;
	ceiling = vars->fullmap->ceiling;
	while (y < W_HEIGHT / 2)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			my_mlx_pixel_put(&vars->img, x, y, ceiling);
			my_mlx_pixel_put(&vars->img, x, y + W_HEIGHT / 2, floor);
			x++;
		}
		y++;
	}
}

void	creating_img(t_vars *vars)
{
	int		x;
	int		y;
	int		map_x;
	int		map_y;

	y = 0;
	map_y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		map_x = 0;
		while (x < W_WIDTH)
		{
			if (map_y < vars->fullmap->y_len)
			{
				if (map_x < vars->fullmap->x_len)
				{
					if (vars->fullmap->map[map_y][map_x] == 0)
						print_tile(&vars->img, x, y, 0x000000);
					else if (vars->fullmap->map[map_y][map_x] == 1)
						print_tile(&vars->img, x, y, 0xFFFFFF);
				}
			}
			if (map_y == vars->player->y && map_x == vars->player->x)
				print_square(&vars->img, x, y, vars->player->size);
			map_x++;
			x += TILE_SIZE;
		}
		map_y++;
		y += TILE_SIZE;
	}
}
