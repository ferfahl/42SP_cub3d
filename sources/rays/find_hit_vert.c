/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hit_vert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:20:51 by feralves          #+#    #+#             */
/*   Updated: 2023/08/17 20:14:44 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	v_intercept(t_vars *vars, t_rays ray)
{
	t_point	intercept;

	intercept.x = floor(vars->player->x / TILE_SIZE) * TILE_SIZE;
	if (ray.facing_right)
		intercept.x += TILE_SIZE;
	intercept.y = vars->player->y + (intercept.x
			- vars->player->x) * tan(ray.angle);
	return (intercept);
}

t_point	v_steped(t_rays ray)
{
	t_point	step;

	step.x = TILE_SIZE;
	if (ray.facing_left)
		step.x *= -1;
	step.y = TILE_SIZE * tan(ray.angle);
	if (ray.facing_up && step.y > 0)
		step.y *= -1;
	else if (ray.facing_down && step.y < 0)
		step.y *= -1;
	return (step);
}

t_point	increment_vert(t_map *map, t_rays ray, t_point intercept, t_point step)
{
	t_point	check;
	t_point	vert;

	vert = intercept;
	while (vert.x >= 0 && vert.x <= map->x_len && vert.y >= 0
		&& vert.y <= map->y_len)
	{
		check.x = vert.x;
		check.y = vert.y;
		if (ray.facing_up)
			check.y -= 1;
		if (map_wall(map, check.x, check.y))
			return (vert);
		else
		{
			vert.x += step.x;
			vert.y += step.y;
		}
	}
	vert.x = 0;
	vert.y = 0;
	return (vert);
}

t_point	get_vert_hit(t_vars *vars, t_rays ray)
{
	t_point	intercept;
	t_point	step;
	t_point	vert;

	intercept = v_intercept(vars, ray);
	step = v_steped(ray);
	vert = increment_vert(vars->fullmap, ray, intercept, step);
	return (vert);
}
