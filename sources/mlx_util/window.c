/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:30:10 by feralves          #+#    #+#             */
/*   Updated: 2023/08/12 11:02:29 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "buttons.h"

void	mlx_hooks(t_vars *vars)
{
	mlx_loop_hook(vars->mlx, &render, vars);
	mlx_hook(vars->win, KEY_PRESS_EVENT, (1L << 0), key_hook, vars);
	mlx_hook(vars->win, CLICK_EVENT, (1L << 2), click_hook, vars);
	mlx_loop(vars->mlx);
}

void	open_window(t_vars	*vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		if_error("Mlx init error");
	vars->win = mlx_new_window(vars->mlx, W_WIDTH, W_HEIGHT, "cub3D");
	if (vars->win == NULL)
		if_error("Mlx vars->window error");
	vars->img = create_var_image(vars->mlx);
}
