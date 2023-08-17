/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hit_horz.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:20:51 by feralves          #+#    #+#             */
/*   Updated: 2023/08/17 00:32:12 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//find the closest horizontal grid intersection (x, y)
t_point	h_intercept(t_vars *vars, t_rays ray)
{
	t_point	intercept;

	intercept.y = floor(vars->player->y);
	// intercept.y = floor(vars->player->y / TILE_SIZE) * TILE_SIZE;
	// if (ray.facing_down)
	// 	intercept.y += TILE_SIZE;
	intercept.x = vars->player->x + (intercept.y
			- vars->player->y) / tan(ray.angle);
	return (intercept);
}

//calculate the increment xstep and ystep (delta)
t_point	h_steped(t_rays ray)
{
	t_point	step;

	step.y = 1;
	// if (ray.facing_up)
	// 	step.y *= -1;
	step.x = 1 / tan(ray.angle);
	// if (ray.facing_left && step.x > 0)
	// 	step.x *= -1;
	// else if (ray.facing_right && step.x < 0)
	// 	step.x *= -1;
	return (step);
}

t_point	get_horz_hit(t_vars *vars, t_rays ray)
{
	t_point	check;
	t_point	horz;
	t_point	intercept;
	t_point	step;
	t_point	control;
	int		checking;

	checking = FALSE;
	control.x = 0;
	control.y = 0;
	intercept = h_intercept(vars, ray);
	step = h_steped(ray);
	horz = intercept;
	while (horz.x >= 0 && horz.x <= vars->fullmap->x_len && horz.y >= 0
		&& horz.y <= vars->fullmap->y_len)
	{
		check.x = horz.x;
		check.y = horz.y;
		// if (ray.facing_up)
		// 	check.y = horz.y - 1;
		// else
		if (map_wall(vars->fullmap, check.x, check.y))
		{
			checking = TRUE;
			break ;
		}
		else
		{
			horz.x += step.x;
			horz.y += step.y;
		}
	}
	if (checking)
		return (horz);
	else
		return (control);
}
