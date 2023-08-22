/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_check_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:27:59 by rarobert          #+#    #+#             */
/*   Updated: 2023/08/22 09:14:06 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_xpm_file(char *str)
{
	int		fd;
	char	*line;

	fd = open_file(str);
	line = get_next_line(fd);
	if (line == NULL)
	{
		close (fd);
		return (-1);
	}
	if (ft_strncmp(line, "/* XPM */", 9))
	{
		free(line);
		close (fd);
		return (-1);
	}
	free(line);
	return (fd);
}

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
		fd = check_xpm_file(trimmed);
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
		fd = check_xpm_file(trimmed);
		input->so_path = ft_strdup(trimmed);
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
		fd = check_xpm_file(trimmed);
		input->we_path = ft_strdup(trimmed);
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
		fd = check_xpm_file(trimmed);
		input->ea_path = ft_strdup(trimmed);
		free(trimmed);
		if (fd < 0)
			return (ft_error("Invalid EA texture"));
		close(fd);
	}
	return (0);
}
