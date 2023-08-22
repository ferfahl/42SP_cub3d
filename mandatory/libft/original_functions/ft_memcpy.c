/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 04:22:17 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:24:05 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief copies n bytes from memory area src to memory area dest. The memory
*areas must not overlap
*@param dest Memory area to be replaced.
*@param src Memory area to be moved.
*@param n Number of bytes to be moved.
*@return a pointer to dest
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				count;
	unsigned char		*dest2;
	const unsigned char	*src2;

	count = 0;
	src2 = src;
	dest2 = dest;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (count < n)
	{
		dest2[count] = src2[count];
		count++;
	}
	return (dest);
}
