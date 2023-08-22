/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:30:47 by feralves          #+#    #+#             */
/*   Updated: 2023/08/22 10:47:56 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_texture(t_cub *cub, t_image texture, int coord[2], int invert)
{
	int			offset[2];
	int			dist_to_top;
	int			wall_height;

	wall_height = wall_strip(cub, coord[X]);
	if (invert)
		offset[X] = invert - texture_offset_x(cub->rays[coord[X]]);
	else
		offset[X] = texture_offset_x(cub->rays[coord[X]]);
	dist_to_top = coord[Y] + (wall_height / 2) - (W_HEIGHT / 2);
	offset[Y] = dist_to_top * ((float)TEXTURE_SIZE / wall_height);
	return (*(unsigned int *)(texture.texture + (offset[Y] * texture.line_len
			+ offset[X] * (texture.bpp / 8))));
}

t_image	which_wall(t_cub *cub, int x, int *invert)
{
	if (cub->rays[x].was_hit_vert)
	{
		if (cub->rays[x].facing_left)
		{
			*invert = TEXTURE_SIZE - 1;
			return (cub->west);
		}
		else
			return (cub->east);
	}
	else
	{
		if (cub->rays[x].facing_up)
			return (cub->north);
		else
		{
			*invert = TEXTURE_SIZE - 1;
			return (cub->south);
		}
	}
}

void	draw_wall(t_cub *cub, int x, int top_pixel, int bot_pixel)
{
	int		coord[2];
	int		color;
	int		invert;
	t_image	texture;

	coord[X] = x;
	coord[Y] = top_pixel;
	while (coord[Y] < bot_pixel)
	{
		if (coord[Y] >= 0 && coord[Y] <= W_HEIGHT)
		{
			invert = 0;
			texture = which_wall(cub, x, &invert);
			color = get_texture(cub, texture, coord, invert);
			my_mlx_pixel_put(&cub->img, x, coord[Y], color);
		}
		coord[Y]++;
	}
}

void	generate_projection(t_cub *cub)
{
	int	x;
	int	wall_top_pixel;
	int	wall_bot_pixel;

	x = 0;
	while (x < cub->nbr_rays)
	{
		wall_top_pixel = top_bot_pixel(cub, x, 1);
		wall_bot_pixel = top_bot_pixel(cub, x, 0);
		draw_wall(cub, x, wall_top_pixel, wall_bot_pixel);
		x++;
	}
}
