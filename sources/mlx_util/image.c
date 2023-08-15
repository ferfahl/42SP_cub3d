/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:57:01 by feralves          #+#    #+#             */
/*   Updated: 2023/08/15 13:21:19 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render(t_vars *vars)
{
	draw_background(vars);
	creating_img(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.ptr, 0, 0);
	return (0);
}

t_image	create_var_image(void *addr)
{
	t_image	image;

	image.ptr = mlx_new_image(addr, W_WIDTH, W_HEIGHT);
	image.data = (int *)mlx_get_data_addr(image.ptr, &image.bpp,
			&image.line_len, &image.endian);
	return (image);
}
