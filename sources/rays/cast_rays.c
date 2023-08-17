/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:04:12 by feralves          #+#    #+#             */
/*   Updated: 2023/08/17 16:23:13 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	start_ray(t_rays *ray, t_player *player, float angle)
{
	ray->angle = angle;
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
	if (horz.x == 0 && horz.y == 0)
		dist_horz = 2000000000;
	else
		dist_horz = dist_points(vars->player->x, horz.x, vars->player->y, horz.y);
	if (vert.x == 0 && vert.y == 0)
		dist_vert = 2000000000;
	else
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

void	single_ray(t_vars *vars, t_rays *ray)
{
	t_pos	test;
	t_pos	hit_test;

	find_hit(vars, ray);
	test.x = floor(ray->init.x * MAP_SCALE);
	test.y = floor(ray->init.y * MAP_SCALE);
	hit_test.x = floor(ray->wall_hit.x * MAP_SCALE);
	hit_test.y = floor(ray->wall_hit.y * MAP_SCALE);
	// printf("player [%d,%d]\twallhit [%d,%d]\n", test.x, test.y, hit_test.x, hit_test.y);
	draw_line(&vars->img, test, hit_test, 0x00FF00);
}

void	cast_all_rays(t_vars *vars)
{
	int		pixel_col;
	float	angle;

	pixel_col = 0;
	float step = FOV / vars->nbr_rays;
	angle = vars->player->angle - HALF_FOV;
	while (pixel_col < vars->nbr_rays)
	{
		angle = normalize_angle(angle);
		start_ray(&vars->rays[pixel_col], vars->player, angle);
		single_ray(vars, &vars->rays[pixel_col]);
		// if (pixel_col == 1)
		// 	printf("ray init [%f,%f]\tray hit [%f,%f]\n", vars->rays[pixel_col].init.x, vars->rays[pixel_col].init.y, vars->rays[pixel_col].wall_hit.x, vars->rays[pixel_col].wall_hit.y);
		angle += step;
		pixel_col++;
	}
}
