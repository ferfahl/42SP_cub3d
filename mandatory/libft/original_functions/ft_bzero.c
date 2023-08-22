/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:40:52 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:23:31 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief function erases the data in the n bytes of the memory starting at the
*location pointed to by s
*@param s: the string to erase
*@param n: number of bytes to erase
*@return none
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
