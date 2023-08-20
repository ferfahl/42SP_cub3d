/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainrap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:22:57 by rarobert          #+#    #+#             */
/*   Updated: 2023/08/20 16:08:45 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

t_input	*start_input(void)
{
	t_input	*input;

	input = (t_input *)malloc(sizeof(t_input));
	input->has_no = FALSE;
	input->has_so = FALSE;
	input->has_we = FALSE;
	input->has_ea = FALSE;
	input->has_f = FALSE;
	input->has_c = FALSE;
	input->c = 0;
	input->f = 0;
	input->map_width = 0;
	input->map_height = 0;
	return (input);
}

t_map_line	*new_map_node(void)
{
	t_map_line	*new;

	new = (t_map_line *)malloc(sizeof(t_map_line));
	new->next = NULL;
	new->line = NULL;
	return (new);
}

int	verify_map(t_map_line *map, t_input *input, int inside_map)
{
	char		*trimmed;

	while (map->next)
	{
		trimmed = ft_strtrim_whitespaces(map->line);
		if (trimmed == NULL || trimmed[0] == 0)
		{
			if (inside_map == TRUE)
				inside_map = FALSE;
		}
		else if (inside_map == FALSE)
		{
			free(trimmed);
			return (-1);
		}
		else
		{
			if (input->map_width < ft_strlen(trimmed))
				input->map_width = ft_strlen(trimmed);
			input->map_height++;
		}
		free(trimmed);
		map = map->next;
	}
	return (0);
}

t_map_line	*skip_empty_lines(t_map_line *start)
{
	t_map_line	*temp;
	char		*line;

	temp = start;
	while (start)
	{
		line = ft_strtrim_whitespaces(start->line);
		if (line[0] != 0)
			break ;
		temp = start->next;
		free(start->line);
		free(start);
		start = temp;
		free(line);
	}
	free(line);
	return (start);
}

int	get_tile(char c)
{
	if (c == '0')
		return (0);
	if (c == '1')
		return (1);
	if (c == 'N')
		return (2);
	if (c == 'S')
		return (3);
	if (c == 'W')
		return (4);
	if (c == 'E')
		return (5);
	if (c == ' ')
		return (9);
	ft_error("Invalid character inside map");
	return (-1);
}

void	free_stuff(t_map_line *map_line, t_input *input)
{
	t_map_line	*aux;

	while (map_line->next)
	{
		aux = map_line;
		map_line = map_line->next;
		free(aux->line);
		free(aux);
	}
	free(map_line->line);
	free(map_line);
	free(input);
}

void	free_all(t_map_line *map_line, t_input *input, int **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free (map[i]);
		i++;
	}
	free(map);
	free_stuff(map_line, input);
}

int	**get_map(t_map_line *start, t_input *input)
{
	int		**map;
	size_t	counter;
	size_t	iterator;

	counter = 0;
	map = (int **)malloc(sizeof(int *) * input->map_height);
	while (counter < input->map_height)
	{
		iterator = 0;
		map[counter] = (int *)malloc(sizeof(int) * input->map_width);
		while (iterator < input->map_width)
		{
			if (iterator + 1 >= ft_strlen(start->line))
				map[counter][iterator] = get_tile('0');
			else
				map[counter][iterator] = get_tile(start->line[iterator]);
			if (map[counter][iterator] == -1)
				free_all(start, input, map);
			iterator++;
		}
		start = start->next;
		counter++;
	}
	return (map);
}

int	**read_map(int fd, t_input *input)
{
	char		*line;
	t_map_line	*start;
	t_map_line	*node;
	int			**map;

	start = new_map_node();
	node = start;
	line = get_next_line(fd);
	while (line)
	{
		node->line = line;
		node->next = new_map_node();
		node = node->next;
		line = get_next_line(fd);
	}
	close(fd);
	start = skip_empty_lines(start);
	if (verify_map(start, input, TRUE) == -1)
		ft_error("Invalid map");
	map = get_map(start, input);
	free_stuff(start, input);
	return (map);
}

t_map	*map_reader(int fd, t_input *input)
{
	t_map	*map;
	map = malloc(sizeof(t_map));
	map->ceiling = input->c;
	map->floor = input->f;
	map->east = input->ea_fd;
	map->west = input->we_fd;
	map->north = input->no_fd;
	map->south = input->so_fd;
	map->y_len = input->map_height;
	map->x_len = input->map_width;
	map->map = read_map(fd, input);
	return (map);
}

int	main(void)
{
	int			fd;
	t_input		*input;
	char		**map;
	char		*line;
	char		*trimmed;
	size_t		i;
	size_t		j;
	t_map		*full_map;


	input = start_input();
	map = malloc(sizeof(char *) * 3);
	map[0] = ft_strdup("./cub3d");
	map[1] = ft_strdup("./map.cub");
	map[2] = NULL;
	fd = check_args(2, map);
	line = get_next_line(fd);
	while (line)
	{
		trimmed = ft_strtrim_whitespaces(line);
		check_all(trimmed, input);
		free(trimmed);
		if (input->has_no && input->has_so && input->has_ea && input->has_we
			&& input->has_c && input->has_f)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	full_map = map_reader(fd, input);
	close(fd);
	i = 0;
	while (i < 16)
	{
		j = 0;
		while (j < 33)
		{
			printf("%d", full_map->map[i][j]);
			j++;
		}
		printf("\n");
		free(full_map->map[i]);
		i++;
	}
	free(full_map->map);
	free(map[0]);
	free(map[1]);
	free(map[2]);
	free(map);
	free(full_map);
	i = 0;
	// free(final_map, )
	// return (input);
}
