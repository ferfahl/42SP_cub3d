/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:57:01 by feralves          #+#    #+#             */
/*   Updated: 2023/08/09 20:45:08 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	create_var_image(void *addr)
{
	t_image	image;

	image.ptr = mlx_new_image(addr, W_WIDTH, W_HEIGHT);
	image.data = (int *)mlx_get_data_addr(image.ptr, &image.bpp,
			&image.line_len, &image.endian);
	return (image);
}
