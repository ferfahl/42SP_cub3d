/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:55:34 by feralves          #+#    #+#             */
/*   Updated: 2023/08/20 23:59:14 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)map->y_len / TILE_SIZE)
	{
		j = 0;
		while (j < (int)map->x_len / TILE_SIZE)
		{
			ft_printf("%d", map->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

t_player	*start_player(t_map *map)
{
	t_player	*p1;

	p1 = malloc(sizeof(t_player));
	p1->pos[X] = map->x_len / 2;
	p1->pos[Y] = map->y_len / 2;
	p1->turn_direction = 0;
	p1->walk_direction = 0;
	p1->angle = PI / 2;
	return (p1);
}

int	main(void)
{
	t_map		*map;
	t_player	*p1;

	map = map_maker();
	p1 = start_player(map);
	start_game(map, p1);
}
