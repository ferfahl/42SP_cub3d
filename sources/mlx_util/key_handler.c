/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:24:27 by feralves          #+#    #+#             */
/*   Updated: 2023/06/27 17:38:46 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode)
{
	// ft_printf("keycode: %d\n", keycode);
	if (keycode == UP || keycode == W_KEY)
		ft_printf("up\n");
	if (keycode == DOWN || keycode == S_KEY)
		ft_printf("down\n");
	if (keycode == RIGHT || keycode == D_KEY)
		ft_printf("right\n");
	if (keycode == LEFT || keycode == A_KEY)
		ft_printf("left\n");
	if (keycode == SPACE)
		ft_printf("space\n");
	if (keycode == SHIFT)
		ft_printf("shift\n");
	if (keycode == V_RIGHT)
		ft_printf("view right\n");
	if (keycode == V_LEFT)
		ft_printf("view left\n");
	if (keycode == ESC)
		ft_exit(0);
	return (0);
}
