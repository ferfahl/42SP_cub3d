/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:55:34 by feralves          #+#    #+#             */
/*   Updated: 2023/08/15 15:05:04 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*temp_map[13] = {
	(int [20]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1},
	(int [20]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	(int [20]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	(int [20]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	(int [20]){1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
	(int [20]){1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	(int [20]){1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	(int [20]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	(int [20]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	(int [20]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	(int [20]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	(int [20]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	(int [20]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void	print_map(t_map *mapped)
{
	int	i;

	i = 0;
	while (i < (int)mapped->y_len)
	{
		for (int j = 0; j < (int)mapped->x_len; j++)
		{
			ft_printf("%d ", mapped->map[i][j]);
		}
		ft_printf("\n");
		i++;
	}
}

t_map	*map_maker(void)
{
	t_map	*mapped;
	mapped = malloc(sizeof(t_map));
	mapped->ceiling = 0xFF444444;
	mapped->floor = 0xFF000000;
	mapped->east = 0xFFFF0000;
	mapped->west = 0xFF00FF00;
	mapped->north = 0xFF0000FF;
	mapped->south = 0xFFFFFFFF;
	mapped->y_len = 12;
	mapped->x_len = 19;
	mapped->map = temp_map;
	return (mapped);
}

t_player	*start_player(t_map *map)
{
	t_player	*p1;

	p1 = malloc(sizeof(t_player));
	p1->x = map->x_len / 2;
	p1->y = map->y_len / 2;
	p1->turn_direction = 0;
	p1->walk_direction = 0;
	p1->angle = 270;
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
