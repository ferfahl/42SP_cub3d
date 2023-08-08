/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:53:38 by feralves          #+#    #+#             */
/*   Updated: 2023/08/08 19:21:26 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	int	*dst;

	if (x > W_WIDTH || y > W_HEIGHT || x < 0 || y < 0)
		return ;
	dst = image->data + (y * image->line_len + x * (image->bpp / 8));
	*dst = color;
}
