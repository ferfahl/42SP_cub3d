/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:55:22 by feralves          #+#    #+#             */
/*   Updated: 2023/08/20 23:55:33 by feralves         ###   ########.fr       */
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
