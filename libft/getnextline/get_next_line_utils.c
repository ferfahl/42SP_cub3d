/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:40:27 by rarobert          #+#    #+#             */
/*   Updated: 2023/08/21 14:49:43 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*ft_listnew(void)
{
	t_gnl	*node;

	node = (t_gnl *)malloc(sizeof(t_gnl));
	if (!node)
		return (NULL);
	node->next = NULL;
	return (node);
}

int	ft_dec_lst_size(t_gnl *lst)
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

void	ft_lstclear(t_gnl *lst)
{
	t_gnl	*aux;
	t_gnl	*i;

	i = lst;
	while (i)
	{
		free(i->str);
		aux = i;
		i = i->next;
		free(aux);
	}
}
