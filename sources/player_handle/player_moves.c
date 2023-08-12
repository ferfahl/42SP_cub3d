/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:58:52 by feralves          #+#    #+#             */
/*   Updated: 2023/08/12 15:15:05 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "buttons.h"

void	move_player(t_map *mapped, t_player *p1)
{
	float	move_step;
	float	pos_p1_x;
	float	pos_p1_y;

	p1->rotation_angle += p1->turn_direction * p1->turn_speed;
	move_step = p1->walk_direction * p1->walk_speed;
	pos_p1_x = p1->x + cos(p1->rotation_angle) * move_step;
	pos_p1_y = p1->y + sin(p1->rotation_angle) * move_step;
	//wall collision
	if (!map_wall(mapped, pos_p1_x, pos_p1_y))
	{
		p1->x = pos_p1_x;
		p1->y = pos_p1_y;
	}
}

void	change_player_pos(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == W_KEY || keycode == UP)
		ft_printf("up\n");
	if (keycode == S_KEY || keycode == DOWN)
		ft_printf("down\n");
	if (keycode == D_KEY)
		ft_printf("right\n");
	if (keycode == A_KEY)
		ft_printf("left\n");
}
