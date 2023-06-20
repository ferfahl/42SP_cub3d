/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:13:32 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:24:01 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief scans the initial n bytes of the memory area pointed to by s for the
*first instance of c
*@param s Pointer to memory area to be scanned.
*@param c Char as integers sought in the area.
*@param n Number of bytes to be scanned.
*@return Pointer to the matching byte or NULL if the character does not occur
*in the given memory area.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			count;

	count = 0;
	str = (unsigned char *)s;
	while (count < n)
	{
		if (*str == (unsigned char)c)
		{
			return ((void *)str);
		}
		str++;
		count++;
	}
	return (0);
}
