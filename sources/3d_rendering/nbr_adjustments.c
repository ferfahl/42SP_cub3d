/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_adjustments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:22:57 by feralves          #+#    #+#             */
/*   Updated: 2023/08/20 15:42:47 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall_strip(t_cub *cub, int x)
{
	float	proj_height;

	proj_height = (TILE_SIZE / cub->rays[x].dist) * cub->fullmap->proj_plane;
	return (floor(proj_height));
}
