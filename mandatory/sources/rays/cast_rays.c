/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:04:12 by feralves          #+#    #+#             */
/*   Updated: 2023/08/19 16:24:02 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_closest_wall(t_hit *h, t_hit *v, t_player *p, float angle)
{
	float	fish_eye;

	fish_eye = cos(p->angle - angle);
	if (h->hitted)
		h->distance = h->distance * fish_eye;
	else
		h->distance = MAX_FLT;
	if (v->hitted)
		v->distance = v->distance * fish_eye;
	else
		v->distance = MAX_FLT;
}

void	find_hit(t_cub *cub, t_player *player, t_rays *ray)
{
	t_hit	horz;
	t_hit	vert;

	horz = get_horz_hit(cub, *ray);
	vert = get_vert_hit(cub, *ray);
	find_closest_wall(&horz, &vert, player, ray->angle);
	if (horz.distance > vert.distance)
	{
		ray->dist = vert.distance;
		ray->hit[X] = vert.hit[X];
		ray->hit[Y] = vert.hit[Y];
		ray->was_hit_vert = TRUE;
	}
	else
	{
		ray->dist = horz.distance;
		ray->hit[X] = horz.hit[X];
		ray->hit[Y] = horz.hit[Y];
		ray->was_hit_vert = FALSE;
	}
}

void	cast_all_rays(t_cub *cub)
{
	int		pixel_col;
	float	angle;
	float	step;

	pixel_col = 0;
	step = FOV / cub->nbr_rays;
	angle = cub->player->angle - HALF_FOV;
	while (pixel_col < cub->nbr_rays)
	{
		angle = normalize_angle(angle);
		start_ray(&cub->rays[pixel_col], cub->player, angle);
		find_hit(cub, cub->player, &cub->rays[pixel_col]);
		angle += step;
		pixel_col++;
	}
}
