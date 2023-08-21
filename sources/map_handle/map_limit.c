/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_limit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:31:40 by feralves          #+#    #+#             */
/*   Updated: 2023/08/20 20:19:39 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_wall(t_map *map, float x, float y)
{
	int	x_grid;
	int	y_grid;

	if (x < 0 || x > (float)map->x_len || y < 0 || y > (float)map->y_len)
		return (TRUE);
	x_grid = floor(x / TILE_SIZE);
	y_grid = floor(y / TILE_SIZE);
	if (map->map[y_grid][x_grid] == 1)
		return (TRUE);
	return (FALSE);
}

int	map_floor(t_map *map, float x, float y)
{
	int	x_grid;
	int	y_grid;

	if (x < 0 || x > (float)map->x_len || y < 0 || y > (float)map->y_len)
		return (TRUE);
	x_grid = floor(x / TILE_SIZE);
	y_grid = floor(y / TILE_SIZE);
	if (map->map[y_grid][x_grid] == 0)
		return (TRUE);
	return (FALSE);
}
