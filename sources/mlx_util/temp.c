/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:02:14 by feralves          #+#    #+#             */
/*   Updated: 2023/08/15 18:28:00 by feralves         ###   ########.fr       */
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

void	creating_img(t_vars *vars)
{
	draw_mini_map(vars, vars->fullmap);
	cast_all_rays(vars);
}
