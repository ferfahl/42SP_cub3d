/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:26:35 by feralves          #+#    #+#             */
/*   Updated: 2023/06/20 17:03:18 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief Returns a pointer to the last occurrence of the character 'c' in the 
*string 's'. 
*@param s String to be scanned. 
*@param c Character as integer to search. 
*@return Pointer to the matched character or NULL if the character is not 
*found. The terminating null byte is considered part of the string, so that 
*if 'c' is specified as '\0', these functions return a pointer to the 
*terminator.
*/
char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*dest;

	if (!s)
		return (NULL);
	str = (char *)s;
	dest = 0;
	if ((char)c == '\0')
		return (&str[ft_strlen(str)]);
	while (*str != '\0')
	{
		if (*str == (char)c)
			dest = str;
		str++;
	}
	return (dest);
}
