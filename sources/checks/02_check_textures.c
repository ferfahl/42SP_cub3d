/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_check_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:27:59 by rarobert          #+#    #+#             */
/*   Updated: 2023/08/20 20:48:35 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_no(char *line, t_input *input)
{
	int		fd;
	char	*trimmed;

	if (!ft_strncmp(line, "NO", 2))
	{
		if (input->has_no)
			return (ft_error("More than one NO texture"));
		input->has_no = TRUE;
		trimmed = ft_strtrim_whitespaces(line + 2);
		if (check_extension(trimmed, ".xpm"))
		{
			free(trimmed);
			return (ft_error("Wrong NO texture file extension\n"));
		}
		fd = open_file(trimmed);
		input->no_path = ft_strdup(trimmed);
		free(trimmed);
		if (fd < 0)
			return (ft_error("Invalid NO texture"));
		close(fd);
	}
	return (0);
}

int	check_so(char *line, t_input *input)
{
	int		fd;
	char	*trimmed;

	if (!ft_strncmp(line, "SO", 2))
	{
		if (input->has_so)
			return (ft_error("More than one SO texture"));
		input->has_so = TRUE;
		trimmed = ft_strtrim_whitespaces(line + 2);
		if (check_extension(trimmed, ".xpm"))
		{
			free(trimmed);
			return (ft_error("Wrong SO texture file extension\n"));
		}
		fd = open_file(trimmed);
		input->no_path = ft_strdup(trimmed);
		free(trimmed);
		if (fd < 0)
			return (ft_error("Invalid SO texture"));
		close(fd);
	}
	return (0);
}

int	check_we(char *line, t_input *input)
{
	int		fd;
	char	*trimmed;

	if (!ft_strncmp(line, "WE", 2))
	{
		if (input->has_we)
			return (ft_error("More than one WE texture"));
		input->has_we = TRUE;
		trimmed = ft_strtrim_whitespaces(line + 2);
		if (check_extension(trimmed, ".xpm"))
		{
			free(trimmed);
			return (ft_error("Wrong WE texture file extension\n"));
		}
		fd = open_file(trimmed);
		input->no_path = ft_strdup(trimmed);
		free(trimmed);
		if (fd < 0)
			return (ft_error("Invalid WE texture"));
		close(fd);
	}
	return (0);
}

int	check_ea(char *line, t_input *input)
{
	int		fd;
	char	*trimmed;

	if (!ft_strncmp(line, "EA", 2))
	{
		if (input->has_ea)
			return (ft_error("More than one EA texture"));
		input->has_ea = TRUE;
		trimmed = ft_strtrim_whitespaces(line + 2);
		if (check_extension(trimmed, ".xpm"))
		{
			free(trimmed);
			return (ft_error("Wrong EA texture file extension\n"));
		}
		fd = open_file(trimmed);
		input->no_path = ft_strdup(trimmed);
		free(trimmed);
		if (fd < 0)
			return (ft_error("Invalid EA texture"));
		close(fd);
	}
	return (0);
}
