/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:56:12 by feralves          #+#    #+#             */
/*   Updated: 2023/08/20 23:57:49 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	verify_map(t_map_line *map, t_input **input, int inside_map)
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
			if ((*input)->map_width < ft_strlen(trimmed))
				(*input)->map_width = ft_strlen(trimmed);
			(*input)->map_height++;
		}
		free(trimmed);
		map = map->next;
	}
	return (0);
}
