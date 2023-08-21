/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:55:34 by feralves          #+#    #+#             */
/*   Updated: 2023/08/21 20:50:26 by rarobert         ###   ########.fr       */
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

t_map	*map_reader(int fd, t_input **input)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->ceiling = (*input)->c;
	map->floor = (*input)->f;
	map->east = (*input)->ea_path;
	map->north = (*input)->no_path;
	map->west = ft_strdup("./assets/textures/we.xpm");
	generate_reverse_xpm((*input)->we_path, map->west);
	map->south = ft_strdup("./assets/textures/so.xpm");
	generate_reverse_xpm((*input)->so_path, map->south);
	map->map = read_map(fd, input);
	map->y_len = (*input)->map_height * TILE_SIZE;
	map->x_len = (*input)->map_width * TILE_SIZE;
	map->proj_plane = (map->x_len / 2) / tan(FOV / 2);
	return (map);
}

t_map	*get_map(t_input **input)
{
	char		*line;
	char		*trimmed;
	t_map		*full_map;

	line = get_next_line((*input)->fd);
	while (line)
	{
		trimmed = ft_strtrim_whitespaces(line);
		check_all(trimmed, *input);
		free(trimmed);
		if ((*input)->has_no && (*input)->has_so && (*input)->has_ea
			&& (*input)->has_we && (*input)->has_c && (*input)->has_f)
			break ;
		free(line);
		line = get_next_line((*input)->fd);
	}
	free(line);
	full_map = map_reader((*input)->fd, input);
	close((*input)->fd);
	return (full_map);
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

int	main(int argc, char *argv[])
{
	t_input		*input;
	t_map		*map;
	t_player	*p1;

	input = start_input(argc, argv);
	if (input == NULL)
		return (-1);
	map = get_map(&input);
	if (verify_path(map, input->player_y, input->player_x) == -1)
		exit (-1);
	p1 = start_player(input->player_y, input->player_x, input->player_dir);
	start_game(map, p1);
}
