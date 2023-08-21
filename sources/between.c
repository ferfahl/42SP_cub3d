/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   between.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:22:57 by rarobert          #+#    #+#             */
/*   Updated: 2023/08/21 00:00:21 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*map_maker(void)
{
	int			fd;
	t_input		*input;
	char		**map;
	char		*line;
	char		*trimmed;
	t_map		*full_map;

	input = start_input();
	map = malloc(sizeof(char *) * 3);
	map[0] = ft_strdup("./cub3d");
	map[1] = ft_strdup("./map.cub");
	map[2] = NULL;
	fd = check_args(2, map);
	line = get_next_line(fd);
	while (line)
	{
		trimmed = ft_strtrim_whitespaces(line);
		check_all(trimmed, input);
		free(trimmed);
		if (input->has_no && input->has_so && input->has_ea && input->has_we
			&& input->has_c && input->has_f)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	full_map = map_reader(fd, input);
	close(fd);
	free(map[0]);
	free(map[1]);
	free(map[2]);
	free(map);
	return (full_map);
}
