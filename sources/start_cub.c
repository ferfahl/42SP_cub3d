/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:59:21 by feralves          #+#    #+#             */
/*   Updated: 2023/08/20 20:19:56 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_game(t_map *map, t_player *p1)
{
	t_cub	*cub;
	t_rays	ray[W_WIDTH];

	cub = (t_cub *)ft_calloc(1, sizeof(t_cub));
	if (cub == NULL)
		if_error("Calloc error");
	open_window(cub);
	cub->map = map;
	cub->player = p1;
	cub->nbr_rays = W_WIDTH;
	cub->rays = ray;
	mlx_hooks(cub);
}
