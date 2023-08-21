/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:53:14 by feralves          #+#    #+#             */
/*   Updated: 2023/08/21 19:44:10 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	ft_exit_error(t_cub *cub, )

void	ft_exit(int status, t_cub *cub)
{
	if (cub)
	{
		mlx_destroy_window(cub->mlx, cub->win);
		mlx_destroy_image(cub->mlx, cub->img.ptr);
		mlx_destroy_image(cub->mlx, cub->north.ptr);
		mlx_destroy_image(cub->mlx, cub->south.ptr);
		mlx_destroy_image(cub->mlx, cub->west.ptr);
		mlx_destroy_image(cub->mlx, cub->east.ptr);
		mlx_destroy_display(cub->mlx);
		free(cub->map);
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
