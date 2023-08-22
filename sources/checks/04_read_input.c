/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:53:52 by rarobert          #+#    #+#             */
/*   Updated: 2023/08/21 20:54:04 by rarobert         ###   ########.fr       */
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
