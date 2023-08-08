/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:24:27 by feralves          #+#    #+#             */
/*   Updated: 2023/08/08 17:23:54 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "buttons.h"

int	key_hook(int keycode, t_vars *vars)
{
	// ft_printf("keycode: %d\n", keycode);
	if (keycode == W_KEY)
		ft_printf("up\n");
	if (keycode == S_KEY)
		ft_printf("down\n");
	if (keycode == D_KEY)
		ft_printf("right\n");
	if (keycode == A_KEY)
		ft_printf("left\n");
	if (keycode == SPACE)
		ft_printf("space\n");
	if (keycode == SHIFT)
		ft_printf("shift\n");
	if (keycode == UP)
		ft_printf("view up\n");
	if (keycode == DOWN)
		ft_printf("view down\n");
	if (keycode == RIGHT || keycode == V_RIGHT)
		ft_printf("view right\n");
	if (keycode == LEFT || keycode == V_LEFT)
		ft_printf("view left\n");
	if (keycode == ESC)
		ft_exit(0, vars);
	return (0);
}
