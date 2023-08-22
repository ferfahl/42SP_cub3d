/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:59:02 by feralves          #+#    #+#             */
/*   Updated: 2023/08/22 10:48:34 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	flood_fill(int **dupe, int x, int y, t_map *map)
{
	int	max_x;
	int	max_y;

	max_x = map->x_len / TILE_SIZE;
	max_y = map->y_len / TILE_SIZE;
	if (y < 0 || x < 0 || y >= max_y || x >= max_x)
		return ;
	if (dupe[y][x] == 1 || dupe[y][x] == 3 || dupe[y][x] == 2)
		return ;
	if (dupe[y][x] == 9 || y == 0 || x == 0 || x == max_x - 1 || y == max_y - 1)
		dupe[y][x] = 2;
	else
		dupe[y][x] = 3;
	flood_fill(dupe, x + 1, y, map);
	flood_fill(dupe, x - 1, y, map);
	flood_fill(dupe, x, y + 1, map);
	flood_fill(dupe, x, y - 1, map);
}

int	**duplicate_map(t_map *map)
{
	int	**dupe;
	int	x;
	int	y;

	y = 0;
	dupe = malloc(sizeof(int *) * map->y_len / TILE_SIZE);
	while (y < map->y_len / TILE_SIZE)
	{
		x = 0;
		dupe[y] = malloc(sizeof(int) * map->x_len / TILE_SIZE);
		while (x < map->x_len / TILE_SIZE)
		{
			dupe[y][x] = map->map[y][x];
			x++;
		}
		y++;
	}
	return (dupe);
}

int	valid_dupe_check(int c)
{
	if (c == 1 || c == 0 || c == 9)
		return (TRUE);
	else if (c == 5 || c == 6 || c == 7 || c == 8)
		return (TRUE);
	else if (c == 3)
		return (TRUE);
	return (FALSE);
}

int	check_dupe(t_map *map, int **dupe)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y_len / TILE_SIZE)
	{
		x = 0;
		while (x < map->x_len / TILE_SIZE)
		{
			if (!valid_dupe_check(dupe[y][x]))
				return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}

int	verify_path(t_map *map, int x, int y)
{
	int	**dupe;

	dupe = duplicate_map(map);
	flood_fill(dupe, x, y, map);
	if (!check_dupe(map, dupe))
	{
		ft_free_map_array(dupe, map->y_len / TILE_SIZE);
		return (ft_error("Invalid path"));
	}
	ft_free_map_array(dupe, map->y_len / TILE_SIZE);
	return (0);
}
