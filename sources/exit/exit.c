/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:53:14 by feralves          #+#    #+#             */
/*   Updated: 2023/08/21 22:41:46 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit_error(char *str, t_cub *cub)
{
	ft_error(str);
	if (cub)
		free_cub(cub);
}

void	ft_exit(int status, t_cub *cub)
{
	if (cub)
		free_cub(cub);
	if (status == 0)
		ft_printf("Exit Success\n");
	else
		ft_printf("Exit Failure\n");
	exit(status);
}
