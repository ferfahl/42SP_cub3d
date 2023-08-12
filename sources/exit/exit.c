/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:53:14 by feralves          #+#    #+#             */
/*   Updated: 2023/08/12 13:55:49 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//temporary
void	clear_map(t_map	*map)
{
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
		free(vars->player);
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
