/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainrap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:22:57 by rarobert          #+#    #+#             */
/*   Updated: 2023/08/17 13:58:46 by rarobert         ###   ########.fr       */
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
			free(trimmed);
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
		free(start);
		start = temp;
	}
	return (start);
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
			if (iterator + 1 >= ft_strlen(start->line)
				|| start->line[iterator] == '0')
				map[counter][iterator] = 0;
			else if (start->line[iterator] == '1')
				map[counter][iterator] = 1;
			else if (start->line[iterator] == 'N')
				map[counter][iterator] = 2;
			else if (start->line[iterator] == 'S')
				map[counter][iterator] = 3;
			else if (start->line[iterator] == 'W')
				map[counter][iterator] = 4;
			else if (start->line[iterator] == 'E')
				map[counter][iterator] = 5;
			else if (start->line[iterator] == ' ')
				map[counter][iterator] = 9;
			else
				ft_error("Invalid character inside map");
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
	input->map = read_map(fd, input);
	i = 0;
	while (i < input->map_height)
	{
		j = 0;
		printf("line %ld: \t", i);
		while (j < input->map_width)
		{
			printf("%d", input->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	// return (input);
}
