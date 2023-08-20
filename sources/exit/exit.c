/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:53:14 by feralves          #+#    #+#             */
/*   Updated: 2023/08/20 20:19:58 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//temporary
void	clear_map(t_map	*map)
{
	free(map);
}

void	ft_exit(int status, t_cub *cub)
{
	if (cub)
	{
		mlx_destroy_window(cub->mlx, cub->win);
		mlx_destroy_image(cub->mlx, cub->img.ptr);
		mlx_destroy_display(cub->mlx);
		clear_map(cub->map);
		free(cub->player);
		free(cub->mlx);
		free(cub);
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
