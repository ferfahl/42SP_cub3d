/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:01:40 by feralves          #+#    #+#             */
/*   Updated: 2023/08/22 10:49:54 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	start_ray(t_rays *ray, t_player *player, float angle)
{
	ray->angle = angle;
	ray->facing_down = is_facing_down(ray->angle);
	ray->facing_up = is_facing_up(ray->angle);
	ray->facing_left = is_facing_left(ray->angle);
	ray->facing_right = is_facing_right(ray->angle);
	ray->init[X] = player->pos[X];
	ray->init[Y] = player->pos[Y];
	ray->dist = 0;
	ray->hit[X] = 0;
	ray->hit[Y] = 0;
	ray->was_hit_vert = FALSE;
}

float	get_dist(t_player *p, t_hit h)
{
	float	dist;

	if (h.hitted)
		dist = dist_points(p->pos[X], p->pos[Y], h.hit[X], h.hit[Y]);
	else
		dist = MAX_FLT;
	return (dist);
}
