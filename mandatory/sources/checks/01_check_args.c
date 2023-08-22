/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:44:31 by feralves          #+#    #+#             */
/*   Updated: 2023/08/22 13:41:57 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extension(char *path, char *extension)
{
	int	len_name;

	len_name = ft_strlen(path) - 4;
	if (ft_strncmp(path + len_name, extension, 4))
		return (1);
	return (0);
}

int	check_args(int argc, char *argv[])
{
	int	fd;

	if (argc != 2)
		return (ft_error("Wrong number of arguments"));
	if (check_extension(argv[1], ".cub"))
		return (ft_error("Expected .cub file"));
	fd = open_file(argv[1]);
	if (fd < 0)
		return (ft_error(strerror(errno)));
	return (fd);
}

int	open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	return (fd);
}
