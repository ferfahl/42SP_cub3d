/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:30:10 by feralves          #+#    #+#             */
/*   Updated: 2023/06/27 17:45:01 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_window(void)
{
	void	*first_try;
	void	*win;

	first_try = mlx_init();
	if (first_try == NULL)
		if_error("Mlx init error");
	win = mlx_new_window(first_try, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (win == NULL)
		if_error("Mlx window error");
	mlx_hook(win, KEY_PRESS_EVENT, (1L << 0), key_hook, NULL);
	mlx_hook(win, CLICK_EVENT, (1L << 2), click_hook, NULL);
	mlx_loop(first_try);
}
