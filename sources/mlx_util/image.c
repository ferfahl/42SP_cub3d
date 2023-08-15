/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:57:01 by feralves          #+#    #+#             */
/*   Updated: 2023/08/12 19:49:33 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <sys/time.h>

float	time_to_wait(void)
{
	struct timeval	time01;
	int				time02;

	gettimeofday(&time01, NULL);
	if (time01.tv_usec > 500000)
		time02 = time01.tv_sec;
	else
		time02 = 0;
	return (time02);
}

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
