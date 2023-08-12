/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:24:27 by feralves          #+#    #+#             */
/*   Updated: 2023/08/12 15:16:17 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "buttons.h"

int	key_hook(int key, t_vars *vars)
{
	ft_printf("keycode: %d\n", key);
	if (key == W_KEY || key == S_KEY || key == DOWN || key == UP)
		change_player_pos(key, vars);
	if (key == A_KEY || key == D_KEY)
		change_player_pos(key, vars);
	if (key == SPACE)
		ft_printf("space\n");
	if (key == SHIFT)
		ft_printf("shift\n");
	if (key == RIGHT || key == Q_KEY)
		ft_printf("view right\n");
	if (key == LEFT || key == E_KEY)
		ft_printf("view left\n");
	if (key == ESC)
		ft_exit(0, vars);
	return (0);
}
