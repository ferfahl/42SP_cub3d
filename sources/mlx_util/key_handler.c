/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:24:27 by feralves          #+#    #+#             */
/*   Updated: 2023/08/21 22:42:31 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "buttons.h"

int	key_hook(int key, t_cub *cub)
{
	if (key == W_KEY || key == S_KEY || key == DOWN || key == UP)
		change_player_pos(key, cub);
	if (key == A_KEY || key == D_KEY)
		change_player_pos(key, cub);
	if (key == RIGHT || key == Q_KEY)
		turn_player(key, cub);
	if (key == LEFT || key == E_KEY)
		turn_player(key, cub);
	if (key == ESC)
		ft_exit(0, cub);
	return (0);
}
