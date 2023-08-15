/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:02:14 by feralves          #+#    #+#             */
/*   Updated: 2023/08/12 19:50:57 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	draw_player(t_vars *vars)
{
	int		next_x;
	int		next_y;
	t_pos	a;
	t_pos	b;

	next_x = vars->player->x * TILE_SIZE + cos(radians(vars->player->angle))
		* 50;
	next_y = vars->player->y * TILE_SIZE + sin(radians(vars->player->angle))
		* 50;
	a.x = floor(vars->player->x * TILE_SIZE);
	a.y = floor(vars->player->y * TILE_SIZE);
	b.x = floor(next_x);
	b.y = floor(next_y);
	print_circle(&vars->img, a.x, a.y, vars->player->size);
	print_line(&vars->img, a, b);
}

void	creating_img(t_vars *vars)
{
	int		x;
	int		y;

	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			if ((y / TILE_SIZE) <= vars->fullmap->y_len)
			{
				if ((x / TILE_SIZE) <= vars->fullmap->x_len)
				{
					if (vars->fullmap->map[y / TILE_SIZE][x / TILE_SIZE] == 0)
						print_tile(&vars->img, x, y, 0x000000);
					else
						print_tile(&vars->img, x, y, 0xFFFFFF);
				}
			}
			x += TILE_SIZE;
		}
		y += TILE_SIZE;
	}
	draw_player(vars);
}
