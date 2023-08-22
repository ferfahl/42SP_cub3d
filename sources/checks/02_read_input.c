/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:53:52 by rarobert          #+#    #+#             */
/*   Updated: 2023/08/22 09:51:14 by feralves         ###   ########.fr       */
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

int	read_cub(t_input **input)
{
	char		*trimmed;
	char		*line;

	line = get_next_line((*input)->fd);
	if (line == NULL)
	{
		ft_error("Empty map file");
		return (FALSE);
	}
	while (line)
	{
		trimmed = ft_strtrim_whitespaces(line);
		free(line);
		if (!check_all(trimmed, *input))
		{
			free(trimmed);
			return (FALSE);
		}
		free(trimmed);
		if ((*input)->has_no && (*input)->has_so && (*input)->has_ea
			&& (*input)->has_we && (*input)->has_c && (*input)->has_f)
			break ;
		line = get_next_line((*input)->fd);
	}
	return (TRUE);
}

t_map	*get_map(t_input **input)
{
	t_map		*full_map;

	if (!read_cub(input))
	{
		if ((*input)->has_no)
			free_input(*input);
		else
			free(*input);
		return (NULL);
	}
	full_map = generate_map((*input)->fd, input);
	if (verify_path(full_map, (*input)->player_y, (*input)->player_x) == -1)
	{
		free_map(full_map);
		free_input(*input);
		return (NULL);
	}
	return (full_map);
}
