/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:44:13 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:41:45 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief Deletes and frees the given node and every successor of that node, using
*the function ’del’ and free(3). Finally, the pointer to the list must be set to
*NULL.
*@param lst: The address of a pointer to a node.
*@param del: The address of the function used to delete the content of the node
*@return none
*/
void	ft_lstclear(t_list **lst, void (*del)(void *));
