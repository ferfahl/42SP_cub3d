/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:57:01 by feralves          #+#    #+#             */
/*   Updated: 2023/08/22 10:49:27 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	creating_img(t_cub *cub)
{
	cast_all_rays(cub);
	generate_projection(cub);
	draw_mini_map(cub, cub->map);
}

int	render(t_cub *cub)
{
	draw_background(cub);
	creating_img(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.ptr, 0, 0);
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
