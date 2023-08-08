/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:30:10 by feralves          #+#    #+#             */
/*   Updated: 2023/08/08 19:38:31 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "buttons.h"

void	fill_img(t_vars *vars)
{
	int		count_w;
	int		count_h;

	count_h = -1;
	while (++count_h < W_HEIGHT)
	{
		count_w = -1;
		while (++count_w < W_WIDTH)
		{
			vars->img.data[count_h * W_WIDTH + count_w] = 0;
		}
	}
}

void	creating_img(t_vars *vars)
{
	int		count_w;
	int		count_h;

	count_h = -1;
	while (++count_h < W_HEIGHT)
	{
		count_w = -1;
		while (++count_w < W_WIDTH)
		{
			if (count_w % 2)
				my_mlx_pixel_put(&vars->img, count_w, count_h, 0x0000FF);
			else
				my_mlx_pixel_put(&vars->img, count_w, count_h, 0xFF0000);
		}
	}
}

void	open_window(t_map *map)
{
	t_vars	*vars;

	vars = (t_vars *)ft_calloc(1, sizeof(t_vars));
	if (vars == NULL)
		if_error("Calloc error");
	vars->fullmap = map;
	// vars->img = create_image(vars->mlx);
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		if_error("Mlx init error");
	vars->win = mlx_new_window(vars->mlx, W_WIDTH, W_HEIGHT, "cub3D");
	if (vars->win == NULL)
		if_error("Mlx vars->window error");
	vars->img = create_image(vars->mlx);
	fill_img(vars);
	creating_img(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.ptr, 0, 0);
	mlx_hook(vars->win, KEY_PRESS_EVENT, (1L << 0), key_hook, vars);
	mlx_hook(vars->win, CLICK_EVENT, (1L << 2), click_hook, vars);
	mlx_loop(vars->mlx);
}
