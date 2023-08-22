/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:55:37 by feralves          #+#    #+#             */
/*   Updated: 2023/06/20 17:00:18 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*Concatenate strings and is designed to be safer, more consistent, and less 
*error prone replacement for strncat(). Unlike strncat(), strlcat() take the 
*full size of the buffer (not just the length) and guarantee to NUL-terminate 
*the result (as long as there is at least one byte free in 'dest'). Note that 
*a byte for the NUL should be included in 'size'. Also note that strlcat() 
*only operate on true “C” strings. This means that both src and dest must be 
*NUL-terminated. *  
*@param dest Pointer to the destination string. 
*@param src Pointer to the source string. 
*@param size Size of the buffer. 
*@return Total length of the created string.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	result;

	count = 0;
	if (!dst || !src)
		return (0);
	result = ft_strlen(dst) + ft_strlen(src);
	if (size < ft_strlen(dst))
		result = (size + ft_strlen(src));
	while (dst[count] && size != 0)
	{
		count++;
		size--;
	}
	if (size > 0)
		ft_strlcpy(&dst[count], src, size);
	return (result);
}
