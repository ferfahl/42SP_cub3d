/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:53:18 by feralves          #+#    #+#             */
/*   Updated: 2023/08/21 22:05:28 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	full_map = generate_map((*input)->fd, input);
	return (full_map);
}

int	check_player(t_input *input)
{
	if (input->has_player > 1)
	{
		ft_error("More than one player on the map");
		return (FALSE);
	}
	if (input->has_player == 0)
	{
		ft_error("No player on the map");
		return (FALSE);
	}
	return (TRUE);
}

int	**create_map(t_map_line *start, t_input **input, size_t counter, size_t i)
{
	int		**map;

	map = (int **)malloc(sizeof(int *) * (*input)->map_height);
	while (++counter < (*input)->map_height)
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
			{
				ft_free_map_array(map, counter + 1);
				return (NULL);
			}
		}
		start = start->next;
	}
	if (!check_player(*input))
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

int	**read_map(int fd, t_input **input, t_map_line *node)
{
	char		*line;
	t_map_line	*start;
	int			**map;

	start = node;
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
	map = create_map(start, input, -1, -1);
	if (map == NULL)
	{
		free_all(start, *input, NULL);
		return (NULL);
	}
	free_map_lines(start);
	return (map);
}
