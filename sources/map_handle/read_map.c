/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:53:18 by feralves          #+#    #+#             */
/*   Updated: 2023/08/21 20:31:09 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	check_player(t_map_line *start, t_input *input, int **map)
{
	if (input->has_player > 1)
	{
		ft_error("More than one player on the map");
		free_all(start, input, map);
		return (FALSE);
	}
	if (input->has_player == 0)
	{
		ft_error("No player on the map");
		free_all(start, input, map);
		return (FALSE);
	}
	return (TRUE);
}

int	**create_map(t_map_line *start, t_input **input, size_t counter)
{
	int		**map;
	size_t	i;

	map = (int **)malloc(sizeof(int *) * (*input)->map_height);
	while (counter < (*input)->map_height)
	{
		map[counter] = (int *)malloc(sizeof(int) * (*input)->map_width);
		i = -1;
		while (++i < (*input)->map_width)
		{
			if (i + 1 >= ft_strlen(start->line))
				map[counter][i] = get_tile(' ', input, counter, i);
			else
				map[counter][i] = get_tile(start->line[i], input, counter, i);
			if (map[counter][i] == -1)
				free_all(start, *input, map);
		}
		start = start->next;
		counter++;
	}
	if (!check_player(start, *input, map))
		return (NULL);
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
	map = create_map(start, input, 0);
	if (map == NULL)
		return (NULL);
	free_stuff(start);
	return (map);
}
