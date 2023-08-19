/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:30:47 by feralves          #+#    #+#             */
/*   Updated: 2023/08/19 16:15:59 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	generate_projection(t_cub *cub)
{
	for (int i = 0; i < cub->nbr_rays; i++)
	{
		float	proj_plane = (cub->fullmap->x_len / 2) / tan(FOV / 2);
		float	proj_wall_height = (TILE_SIZE / cub->rays[i].dist) * proj_plane;

		int	wall_strip_height = (int)proj_wall_height;

		int	wall_top_pixel = (W_HEIGHT / 2) - (wall_strip_height / 2);
		if (wall_top_pixel < 0)
			wall_top_pixel = 0;
		
		int wall_bot_pixel = (W_HEIGHT / 2) + (wall_strip_height / 2);
		if (wall_bot_pixel > W_HEIGHT)
			wall_bot_pixel = W_HEIGHT;

		// int	offset_x;
		//render the wall from limits above
		// if (cub->rays[i].was_hit_vert)
		// 	offset_x = (int)cub->rays[i].hit[Y] % TILE_SIZE;
		// else
			// offset_x = (int)cub->rays[i].hit[X] % TILE_SIZE;

		for (int y = wall_top_pixel; y < wall_bot_pixel; y++)
		{
			// int	distFromTop = (y + (wall_strip_height / 2) - (W_HEIGHT / 2));
			// int offsetY = distFromTop * wall_strip_height;

			my_mlx_pixel_put(&cub->img, i, y, 0xFF0000);
        }
	}
}
