/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:01:40 by feralves          #+#    #+#             */
/*   Updated: 2023/08/19 14:25:08 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	ray->wall_hit[X] = 0;
	ray->wall_hit[Y] = 0;
	ray->was_hit_vert = FALSE;
}

float	get_dist(float player[2], float ref[2])
{
	if (ref[X] == 0 && ref[Y] == 0)
		return (MAX_FLT);
	else
		return (dist_points(player[X], player[Y], ref[X], ref[Y]));
}
