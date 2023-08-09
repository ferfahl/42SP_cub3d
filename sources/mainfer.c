/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:55:34 by feralves          #+#    #+#             */
/*   Updated: 2023/08/09 20:44:06 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_map(t_map	*map)
{
	int	i;

	i = 0;
	while (i <= 11)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map->ceiling);
	free(map->floor);
	free(map->east);
	free(map->west);
	free(map->north);
	free(map->south);
	free(map);
}

void	ft_exit(int status, t_vars *vars)
{
	if (vars)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_image(vars->mlx, vars->img.ptr);
		mlx_destroy_display(vars->mlx);
		clear_map(vars->fullmap);
		free(vars->mlx);
		free(vars);
	}
	if (status == 0)
		ft_printf("Exit Success\n");
	else
		ft_printf("Exit Failure\n");
	exit(status);
}

void	if_error(char *str)
{
	ft_printf("error\n%s\n", str);
	exit(1);
}

t_map	*map_maker(void)
{
	t_map	*mapped;
	int		i;

	i = 0;
	mapped = malloc(sizeof(t_map));
	mapped->ceiling = ft_strdup("0xFF444444");
	mapped->floor = ft_strdup("0xFF000000");
	mapped->east = ft_strdup("0xFFFF0000");
	mapped->west = ft_strdup("0xFF00FF00");
	mapped->north = ft_strdup("0xFF0000FF");
	mapped->south = ft_strdup("0xFFFFFFFF");
	mapped->map = malloc(sizeof(char *) * (11 + 1));
	while (i < 11)
	{
		if (i == 0 || i == 10)
			mapped->map[i] = ft_strdup("111111111111111");
		else if (i % 2 != 0)
			mapped->map[i] = ft_strdup("100000000000011");
		else if (i == 4)
			mapped->map[i] = ft_strdup("10011111N000101");
		else
			mapped->map[i] = ft_strdup("100111110000101");
		i++;
	}
	mapped->map[i] = ft_strdup("\0");
	return (mapped);
}

int	main(void)
{
	t_map	*map;

	map = map_maker();
	open_window(map);
}
