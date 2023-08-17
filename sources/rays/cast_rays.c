/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:04:12 by feralves          #+#    #+#             */
/*   Updated: 2023/08/16 12:06:18 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	start_ray(t_rays *ray, t_player *player, float angle)
{
	ray->angle = normalize_angle(angle);
	ray->facing_down = is_facing_down(ray->angle);
	ray->facing_up = is_facing_up(ray->angle);
	ray->facing_left = is_facing_left(ray->angle);
	ray->facing_right = is_facing_right(ray->angle);
	ray->init.x = player->x;
	ray->init.y = player->y;
	ray->dist = 0;
	ray->wall_hit.x = 0;
	ray->wall_hit.y = 0;
	ray->was_hit_vert = FALSE;
}

void	find_hit(t_vars *vars, t_rays *ray)
{
	t_point	horz;
	t_point	vert;
	float	dist_horz;
	float	dist_vert;

	horz = get_horz_hit(vars, *ray);
	vert = get_vert_hit(vars, *ray);
	dist_horz = dist_points(vars->player->x, horz.x, vars->player->y, horz.y);
	dist_vert = dist_points(vars->player->x, vert.x, vars->player->y, vert.y);
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

void	single_ray(t_vars *vars, t_rays ray)
{
	t_pos	test;
	t_pos	hit_test;

	find_hit(vars, &ray);
	test.x = floor(ray.init.x * MAP_SCALE);
	test.y = floor(ray.init.y * MAP_SCALE);
	hit_test.x = floor(ray.wall_hit.x * MAP_SCALE);
	hit_test.y = floor(ray.wall_hit.y * MAP_SCALE);
	print_line(&vars->img, test, hit_test, 0x00FF00);
}

void	cast_all_rays(t_vars *vars)
{
	int		col;
	float	dist_proj;
	float	map_w;
	float	angle;

	col = 1;
	map_w = ((vars->fullmap->x_len + 1) * TILE_SIZE) / 2;
	dist_proj = map_w / tan(FOV / 2);
	while (col < vars->nbr_rays)
	{
		angle = vars->player->angle + atan((col - vars->nbr_rays / 2) / dist_proj);
		start_ray(&vars->rays[col], vars->player, angle);
		single_ray(vars, vars->rays[col]);
		col++;
	}
}
