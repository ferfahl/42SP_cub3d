/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:00:47 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:24:09 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief fills the first n bytes of the memory area pointed to by s with the
*constant byte c
*@param s Memmory to be replaced.
*@param c Constant byte used to replace.
*@param n Number of bytes to be replaced.
*@return Pointer to the replaced memory area.
*/
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*dest;

	dest = s;
	count = 0;
	while (count < n)
	{
		dest[count] = c;
		count++;
	}
	return (dest);
}
