/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:30:05 by feralves          #+#    #+#             */
/*   Updated: 2023/06/27 17:44:19 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(int status)
{
	if (status == 0)
		ft_printf("Exit Success\n");
	else
		ft_printf("Exit Failure\n");
	exit(status);
}

void	if_error(char *str)
{
	ft_printf("error\n%s\n", str);
	exit(1);
}

int	main(int argc, char *argv[])
{
	if (check_args(argc, argv))
		return (1);
	//begin struct
	//open file
	//check map
	//check info for each element
	//check if map is closed
	//check if map is valid
	open_window();
}