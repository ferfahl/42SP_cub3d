/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:02:14 by feralves          #+#    #+#             */
/*   Updated: 2023/08/12 11:03:23 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_background(t_vars *vars)
{
	int		x;
	int		y;

	y = -1;
	while (++y < W_HEIGHT)
	{
		x = -1;
		while (++x < W_WIDTH)
		{
			vars->img.data[y * W_WIDTH + x] = 0;
		}
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
						print_tile(&vars->img, x, y, 0xFF0000);
					else if (vars->fullmap->map[map_y][map_x] == 1)
						print_tile(&vars->img, x, y, 0xFFFFFF);
				}
			}
			map_x++;
			x += TILE_SIZE;
		}
		map_y++;
		y += TILE_SIZE;
	}
}
