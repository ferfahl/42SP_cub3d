/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:56:12 by feralves          #+#    #+#             */
/*   Updated: 2023/08/22 15:02:47 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_tile(char c, t_input **input, int x, int y)
{
	if (c == '1')
		return (1);
	if (c == 'S' || c == 'N' || c == 'W' || c == 'E' || c == '0')
	{
		if (c != '0')
		{
			(*input)->has_player++;
			(*input)->player_x = x;
			(*input)->player_y = y;
		}
		if (c == 'S')
			(*input)->player_dir = SOUTH;
		if (c == 'W')
			(*input)->player_dir = WEST;
		if (c == 'N')
			(*input)->player_dir = NORTH;
		if (c == 'E')
			(*input)->player_dir = EAST;
		return (0);
	}
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

int	check_env(char *str)
{
	if (!ft_strncmp(str, "NO", 2))
		return (TRUE);
	if (!ft_strncmp(str, "SO", 2))
		return (TRUE);
	if (!ft_strncmp(str, "WE", 2))
		return (TRUE);
	if (!ft_strncmp(str, "EA", 2))
		return (TRUE);
	if (!ft_strncmp(str, "F ", 2))
		return (TRUE);
	if (!ft_strncmp(str, "C ", 2))
		return (TRUE);
	return (FALSE);
}
