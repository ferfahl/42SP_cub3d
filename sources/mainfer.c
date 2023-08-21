/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:42:06 by feralves          #+#    #+#             */
/*   Updated: 2023/08/21 17:00:42 by feralves         ###   ########.fr       */
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


int	main(void)
{
	t_map		*map;
	int			coord[2];

	coord[X] = 26;
	coord[Y] = 11;
	map = map_maker();
	verify_path(map, coord);
	free(map);
}

