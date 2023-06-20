/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:44:25 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:41:56 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief Iterates the list ’lst’ and applies the function ’f’ on the content of
*each node. Creates a new list resulting of the successive applications of the
*function ’f’. The ’del’ function is used to delete the content of a node if
*needed.
*@param lst: The address of a pointer to a node.f: The address of the function
*used to iterate on the list.
*@param del: The address of the function used to delete the content of a node if
*needed
*@return The new list. / NULL if the allocation fails.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
