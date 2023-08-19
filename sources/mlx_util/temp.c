/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:02:14 by feralves          #+#    #+#             */
/*   Updated: 2023/08/19 15:52:51 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_background(t_cub *cub)
{
	int	x;
	int	y;
	int	ceiling;
	int	floor;

	y = 0;
	floor = cub->fullmap->floor;
	ceiling = cub->fullmap->ceiling;
	while (y < W_HEIGHT / 2)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			my_mlx_pixel_put(&cub->img, x, y, ceiling);
			my_mlx_pixel_put(&cub->img, x, y + W_HEIGHT / 2, floor);
			x++;
		}
		y++;
	}
}

void	creating_img(t_cub *cub)
{
	cast_all_rays(cub);
	generate_projection(cub);
	draw_mini_map(cub, cub->fullmap);
}
