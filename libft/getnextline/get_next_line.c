/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:40:25 by rarobert          #+#    #+#             */
/*   Updated: 2023/08/21 14:49:03 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_string(t_gnl *lst, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (lst)
	{
		j = 0;
		while (lst->str[j])
		{
			str[i + j] = lst->str[j];
			j++;
		}
		i += j;
		lst = lst->next;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	t_gnl	*line;
	t_gnl	*start;
	char	*next_line;
	size_t	i;

	line = ft_listnew();
	start = line;
	fill_list(fd, line);
	while (line->next)
		line = line->next;
	i = ft_strlen(line->str) + (BUFFER_SIZE * (ft_dec_lst_size(start)));
	next_line = get_string(start, i);
	ft_lstclear(start);
	if (!next_line[0])
	{
		free (next_line);
		return (NULL);
	}
	return (next_line);
}

void	fill_list(int fd, t_gnl *to_fill)
{
	char	c;
	size_t	i;

	i = 0;
	c = 1;
	while (c)
	{
		to_fill->str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		while (c && i < BUFFER_SIZE)
		{
			c = get_next_char(fd);
			to_fill->str[i++] = c;
			if (c == '\n')
				break ;
		}
		to_fill->str[i] = '\0';
		if (c == '\n')
			break ;
		if (c)
		{
			i = 0;
			to_fill->next = ft_listnew();
			to_fill = to_fill->next;
		}
	}
}

char	get_next_char(int fd)
{
	size_t	x;
	char	c;

	c = 0;
	x = read(fd, &c, 1);
	if (x > 0)
		return (c);
	return (0);
}
