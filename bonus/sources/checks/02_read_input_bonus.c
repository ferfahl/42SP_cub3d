/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_read_input_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:53:52 by rarobert          #+#    #+#             */
/*   Updated: 2023/08/22 10:48:06 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

int	check_if_textures(t_input *input)
{
	if (!input->has_we)
		return (ft_error("No WE texture found"));
	if (!input->has_ea)
		return (ft_error("No EA texture found"));
	if (!input->has_no)
		return (ft_error("No NO texture found"));
	if (!input->has_so)
		return (ft_error("No SO texture found"));
	if (!input->has_c)
		return (ft_error("No Ceiling color found"));
	if (!input->has_f)
		return (ft_error("No Floor color found"));
	return (0);
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
	if (check_if_textures(*input) == -1)
	{
		free_input(*input);
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
