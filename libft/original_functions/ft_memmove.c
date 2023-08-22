/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:01:06 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:24:07 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief copies n bytes from memory area src to memory area dest.The memory areas
*may overlap: copying takes place as though the bytes in src are first copied
*into a temporary array that does not overlap src or dest, and the bytes are then
*copied from the temporary array to dest.
*@param dest dest Memory area to be replaced.
*@param src Memory area to be moved.
*@param n Number of bytes to be moved.
*@return a pointer to dest
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;

	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	if (ft_strlen(dest) >= ft_strlen(src))
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			n--;
			dest2[n] = src2[n];
		}
	}
	return (dest2);
}
