/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:41:14 by feralves          #+#    #+#             */
/*   Updated: 2023/06/20 16:59:39 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief Copy strings and is designed to be safer, more consistent, and less 
*error prone replacement for strncpy(). Unlike strncpy(), strlcpy() take the 
*full size of the buffer (not just the length) and guarantee to NUL-terminate 
*the result (as long as size is larger than 0). Note that a byte for the NUL 
*should be included in 'size'. Also note that strlcpy() only operate on true “C”
*strings. This means that 'src' must be NUL-terminated.
*@param dest Pointer to the destination string. 
*@param src Pointer to the source string. 
*@param size Size of the buffer. 
*@return Total length of the created string.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (!dst || !src)
		return (0);
	while (count + 1 < size && src[count])
	{
		dst[count] = src[count];
		count++;
	}
	if (size > 0)
		dst[count] = '\0';
	return (ft_strlen(src));
}
