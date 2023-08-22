/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 22:38:52 by feralves          #+#    #+#             */
/*   Updated: 2023/08/22 10:48:26 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_cub(t_cub *cub)
{
	free_map(cub->map);
	free(cub->player);
	if (cub->mlx)
	{
		mlx_destroy_window(cub->mlx, cub->win);
		mlx_destroy_image(cub->mlx, cub->img.ptr);
		mlx_destroy_image(cub->mlx, cub->north.ptr);
		mlx_destroy_image(cub->mlx, cub->south.ptr);
		mlx_destroy_image(cub->mlx, cub->west.ptr);
		mlx_destroy_image(cub->mlx, cub->east.ptr);
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
	}
	free(cub);
}
