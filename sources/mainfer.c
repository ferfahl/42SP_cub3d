/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:42:06 by feralves          #+#    #+#             */
/*   Updated: 2023/08/21 13:29:17 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_map *map, int **draw)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)map->y_len / TILE_SIZE)
	{
		j = 0;
		while (j < (int)map->x_len / TILE_SIZE)
		{
			ft_printf("%d", draw[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	flood_fill(int **dupe, int x, int y, t_map *map)
{
	if (y <= 1 || x <= 1 || y >= map->y_len - 1 || x >= map->x_len - 1)
		return ;
	// if (dupe[y][x] == 1 || dupe[y][x] == 7 || dupe[y][x] == 8)
	if (dupe[y][x] == 1)
		return ;
	if (dupe[y][x] == 7 || dupe[y][x] == 8)
		return ;
	if (dupe[y][x] == 9)
		dupe[y][x] = 8;
	else
		dupe[y][x] = 7;
	flood_fill(dupe, x + 1, y, map);
	flood_fill(dupe, x - 1, y, map);
	flood_fill(dupe, x, y + 1, map);
	flood_fill(dupe, x, y - 1, map);
}

void	verify_path(int **map, int coord[2], t_map *full_map)
{
	int	**dupe;

	dupe = map;
	// dupe[coord[Y]][coord[X]] = 7;
	flood_fill(dupe, coord[X], coord[Y], full_map);
	print_map(full_map, dupe);
	
}

int	main(void)
{
	t_map		*map;
	int			coord[2];

	coord[X] = 26;
	coord[Y] = 11;
	map = map_maker();
	printf("map before:\n");
	print_map(map, map->map);
	printf("map after:\n");
	verify_path(map->map, coord, map);
	free(map);
}

