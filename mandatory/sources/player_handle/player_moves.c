/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:58:52 by feralves          #+#    #+#             */
/*   Updated: 2023/08/20 20:20:05 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "buttons.h"

void	move_player(t_cub *cub, int walk, int control)
{
	float	move_step;
	float	new_x;
	float	new_y;

	move_step = (walk * WALK_SPEED) + P_SIZE;
	if (!control)
	{
		new_x = cub->player->pos[X] + cos(cub->player->angle)
			* move_step;
		new_y = cub->player->pos[Y] + sin(cub->player->angle)
			* move_step;
	}
	else
	{
		new_x = cub->player->pos[X] + cos(cub->player->angle - PI / 2)
			* move_step;
		new_y = cub->player->pos[Y] + sin(cub->player->angle - PI / 2)
			* move_step;
	}
	if (!map_wall(cub->map, new_x, new_y))
	{
		cub->player->pos[X] = new_x;
		cub->player->pos[Y] = new_y;
	}
}

void	change_player_pos(int keycode, t_cub *cub)
{
	if (keycode == W_KEY || keycode == UP)
		move_player(cub, 1, 0);
	if (keycode == S_KEY || keycode == DOWN)
		move_player(cub, -1, 0);
	if (keycode == D_KEY)
		move_player(cub, -1, 1);
	if (keycode == A_KEY)
		move_player(cub, 1, 1);
}

void	turn_player(int keycode, t_cub *cub)
{
	if (keycode == RIGHT || keycode == Q_KEY)
		cub->player->angle += TURN_SPEED;
	if (keycode == LEFT || keycode == E_KEY)
		cub->player->angle += -1 * TURN_SPEED;
	cub->player->angle = normalize_angle(cub->player->angle);
}
