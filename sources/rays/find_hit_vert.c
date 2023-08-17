/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hit_vert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:20:51 by feralves          #+#    #+#             */
/*   Updated: 2023/08/17 15:48:47 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	v_intercept(t_vars *vars, t_rays ray)
{
	t_point	intercept;

	intercept.x = floor(vars->player->x / MAP_RAY) * MAP_RAY;
	// intercept.x = floor(vars->player->x / TILE_SIZE) * TILE_SIZE;
	if (ray.facing_right)
		intercept.x += MAP_RAY;
	// printf("YYYplayer[%f,%f]\tangle:%f\ttan:%f\n", vars->player->x, vars->player->y, ray.angle, tan(ray.angle));
	intercept.y = vars->player->y + (intercept.x
				- vars->player->x) * tan(ray.angle);
	return (intercept);
}

t_point	v_steped(t_rays ray)
{
	t_point	step;

	step.x = MAP_RAY;
	if (ray.facing_left)
		step.x *= -1;
	step.y = MAP_RAY * tan(ray.angle);
	if (ray.facing_up && step.y > 0)
		step.y *= -1;
	else if (ray.facing_down && step.y < 0)
		step.y *= -1;
	return (step);
}

t_point	get_vert_hit(t_vars *vars, t_rays ray)
{
	t_point	check;
	t_point	vert;
	t_point	intercept;
	t_point	step;
	t_point	control;
	int		checking;

	checking = FALSE;
	control.x = 0;
	control.y = 0;
	intercept = v_intercept(vars, ray);
	step = v_steped(ray);
	vert = intercept;
	while (vert.x >= 0 && vert.x <= vars->fullmap->x_len && vert.y >= 0
		&& vert.y <= vars->fullmap->y_len)
	{
		check.x = vert.x;
		check.y = vert.y;
		if (ray.facing_up)
			check.y += -1;
		if (map_wall(vars->fullmap, check.x, check.y))
		{
			checking = TRUE;
			break ;
		}
		else
		{
			vert.x += step.x;
			vert.y += step.y;
		}
	}
	if (checking)
		return (vert);
	else
		return (control);
}
