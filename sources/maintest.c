/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:55:34 by feralves          #+#    #+#             */
/*   Updated: 2023/08/21 18:26:14 by rarobert         ###   ########.fr       */
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
	printf("\n");
	print_map(map);
	return (map);
}

t_map	*get_map(int argc, char *argv[], t_input **input)
{
	int			fd;
	char		*line;
	char		*trimmed;
	t_map		*full_map;

	fd = check_args(argc, argv);
	line = get_next_line(fd);
	while (line)
	{
		trimmed = ft_strtrim_whitespaces(line);
		check_all(trimmed, *input);
		free(trimmed);
		if ((*input)->has_no && (*input)->has_so && (*input)->has_ea && (*input)->has_we
			&& (*input)->has_c && (*input)->has_f)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	full_map = map_reader(fd, input);
	close(fd);
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

	input = start_input();
	map = get_map(argc, argv, &input);
	// exit(0);
	printf("%s\n", map->north);
	printf("%s\n", map->south);
	printf("%s\n", map->west);
	printf("%s\n", map->east);
	p1 = start_player(input->player_y, input->player_x, input->player_dir);
	start_game(map, p1);
}
