/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:55:34 by feralves          #+#    #+#             */
/*   Updated: 2023/08/11 19:04:37 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int *temp_map[13] = {
	(int[20]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1},
	(int[20]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	(int[20]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	(int[20]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	(int[20]){1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
	(int[20]){1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	(int[20]){1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	(int[20]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	(int[20]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	(int[20]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	(int[20]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	(int[20]){1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	(int[20]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void	clear_map(t_map	*map)
{
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
	int	i;

	i = 0;
	mapped = malloc(sizeof(t_map));
	mapped->ceiling = ft_strdup("0xFF444444");
	mapped->floor = ft_strdup("0xFF000000");
	mapped->east = ft_strdup("0xFFFF0000");
	mapped->west = ft_strdup("0xFF00FF00");
	mapped->north = ft_strdup("0xFF0000FF");
	mapped->south = ft_strdup("0xFFFFFFFF");
	mapped->y_len = 13;
	mapped->x_len = 20;
	mapped->map = temp_map;
	while (i < (int)mapped->y_len)
	{
		for (int j = 0; j < (int)mapped->x_len; j++)
		{
			ft_printf("%d ", mapped->map[i][j]);
		}
		ft_printf("\n");
		i++;
	}
	return (mapped);
}

t_player	*start_player(t_map *map)
{
	t_player	*p1;

	p1 = malloc(sizeof(t_player));
	p1->x = map->x_len / 2;
	p1->y = map->y_len / 2;
	p1->size = 1;
	p1->turn_direction = 0;
	p1->walk_direction = 0;
	p1->rotation_angle = PI / 2;
	p1->turn_speed = 45 * (PI / 180);
	p1->walk_speed = 100;
	return (p1);
}

int	main(void)
{
	t_map		*map;
	t_player	*p1;

	map = map_maker();
	p1 = start_player(map);
	open_window(map, p1);
}
