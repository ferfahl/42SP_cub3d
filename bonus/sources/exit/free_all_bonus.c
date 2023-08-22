/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:53:56 by feralves          #+#    #+#             */
/*   Updated: 2023/08/22 19:28:10 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_input(t_input *input)
{
	if (input)
	{
		if (input->has_we)
			free(input->we_path);
		if (input->has_ea)
			free(input->ea_path);
		if (input->has_no)
			free(input->no_path);
		if (input->has_so)
			free(input->so_path);
		close(input->fd);
		free(input);
	}
}

void	ft_free_map_array(int **array, int y)
{
	if (!array)
		return ;
	while (--y >= 0)
		free(array[y]);
	free(array);
}

void	free_map(t_map *map)
{
	free(map->west);
	free(map->north);
	free(map->south);
	free(map->east);
	ft_free_map_array(map->map, map->y_len / TILE_SIZE);
	free(map);
}

void	free_map_lines(t_map_line *map_line)
{
	t_map_line	*aux;

	if (!map_line)
		return ;
	while (map_line->next)
	{
		aux = map_line;
		map_line = map_line->next;
		free(aux->line);
		free(aux);
	}
	free(map_line->line);
	free(map_line);
}

void	free_all(t_map_line *map_line, t_input *input, int **map)
{
	ft_free_map_array(map, input->map_height);
	free_map_lines(map_line);
	free_input(input);
}
