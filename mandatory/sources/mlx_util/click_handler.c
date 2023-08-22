/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:24:44 by feralves          #+#    #+#             */
/*   Updated: 2023/08/21 22:42:48 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	click_hook(t_cub *cub)
{
	ft_exit(0, cub);
	return (0);
}