/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:59:31 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:34:57 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief Allocates (with malloc(3)) and returns a substring from the string ’s’. 
*The substring begins at index ’start’ and is of maximum size ’len’.
*@param s: The string from which to create the substring.
*@param start: The start index of the substring in the string ’s’.
*@param len: The maximum length of the substring.
*@return the substring. NULL if the allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	index;
	size_t			max_size;

	index = 0;
	max_size = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	max_size = ft_strlen(s) - start;
	if (max_size > len)
		max_size = len;
	substring = malloc((max_size + 1) * sizeof(*substring));
	if (!substring)
		return (NULL);
	while (index < max_size)
	{
		substring[index] = s[start];
		start++;
		index++;
	}
	substring[index] = '\0';
	return (substring);
}
