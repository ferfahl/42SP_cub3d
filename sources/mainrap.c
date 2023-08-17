/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainrap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:22:57 by rarobert          #+#    #+#             */
/*   Updated: 2023/08/16 20:38:50 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

t_input	*start_input(void)
{
	t_input	*input;

	input = (t_input *)malloc(sizeof(t_input));
	input->has_no = FALSE;
	input->has_so = FALSE;
	input->has_we = FALSE;
	input->has_ea = FALSE;
	input->has_f = FALSE;
	input->has_c = FALSE;
	input->c = 0;
	input->f = 0;
	return (input);
}

int	main(void)
{
	int		fd;
	t_input	*input;
	char	**map;
	char	*line;
	char	*trimmed;

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
	printf("ceiling = %d\tfloor = %d\n", input->c, input->f);
	printf("fds:[%d,%d,%d,%d]\n", input->no_fd, input->so_fd, input->we_fd, input->ea_fd);
	// input->map = get_map(fd);
	close(fd);
	// return (input);
}
