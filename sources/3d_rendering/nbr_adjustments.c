/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_adjustments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:22:57 by feralves          #+#    #+#             */
/*   Updated: 2023/08/20 21:06:35 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall_strip(t_cub *cub, int x)
{
	float	proj_height;

	proj_height = (TILE_SIZE / cub->rays[x].dist) * cub->map->proj_plane;
	return (floor(proj_height));
}

int	top_bot_pixel(t_cub *cub, int x, int control)
{
	int	value;
	int	wall_strip_height;

	wall_strip_height = wall_strip(cub, x);
	if (control)
	{
		value = (W_HEIGHT / 2) - (wall_strip_height / 2);
		if (value < 0)
			value = 0;
	}
	else
	{
		value = (W_HEIGHT / 2) + (wall_strip_height / 2);
		if (value > W_HEIGHT)
			value = W_HEIGHT;
	}
	return (value);
}

int	texture_offset_x(t_rays ray)
{
	int	offset_x;

	if (ray.was_hit_vert)
		offset_x = (int)ray.hit[Y] % TEXTURE_SIZE;
	else
		offset_x = (int)ray.hit[X] % TEXTURE_SIZE;
	return (offset_x);
}
