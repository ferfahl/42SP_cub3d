/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:24:44 by feralves          #+#    #+#             */
/*   Updated: 2023/08/08 17:24:24 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	click_hook(t_vars *vars)
{
	ft_printf("end click\n");
	ft_exit(0, vars);
	return (0);
}
