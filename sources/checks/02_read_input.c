/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:53:52 by rarobert          #+#    #+#             */
/*   Updated: 2023/08/22 09:32:03 by feralves         ###   ########.fr       */
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

t_map	*get_map(t_input **input)
{
	char		*line;
	char		*trimmed;
	t_map		*full_map;

	line = get_next_line((*input)->fd);
	if (line == NULL)
	{
		free(input);
		ft_error("Empty map file");
		return (NULL);
	}
	while (line)
	{
		trimmed = ft_strtrim_whitespaces(line);
		if (!check_all(trimmed, *input))
		{
			free(trimmed);
			free(line);
			free_input(*input);
			return (NULL);
		}
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
