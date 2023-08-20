/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hit_horz.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:20:51 by feralves          #+#    #+#             */
/*   Updated: 2023/08/19 21:35:55 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//find the closest horizontal grid intersection (x, y)
void	h_intercept(t_player *player, t_rays ray, t_hit *horz)
{
	float	y_diff;

	horz->intercept[Y] = floor(player->pos[Y] / TILE_SIZE) * TILE_SIZE;
	if (ray.facing_up)
		horz->intercept[Y] -= 0.0001;
	if (ray.facing_down)
		horz->intercept[Y] += TILE_SIZE;
	y_diff = horz->intercept[Y] - player->pos[Y];
	horz->intercept[X] = player->pos[X] + (y_diff) / tan(ray.angle);
}

//calculate the increment xstep and ystep (delta)
void	h_steped(t_rays ray, t_hit *horz)
{
	horz->step[Y] = TILE_SIZE;
	if (ray.facing_up)
		horz->step[Y] *= -1;
	horz->step[X] = TILE_SIZE / tan(ray.angle);
	if (ray.facing_left && horz->step[X] > 0)
		horz->step[X] *= -1;
	else if (ray.facing_right && horz->step[X] < 0)
		horz->step[X] *= -1;
}

void	increment_horz(t_map *map, t_rays ray, t_hit *horz)
{
	float	check[2];

	horz->hitted = FALSE;
	horz->hit[X] = horz->intercept[X];
	horz->hit[Y] = horz->intercept[Y];
	while (horz->hit[X] >= 0 && horz->hit[X] <= map->x_len && horz->hit[Y] >= 0
		&& horz->hit[Y] <= map->y_len)
	{
		check[X] = horz->hit[X];
		check[Y] = horz->hit[Y];
		if (ray.facing_up)
			check[Y] -= 1;
		if (map_wall(map, check[X], check[Y]))
		{
			horz->hitted = TRUE;
			return ;
		}
		else
		{
			horz->hit[X] += horz->step[X];
			horz->hit[Y] += horz->step[Y];
		}
	}
	horz->hit[X] = 0;
	horz->hit[Y] = 0;
}

t_hit	get_horz_hit(t_cub *cub, t_rays ray)
{
	t_hit	horz;

	h_intercept(cub->player, ray, &horz);
	h_steped(ray, &horz);
	increment_horz(cub->fullmap, ray, &horz);
	horz.distance = get_dist(cub->player, horz);
	return (horz);
}
