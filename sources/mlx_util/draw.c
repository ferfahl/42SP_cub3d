/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:53:38 by feralves          #+#    #+#             */
/*   Updated: 2023/08/15 15:12:23 by feralves         ###   ########.fr       */
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

void	print_square(t_image *image, t_pos id, int size, int color)
{
	int	i;
	int	j;

	i = id.x;
	while (i < size + id.x)
	{
		j = id.y;
		while (j < size + id.y)
		{
			my_mlx_pixel_put(image, i, j, color);
			j++;
		}
		i++;
	}
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

void	print_circle(t_image *image, int xc, int yc, int r)
{
	int	x;
	int	y;

	x = xc - r;
	y = yc - r;
	my_mlx_pixel_put(image, xc, yc, 0xFF0000);
	while (x <= xc + r)
	{
		y = yc - r;
		while (y <= yc + r)
		{
			if ((x - xc) * (x - xc) + (y - yc) * (y - yc) < r * r)
				my_mlx_pixel_put(image, x, y, 0xFF0000);
			y++;
		}
		x++;
	}
}
