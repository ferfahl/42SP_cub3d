/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:55:34 by feralves          #+#    #+#             */
/*   Updated: 2023/08/21 16:33:18 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	generate_reverse_xpm(char *old, char *new);

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < (int)map->y_len / TILE_SIZE)
	{
		for (int j = 0; j < (int)map->x_len / TILE_SIZE; j++)
		{
			ft_printf("%d", map->map[i][j]);
		}
		ft_printf("\n");
		i++;
	}
}

int	main(void)
{
	t_map		*map;
	t_player	*p1;

	map = map_maker();
	p1 = start_player(map);
	start_game(map, p1);
}
