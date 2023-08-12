/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:31:40 by feralves          #+#    #+#             */
/*   Updated: 2023/08/12 15:13:59 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_wall(t_map *mapped, float x, float y)
{
	int	x_grid;
	int	y_grid;

	if (x < 0 || x > (float)mapped->x_len || y < 0 || y > (float)mapped->y_len)
		return (TRUE);
	x_grid = floor(x / TILE_SIZE);
	y_grid = floor(y / TILE_SIZE);
	if (mapped->map[x_grid][y_grid] == 0)
		return (TRUE);
	return (FALSE);
}
