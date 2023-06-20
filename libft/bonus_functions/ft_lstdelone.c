/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:44:16 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:41:49 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief Takes as a parameter a node and frees the memory of the node’s content
*using the function ’del’ given as a parameter and free the node. The memory of
*’next’ must not be freed.
*@param lst: The node to free.
*@param del: The address of the function used to delete the content
*@return none
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));
