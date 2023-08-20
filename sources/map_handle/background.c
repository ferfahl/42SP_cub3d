/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:15:59 by feralves          #+#    #+#             */
/*   Updated: 2023/08/20 15:16:22 by feralves         ###   ########.fr       */
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
