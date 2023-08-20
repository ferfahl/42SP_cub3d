/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:30:47 by feralves          #+#    #+#             */
/*   Updated: 2023/08/20 20:51:36 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	texture_offset_x(t_rays ray)
{
	int	offset_x;

	if (ray.was_hit_vert)
		offset_x = (int)ray.hit[Y] % TEXTURE_SIZE;
	else
		offset_x = (int)ray.hit[X] % TEXTURE_SIZE;
	return (offset_x);
}

int	get_texture(t_cub *cub, t_image texture, int x, int y)
{
	int			offset[2];
	int			dist_to_top;
	int			wall_height;

	wall_height = wall_strip(cub, x);
	offset[X] = texture_offset_x(cub->rays[x]);
	dist_to_top = y + (wall_height / 2) - (W_HEIGHT / 2);
	offset[Y] = dist_to_top * (64.0 / wall_height);
	return (*(unsigned int *)(texture.texture
		+ (offset[Y] * texture.line_len + offset[X]
			* (texture.bpp / 8))));
}

t_image	which_wall(t_cub *cub, int x)
{
	if (cub->rays[x].was_hit_vert)
	{
		if (cub->rays[x].facing_left)
			return (cub->west); //west
		else
			return (cub->east); //east
	}
	else
	{
		if (cub->rays[x].facing_up)
			return (cub->north); //north
		else
			return (cub->south); //south
	}
}

void	draw_wall(t_cub *cub, int x, int top_pixel, int bot_pixel)
{
	int		y;
	int		color;
	t_image	texture;
	// int	side;

	y = top_pixel;
	while (y < bot_pixel)
	{
		if (y >= 0 && y <= W_HEIGHT)
		{
			// side = which_wall(cub, x);
			texture = which_wall(cub, x);
			color = get_texture(cub, texture, x, y);
			// if (side == 0)
			// 	my_mlx_pixel_put(&cub->img, x, y, 0x0000FF);
			my_mlx_pixel_put(&cub->img, x, y, color);
			// else if (side == 1)
			// 	my_mlx_pixel_put(&cub->img, x, y, 0x00FF00);
			// else if (side == 2)
			// 	my_mlx_pixel_put(&cub->img, x, y, 0xFFF000);
			// else if (side == 3)
			// 	my_mlx_pixel_put(&cub->img, x, y, 0x0F0F0F);
		}
		y++;
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
