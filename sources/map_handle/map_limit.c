/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_limit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:31:40 by feralves          #+#    #+#             */
/*   Updated: 2023/08/17 16:02:55 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_wall(t_map *mapped, float x, float y)
{
	int	x_grid;
	int	y_grid;

	if (x < 0 || x > (float)mapped->x_len || y < 0 || y > (float)mapped->y_len)
		return (TRUE);
	x_grid = floor(x / MAP_RAY);
	y_grid = floor(y / MAP_RAY);
	if (mapped->map[y_grid][x_grid] == 1)
		return (TRUE);
	return (FALSE);
}
