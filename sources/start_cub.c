/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:59:21 by feralves          #+#    #+#             */
/*   Updated: 2023/08/21 17:12:43 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_input	*start_input(void)
{
	t_input	*input;

	input = (t_input *)malloc(sizeof(t_input));
	input->has_no = FALSE;
	input->has_so = FALSE;
	input->has_we = FALSE;
	input->has_ea = FALSE;
	input->has_f = FALSE;
	input->has_c = FALSE;
	input->c = 0;
	input->f = 0;
	input->map_width = 0;
	input->map_height = 0;
	return (input);
}

void	start_game(t_map *map, t_player *p1)
{
	t_cub	*cub;
	t_rays	ray[W_WIDTH];

	cub = (t_cub *)ft_calloc(1, sizeof(t_cub));
	if (cub == NULL)
		ft_error("Calloc error");
	open_window(cub);
	cub->map = map;
	cub->player = p1;
	cub->nbr_rays = W_WIDTH;
	cub->rays = ray;
	mlx_hooks(cub);
}
