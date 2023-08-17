/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:17:49 by rarobert          #+#    #+#             */
/*   Updated: 2023/08/16 21:21:31 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	get_next_char(int fd)
{
	ssize_t	x;
	char	c;

	c = 0;
	x = read(fd, &c, 1);
	if (x > 0)
		return (c);
	return (0);
}

t_list_gnl	*ft_lstnew_gnl(void)
{
	t_list_gnl	*node;

	node = (t_list_gnl *)malloc(sizeof(t_list_gnl));
	if (!node)
		return (NULL);
	node->next = NULL;
	return (node);
}

char	*get_string(t_list_gnl *lst, size_t len)
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

int	ft_dec_lst_size(t_list_gnl *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		counter++;
		lst = lst->next;
	}
	return (counter - 1);
}

void	ft_lstclear_gnl(t_list_gnl *lst)
{
	t_list_gnl	*aux;
	t_list_gnl	*i;

	i = lst;
	while (i)
	{
		free(i->str);
		aux = i;
		i = i->next;
		free(aux);
	}
}

void	fill_list(int fd, t_list_gnl *to_fill)
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
			to_fill->next = ft_lstnew_gnl();
			to_fill = to_fill->next;
		}
	}
}

char	*gnl(int fd)
{
	t_list_gnl	*line;
	t_list_gnl	*start;
	char		*next_line;
	size_t		i;

	line = ft_lstnew_gnl();
	start = line;
	fill_list(fd, line);
	while (line->next)
		line = line->next;
	i = ft_strlen(line->str) + (BUFFER_SIZE * (ft_dec_lst_size(start)));
	next_line = get_string(start, i);
	ft_lstclear_gnl(start);
	if (!next_line[0])
	{
		free (next_line);
		return (NULL);
	}
	return (next_line);
}
