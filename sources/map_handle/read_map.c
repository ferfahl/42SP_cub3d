/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:53:18 by feralves          #+#    #+#             */
/*   Updated: 2023/08/20 23:57:44 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
				map[counter][iterator] = get_tile(' ');
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

t_map_line	*new_map_node(void)
{
	t_map_line	*new;

	new = (t_map_line *)malloc(sizeof(t_map_line));
	new->next = NULL;
	new->line = NULL;
	return (new);
}

int	**read_map(int fd, t_input **input)
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
	map = get_map(start, *input);
	free_stuff(start);
	return (map);
}
