/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 06:49:03 by feralves          #+#    #+#             */
/*   Updated: 2023/06/20 17:25:31 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reading(int fd)
{
	char	*reader;
	int		size;
	
	reader = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!reader)
		return (NULL);
	reader[0] = '\0';
	size = read(fd, reader, BUFFER_SIZE);
	if (size == 0)
	{
		free(reader);
		return (NULL);
	}
	else
		reader[size] = '\0';
	return (reader);
	
}

char	*get_till_break(char *str)
{
	int		i;
	int		size;
	char	*was_read;

	i = 0;
	size = size_till_break(str);
	was_read = malloc((size + 1) * sizeof(char));
	if (!was_read)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
	{
		was_read[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		was_read[i] = '\n';
		i++;
	}
	was_read[i] = '\0';
	return (was_read);
}

char	*get_rest(char *str)
{
	int		i;
	int		read_size;
	int		final_size;
	char	*remains;

	i = 0;
	read_size = size_till_break(str);
	final_size = ft_strlen(str) - read_size;
	remains = malloc((final_size + 1) * sizeof(char));
	if (!remains)
		return (NULL);
	while (str[read_size + i])
	{
		remains[i] = str[read_size + i];
		i++;
	}
	remains[i] = '\0';
	return (remains);
}

char	*ft_return_line(int fd)
{
	char	*was_read;
	char	*reader;
	char	*full_line;
	const char	*remains;

	if (!remains)
		remains = NULL;
	reader = reading(fd);
	full_line = ft_strjoin(remains, reader);
	free(reader);
	free(remains);
	if (ft_strlen(full_line) == 0)
	{
		free(full_line);
		return (NULL);
	}
	was_read = get_till_break(full_line);
	remains = get_rest(full_line);
	free(full_line);
	return (was_read);
}

char	*get_next_line(int fd)
{
	char		*was_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 999)
		return (NULL);
	was_read = ft_return_line(fd);
	return (was_read);
}
