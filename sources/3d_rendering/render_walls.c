/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:30:47 by feralves          #+#    #+#             */
/*   Updated: 2023/08/20 17:45:31 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_walls(t_cub *cub, int x, int y)
{
	if (cub->rays[x].was_hit_vert)
	{
		if (cub->rays[x].facing_left)
			my_mlx_pixel_put(&cub->img, x, y, 0xFF00FF); //west
		else
			my_mlx_pixel_put(&cub->img, x, y, 0xFF0000); //east
	}
	else
	{
		if (cub->rays[x].facing_up)
			my_mlx_pixel_put(&cub->img, x, y, 0xFF0000); //north
		else
			my_mlx_pixel_put(&cub->img, x, y, 0xFF0000); //south
	}
}

void	generate_projection(t_cub *cub)
{
	int	x;
	int	y;
	int	wall_strip_height;
	int	wall_top_pixel;
	int	wall_bot_pixel;

	x = 0;
	while (x < cub->nbr_rays)
	{
		wall_strip_height = wall_strip(cub, x);
		wall_top_pixel = (W_HEIGHT / 2) - (wall_strip_height / 2);
		if (wall_top_pixel < 0)
			wall_top_pixel = 0;
		wall_bot_pixel = (W_HEIGHT / 2) + (wall_strip_height / 2);
		if (wall_bot_pixel > W_HEIGHT)
			wall_bot_pixel = W_HEIGHT;
		y = wall_top_pixel;
		while (y < wall_bot_pixel)
		{
			render_walls(cub, x, y);
			y++;
		}
		x++;
	}
}
