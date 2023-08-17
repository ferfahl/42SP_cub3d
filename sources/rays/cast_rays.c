/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:04:12 by feralves          #+#    #+#             */
/*   Updated: 2023/08/17 18:04:38 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	find_hit(t_vars *vars, t_player *player, t_rays *ray)
{
	t_point	horz;
	t_point	vert;
	float	dist_horz;
	float	dist_vert;

	horz = get_horz_hit(vars, *ray);
	vert = get_vert_hit(vars, *ray);
	dist_horz = get_dist(player, horz);
	dist_vert = get_dist(player, vert);
	if (dist_horz > dist_vert)
	{
		ray->dist = dist_vert;
		ray->wall_hit.x = vert.x;
		ray->wall_hit.y = vert.y;
		ray->was_hit_vert = TRUE;
	}
	else
	{
		ray->dist = dist_horz;
		ray->wall_hit.x = horz.x;
		ray->wall_hit.y = horz.y;
		ray->was_hit_vert = FALSE;
	}
}

void	single_ray(t_vars *vars, t_rays *ray)
{
	find_hit(vars, vars->player, ray);
}

void	cast_all_rays(t_vars *vars)
{
	int		pixel_col;
	float	angle;
	float	step;

	pixel_col = 0;
	step = FOV / vars->nbr_rays;
	angle = vars->player->angle - HALF_FOV;
	while (pixel_col < vars->nbr_rays)
	{
		angle = normalize_angle(angle);
		start_ray(&vars->rays[pixel_col], vars->player, angle);
		single_ray(vars, &vars->rays[pixel_col]);
		angle += step;
		pixel_col++;
	}
}
