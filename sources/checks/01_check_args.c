/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:44:31 by feralves          #+#    #+#             */
/*   Updated: 2023/08/09 20:45:40 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extension(char *str)
{
	int	len_name;

	len_name = ft_strlen(str) - 4;
	if (ft_strncmp(str + len_name, ".cub", 4))
		return (1);
	return (0);
}

int	check_args(int argc, char *argv[])
{
	if (argc != 2)
		return (ft_error("Wrong number of arguments\n"));
	if (check_extension(argv[1]))
		return (ft_error("Wrong file extension\n"));
	return (0);
}
//check if file exists
//open? now or later?
