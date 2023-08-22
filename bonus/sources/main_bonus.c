/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:30:05 by feralves          #+#    #+#             */
/*   Updated: 2023/08/22 18:36:32 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	main(int argc, char *argv[])
{
	t_input		*input;
	t_map		*map;
	t_player	*p1;

	input = start_input(argc, argv);
	if (input == NULL)
		return (-1);
	map = get_map(&input);
	if (map == NULL)
		return (-1);
	if (map->map == NULL)
	{
		free_map(map);
		return (-1);
	}
	if (verify_path(map, input->player_y, input->player_x) == -1)
	{
		free_map(map);
		free_input(input);
		return (-1);
	}
	p1 = start_player(input->player_y, input->player_x, input->player_dir);
	free_input(input);
	start_game(map, p1);
}
