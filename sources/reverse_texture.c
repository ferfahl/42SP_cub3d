/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:14:08 by rarobert          #+#    #+#             */
/*   Updated: 2023/08/21 14:54:27 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	copy_color_line(char *line, int fd)
{
	char	temp;

	temp = line[1];
	line[1] = line[2];
	line[2] = temp;
	write(fd, line, ft_strlen(line));
}

static void	ft_strrev(char *line, int fd)
{
	size_t	len;

	len = ft_strlen(line) - 2;
	while (len-- > 0)
		write(fd, &line[len], 1);
	write(fd, ",\n", 2);
}

static void	copy_textures(char *next_line, char *current_line, int *fd, int check)
{
	size_t	len;

	while (check == FALSE && current_line != NULL)
	{
		ft_strrev(current_line, fd[1]);
		free(current_line);
		current_line = ft_strdup(next_line);
		free (next_line);
		next_line = get_next_line(fd[0]);
		if (!ft_strncmp(next_line, "};", 2))
			check = TRUE;
	}
	len = ft_strlen(current_line) - 1;
	while (len-- > 0)
		write(fd[1], &current_line[len], 1);
	write(fd[1], "\n};", 3);
	free(current_line);
	free(next_line);
}

void	generate_reverse_xpm(char *old, char *new)
{
	char	*line;
	int		fd[2];
	int		check;
	size_t	i;

	i = 0;
	fd[0] = open(old, O_RDONLY);
	fd[1] = open(new, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	check = FALSE;
	while (i++ < 4)
	{
		line = get_next_line(fd[0]);
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	while (check == FALSE)
	{
		i++;
		line = get_next_line(fd[0]);
		if (!ft_strncmp(line, "/* pixels */", 12))
			check = TRUE;
		copy_color_line(line, fd[1]);
		free(line);
	}
	copy_textures(get_next_line(fd[0]), get_next_line(fd[0]), fd, FALSE);
}