/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:30:10 by feralves          #+#    #+#             */
/*   Updated: 2023/08/22 10:49:32 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "buttons_bonus.h"

void	mlx_hooks(t_cub *cub)
{
	load_textures(cub);
	mlx_loop_hook(cub->mlx, &render, cub);
	mlx_hook(cub->win, KEY_PRESS_EVENT, (1L << 0), key_hook, cub);
	mlx_hook(cub->win, CLICK_EVENT, (1L << 2), click_hook, cub);
	mlx_loop(cub->mlx);
}

void	open_window(t_cub	*cub)
{
	cub->mlx = mlx_init();
	if (cub->mlx == NULL)
		return (ft_exit_error("Mlx init error", cub));
	cub->win = mlx_new_window(cub->mlx, W_WIDTH, W_HEIGHT, "cub3D");
	if (cub->win == NULL)
		return (ft_exit_error("Mlx cub->window error", cub));
	cub->img = create_var_image(cub->mlx);
}
