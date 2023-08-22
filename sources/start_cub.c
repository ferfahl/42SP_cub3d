/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:59:21 by feralves          #+#    #+#             */
/*   Updated: 2023/08/21 21:59:53 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*generate_map(int fd, t_input **input)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->ceiling = (*input)->c;
	map->floor = (*input)->f;
	map->east = ft_strdup((*input)->ea_path);
	map->north = ft_strdup((*input)->no_path);
	map->west = ft_strdup("./assets/textures/we.xpm");
	generate_reverse_xpm((*input)->we_path, map->west);
	map->south = ft_strdup("./assets/textures/so.xpm");
	generate_reverse_xpm((*input)->so_path, map->south);
	map->map = read_map(fd, input, new_map_node());
	if (!map->map)
		return (map);
	map->y_len = (*input)->map_height * TILE_SIZE;
	map->x_len = (*input)->map_width * TILE_SIZE;
	map->proj_plane = (map->x_len / 2) / tan(FOV / 2);
	return (map);
}

t_input	*start_input(int argc, char *argv[])
{
	t_input	*input;
	int		fd;

	fd = check_args(argc, argv);
	if (fd < 0)
		return (NULL);
	input = (t_input *)malloc(sizeof(t_input));
	input->has_no = FALSE;
	input->has_so = FALSE;
	input->has_we = FALSE;
	input->has_ea = FALSE;
	input->has_f = FALSE;
	input->has_c = FALSE;
	input->has_player = FALSE;
	input->c = 0;
	input->f = 0;
	input->map_width = 0;
	input->map_height = 0;
	input->fd = fd;
	return (input);
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

void	start_game(t_map *map, t_player *p1)
{
	t_cub	*cub;
	t_rays	ray[W_WIDTH];

	cub = (t_cub *)ft_calloc(1, sizeof(t_cub));
	if (cub == NULL)
		ft_error("Calloc error");
	open_window(cub);
	cub->map = map;
	cub->player = p1;
	cub->nbr_rays = W_WIDTH;
	cub->rays = ray;
	mlx_hooks(cub);
}
