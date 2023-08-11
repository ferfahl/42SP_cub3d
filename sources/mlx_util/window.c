/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:30:10 by feralves          #+#    #+#             */
/*   Updated: 2023/08/11 19:05:14 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "buttons.h"

void	fill_img(t_vars *vars)
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
	map_x = 0;
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
			// if (!(x % (TILE_SIZE * 2)) && y % (TILE_SIZE * 2))
			// 	print_tile(&vars->img, x, y, 0xFFFF00);
			// else if (x % (TILE_SIZE * 2) && !(y % (TILE_SIZE * 2)))
			// 	print_tile(&vars->img, x, y, 0x00FF00);
			// else if (!(x % (TILE_SIZE * 2)) && !(y % (TILE_SIZE * 2)))
			// 	print_tile(&vars->img, x, y, 0x000000);
			// else
			// 	print_tile(&vars->img, x, y, 0xFF0000);
			map_x++;
			x += TILE_SIZE;
		}
		map_y++;
		y += TILE_SIZE;
	}
}

void	open_window(t_map *map, t_player *p1)
{
	t_vars	*vars;

	vars = (t_vars *)ft_calloc(1, sizeof(t_vars));
	if (vars == NULL)
		if_error("Calloc error");
	vars->fullmap = map;
	vars->player = p1;
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		if_error("Mlx init error");
	vars->win = mlx_new_window(vars->mlx, W_WIDTH, W_HEIGHT, "cub3D");
	if (vars->win == NULL)
		if_error("Mlx vars->window error");
	vars->img = create_var_image(vars->mlx);
	fill_img(vars);
	creating_img(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.ptr, 0, 0);
	mlx_hook(vars->win, KEY_PRESS_EVENT, (1L << 0), key_hook, vars);
	mlx_hook(vars->win, CLICK_EVENT, (1L << 2), click_hook, vars);
	mlx_loop(vars->mlx);
}
