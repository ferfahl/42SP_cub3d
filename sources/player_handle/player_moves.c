/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:58:52 by feralves          #+#    #+#             */
/*   Updated: 2023/08/12 19:49:09 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "buttons.h"
#include <stdio.h>

void	move_player(t_vars *vars, int walk, int control)
{
	float	move_step;
	float	new_x;
	float	new_y;

	move_step = walk * WALK_SPEED;
	if (!control)
	{
		new_x = vars->player->x + cos(radians(vars->player->angle))
			* move_step;
		new_y = vars->player->y + sin(radians(vars->player->angle))
			* move_step;
	}
	else
	{
		new_x = vars->player->x + sin(radians(vars->player->angle))
			* move_step;
		new_y = vars->player->y + cos(radians(vars->player->angle))
			* move_step;
	}
	if (!map_wall(vars->fullmap, new_x, new_y))
	{
		vars->player->x = new_x;
		vars->player->y = new_y;
	}
}

void	change_player_pos(int keycode, t_vars *vars)
{
	if (keycode == W_KEY || keycode == UP)
		move_player(vars, 1, 0);
	if (keycode == S_KEY || keycode == DOWN)
		move_player(vars, -1, 0);
	if (keycode == D_KEY)
		move_player(vars, 1, 1);
	if (keycode == A_KEY)
		move_player(vars, -1, 1);
}

void	turn_player(int keycode, t_vars *vars)
{
	if (keycode == RIGHT || keycode == Q_KEY)
		vars->player->angle += TURN_SPEED;
	if (keycode == LEFT || keycode == E_KEY)
		vars->player->angle += -1 * TURN_SPEED;
	vars->player->angle = normalize_angle(vars->player->angle);
}
