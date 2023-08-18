/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hit_horz.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:20:51 by feralves          #+#    #+#             */
/*   Updated: 2023/08/17 20:27:35 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//find the closest horizontal grid intersection (x, y)
t_point	h_intercept(t_player *player, t_rays ray)
{
	t_point	intercept;

	intercept.y = floor(player->y / TILE_SIZE) * TILE_SIZE;
	if (ray.facing_down)
		intercept.y += TILE_SIZE;
	intercept.x = player->x + (intercept.y - player->y) / tan(ray.angle);
	return (intercept);
}

//calculate the increment xstep and ystep (delta)
t_point	h_steped(t_rays ray)
{
	t_point	step;

	step.y = TILE_SIZE;
	if (ray.facing_up)
		step.y *= -1;
	step.x = TILE_SIZE / tan(ray.angle);
	if (ray.facing_left && step.x > 0)
		step.x *= -1;
	else if (ray.facing_right && step.x < 0)
		step.x *= -1;
	return (step);
}

t_point	increment_horz(t_map *map, t_rays ray, t_point intercept, t_point step)
{
	t_point	check;
	t_point	horz;

	horz = intercept;
	while (horz.x >= 0 && horz.x <= map->x_len && horz.y >= 0
		&& horz.y <= map->y_len)
	{
		check.x = horz.x;
		if (ray.facing_up)
			check.y = horz.y - 1;
		else
			check.y = horz.y;
		if (map_wall(map, check.x, check.y))
			return (horz);
		else
		{
			horz.x += step.x;
			horz.y += step.y;
		}
	}
	horz.x = 0;
	horz.y = 0;
	return (horz);
}

t_point	get_horz_hit(t_vars *vars, t_rays ray)
{
	t_point	intercept;
	t_point	step;
	t_point	horz;

	intercept = h_intercept(vars->player, ray);
	step = h_steped(ray);
	horz = increment_horz(vars->fullmap, ray, intercept, step);
	return (horz);
}
