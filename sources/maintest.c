/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:55:34 by feralves          #+#    #+#             */
/*   Updated: 2023/08/21 21:58:15 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_map *map, int **print)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)map->y_len / TILE_SIZE)
	{
		j = 0;
		while (j < (int)map->x_len / TILE_SIZE)
			ft_printf("%d", print[i++][j++]);
		ft_printf("\n");
	}
}

int	main(int argc, char *argv[])
{
	t_input		*input;
	t_map		*map;
	t_player	*p1;

	input = start_input(argc, argv);
	if (input == NULL)
		return (-1);
	map = get_map(&input);
	if (map->map == NULL)
	{
		free_map(map);
		return (-1);
	}
	if (verify_path(map, input->player_y, input->player_x) == -1)
		exit (-1);
	exit(0);
	p1 = start_player(input->player_y, input->player_x, input->player_dir);
	free_input(input);
	start_game(map, p1);
}
