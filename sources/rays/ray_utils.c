/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:01:40 by feralves          #+#    #+#             */
/*   Updated: 2023/08/19 13:09:44 by feralves         ###   ########.fr       */
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
	ray->init.x = player->x;
	ray->init.y = player->y;
	ray->dist = 0;
	ray->wall_hit.x = 0;
	ray->wall_hit.y = 0;
	ray->was_hit_vert = FALSE;
}

float	get_dist(t_player *player, t_point ref)
{
	if (ref.x == 0 && ref.y == 0)
		return (MAX_FLT);
	else
		return (dist_points(player->x, player->y, ref.x, ref.y));
}
