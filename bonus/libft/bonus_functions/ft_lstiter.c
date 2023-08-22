/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:44:19 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:41:51 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief Iterates the list ’lst’ and applies the function ’f’ on the content of
*each node
*@param lst: The address of a pointer to a node.
*@param f: The address of the function used to iterate on
the list
*@return none
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));
