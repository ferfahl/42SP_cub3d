/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:53:56 by feralves          #+#    #+#             */
/*   Updated: 2023/08/21 20:28:47 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_map_array(int **array, int y)
{
	while (--y >= 0)
		free(array[y]);
	free(array);
}

void	free_stuff(t_map_line *map_line)
{
	t_map_line	*aux;

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
	free_stuff(map_line);
	free(input);
}
