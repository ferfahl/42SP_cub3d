/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:53:56 by feralves          #+#    #+#             */
/*   Updated: 2023/08/21 19:39:30 by feralves         ###   ########.fr       */
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
	size_t	i;

	i = 0;
	while (map[i])
	{
		free (map[i]);
		i++;
	}
	free(map);
	free_stuff(map_line);
	free(input);
}
