/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:54:32 by feralves          #+#    #+#             */
/*   Updated: 2023/08/12 19:28:31 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// delta[0] = absolute value of x1 - x2
// delta[1] = absolute value of y1 - y2
// delta[2] = 1 if x2>x1, -1 if x1>x2
// delta[3] = 1 if y2>y1, -1 if y1>y2
int	*get_delta(t_pos a, t_pos b)
{
	int	*delta;

	delta = malloc(4 * sizeof(int));
	if (b.x > a.x)
	{
		delta[2] = 1;
		delta[0] = b.x - a.x;
	}
	else
	{
		delta[2] = -1;
		delta[0] = a.x - b.x;
	}
	if (b.y > a.y)
	{
		delta[3] = 1;
		delta[1] = b.y - a.y;
	}
	else
	{
		delta[3] = -1;
		delta[1] = a.y - b.y;
	}
	return (delta);
}

void	draw_line_util_1(t_image *image, t_pos a, t_pos b, int color)
{
	int	*delta;
	int	decision;

	my_mlx_pixel_put(image, a.x, a.y, color);
	delta = get_delta(a, b);
	decision = (2 * delta[1]) - delta[0];
	while (a.x != b.x)
	{
		a.x = a.x + delta[2];
		if (decision <= 0)
		{
			decision += (2 * delta[1]);
			my_mlx_pixel_put(image, a.x, a.y, color);
		}
		else
		{
			decision += 2 * (delta[1] - delta[0]);
			a.y = a.y + delta[3];
			my_mlx_pixel_put(image, a.x, a.y, color);
		}
	}
	my_mlx_pixel_put(image, b.x, b.y, color);
	free(delta);
}

void	draw_line_util_2(t_image *image, t_pos a, t_pos b, int color)
{
	int	*delta;
	int	decision;

	my_mlx_pixel_put(image, a.x, a.y, color);
	delta = get_delta(a, b);
	decision = (2 * delta[0]) - delta[1];
	while (a.y != b.y)
	{
		a.y = a.y + delta[3];
		if (decision <= 0)
		{
			decision += (2 * delta[0]);
			my_mlx_pixel_put(image, a.x, a.y, color);
		}
		else
		{
			decision += 2 * (delta[0] - delta[1]);
			a.x = a.x + delta[2];
			my_mlx_pixel_put(image, a.x, a.y, color);
		}
	}
	my_mlx_pixel_put(image, b.x, b.y, color);
	free(delta);
}

void	print_line(t_image *image, t_pos a, t_pos b)
{
	int	delta_x;
	int	delta_y;
	int	color;

	color = 0xFF0000;
	delta_x = a.x - b.x;
	delta_y = a.y - b.y;
	if (b.x > a.x)
		delta_x = b.x - a.x;
	if (b.y > a.y)
		delta_y = b.y - a.y;
	if (delta_x >= delta_y)
		draw_line_util_1(image, a, b, color);
	else
		draw_line_util_2(image, a, b, color);
}

// void	draw_line(t_vars *vars, int delta_x, int delta_y, int side_lenght)
// {
// 	int		color;
// 	int		i;
// 	float	x_inc;
// 	float	y_inc;
// 	float	current_x;
// 	float	current_y;

// 	color = 0xFF0000;
// 	i = 0;
// 	x_inc = delta_x / (float) side_lenght;
// 	y_inc = delta_y / (float) side_lenght;

// 	current_x = vars->player->x;
// 	current_y = vars->player->y;
// 	while (i < side_lenght)
// 	{
// 		my_mlx_pixel_put(&vars->img, round(current_x), round(current_y), color);
// 		current_x += x_inc;
// 		current_y += y_inc;
// 		i++;
// 	}
// }

// void	print_line(t_vars *vars, int x1, int y1)
// {
// 	int	delta_x;
// 	int	delta_y;
// 	int	side_lenght;

// 	delta_x = (x1 - vars->player->x);
// 	delta_y = (y1 - vars->player->y);
// 	if (delta_x >= delta_y)
// 		side_lenght = abs(delta_x);
// 	else
// 		side_lenght = abs(delta_y);
// 	draw_line(vars, delta_x, delta_y, side_lenght);
// }
