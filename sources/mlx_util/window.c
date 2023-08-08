/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:30:10 by feralves          #+#    #+#             */
/*   Updated: 2023/08/08 17:23:35 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "buttons.h"

void	open_window(t_map *map)
{
	t_vars	*vars;

	vars = (t_vars *)ft_calloc(1, sizeof(t_vars));
	if (vars == NULL)
		if_error("Calloc error");
	vars->fullmap = map;
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		if_error("Mlx init error");
	vars->win = mlx_new_window(vars->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (vars->win == NULL)
		if_error("Mlx vars->window error");
	mlx_hook(vars->win, KEY_PRESS_EVENT, (1L << 0), key_hook, vars);
	mlx_hook(vars->win, CLICK_EVENT, (1L << 2), click_hook, vars);
	mlx_loop(vars->mlx);
}
