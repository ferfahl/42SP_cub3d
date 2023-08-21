/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:55:34 by feralves          #+#    #+#             */
/*   Updated: 2023/08/21 16:33:41 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

t_map	*map_reader(int fd, t_input *input)
{
	t_map	*map;
	map = malloc(sizeof(t_map));
	map->ceiling = input->c;
	map->floor = input->f;
	map->east = input->ea_path;
	map->north = input->no_path;
	map->west = ft_strdup("./assets/textures/we.xpm");
	generate_reverse_xpm(input->we_path, map->west);
	map->south = ft_strdup("./assets/textures/so.xpm");
	generate_reverse_xpm(input->so_path, map->south);
	map->map = read_map(fd, &input);
	map->y_len = input->map_height * TILE_SIZE;
	map->x_len = input->map_width * TILE_SIZE;
	map->proj_plane = (map->x_len / 2) / tan(FOV / 2);
	return (map);
}

t_player	*start_player(int x, int y, int dir)
{
	t_player	*p1;

	p1 = malloc(sizeof(t_player));
	p1->pos[X] = x * TILE_SIZE;
	p1->pos[Y] = y * TILE_SIZE;
	p1->turn_direction = 0;
	p1->walk_direction = 0;
	p1->angle = dir * PI / 2;
	return (p1);
}



int	main(void)
{
	t_map		*map;
	t_player	*p1;

	map = map_maker();
	p1 = start_player(15, 5, EAST);
	start_game(map, p1);
}
