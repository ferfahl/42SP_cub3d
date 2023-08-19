/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hit_vert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:20:51 by feralves          #+#    #+#             */
/*   Updated: 2023/08/19 16:30:40 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	v_intercept(t_player *player, t_rays ray, t_hit *vert)
{
	float	x_diff;

	vert->intercept[X] = floor(player->pos[X] / TILE_SIZE) * TILE_SIZE;
	if (ray.facing_right)
		vert->intercept[X] += TILE_SIZE;
	if (ray.facing_left)
		vert->intercept[X] -= 0.0001;
	x_diff = vert->intercept[X] - player->pos[X];
	vert->intercept[Y] = player->pos[Y] + (x_diff) * tan(ray.angle);
}

void	v_steped(t_rays ray, t_hit *vert)
{
	vert->step[X] = TILE_SIZE;
	if (ray.facing_left)
		vert->step[X] *= -1;
	vert->step[Y] = TILE_SIZE * tan(ray.angle);
	if (ray.facing_up && vert->step[Y] > 0)
		vert->step[Y] *= -1;
	else if (ray.facing_down && vert->step[Y] < 0)
		vert->step[Y] *= -1;
}

void	increment_vert(t_map *map, t_rays ray, t_hit *vert)
{
	float	check[2];

	vert->hitted = FALSE;
	vert->hit[X] = vert->intercept[X];
	vert->hit[Y] = vert->intercept[Y];
	while (vert->hit[X] >= 0 && vert->hit[X] <= map->x_len && vert->hit[Y] >= 0
		&& vert->hit[Y] <= map->y_len)
	{
		check[X] = vert->hit[X];
		check[Y] = vert->hit[Y];
		if (ray.facing_left)
			check[Y] -= 1;
		if (map_wall(map, check[X], check[Y]))
		{
			vert->hitted = TRUE;
			return ;
		}
		else
		{
			vert->hit[X] += vert->step[X];
			vert->hit[Y] += vert->step[Y];
		}
	}
	vert->hit[X] = 0;
	vert->hit[Y] = 0;
}

t_hit	get_vert_hit(t_cub *cub, t_rays ray)
{
	t_hit	vert;

	v_intercept(cub->player, ray, &vert);
	v_steped(ray, &vert);
	increment_vert(cub->fullmap, ray, &vert);
	vert.distance = get_dist(cub->player, vert);
	return (vert);
}
