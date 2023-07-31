/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:55:34 by feralves          #+#    #+#             */
/*   Updated: 2023/07/31 12:09:33 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*map_maker(void)
{
	t_map	*mapped;
	int		i;

	i = 0;
	mapped = malloc(sizeof(t_map));
	mapped->ceiling = ft_strdup("220,100,0");
	mapped->floor = ft_strdup("220,100,0");
	mapped->east = ft_strdup("225,30,0");
	mapped->west = ft_strdup("225,30,0");
	mapped->north = ft_strdup("225,30,0");
	mapped->south = ft_strdup("225,30,0");
	mapped->map = malloc(sizeof(char *) * (11 + 1));
	while (i < 11)
	{
		if (i == 0 || i == 11)
			mapped->map[i] = ft_strdup("11111111111");
		else if (i % 2 != 0)
			mapped->map[i] = ft_strdup("10000000011");
		else
			mapped->map[i] = ft_strdup("10010000101");
		i++;
	}
	mapped[i] = NULL;
	return(mapped);
}

int main(void)
{
	t_map *map;

	map = map_maker();
	mini_map();
	open_window();
}