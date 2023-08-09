/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:53:38 by feralves          #+#    #+#             */
/*   Updated: 2023/08/08 20:32:23 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (x > W_WIDTH || y > W_HEIGHT || x < 0 || y < 0)
		return ;
	dst = (char *)image->data + (y * image->line_len + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

void	print_tile(t_image *image, size_t x, size_t y, int color)
{
	size_t	i;
	size_t	j;

	i = x;
	while (i < TILE_SIZE + x)
	{
		j = y;
		while (j < TILE_SIZE + y)
		{
			my_mlx_pixel_put(image, i, j, color);
			j++;
		}
		i++;
	}
}
