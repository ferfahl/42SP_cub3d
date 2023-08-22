/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:05:03 by feralves          #+#    #+#             */
/*   Updated: 2023/06/20 16:59:16 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief returns a new string, which is the result of the concatenation of ’s1’
*and ’s2’.
*@param s1: The prefix string
*@param s2: The suffix string.
*@return the new string, NULL if the allocation fails
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	count;
	size_t	index;

	count = 0;
	index = 0;
	if (!s1 && !s2)
		return (NULL);
	dest = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(*dest));
	if (!dest)
		return (NULL);
	while (s1 && s1[count])
	{
		dest[count] = s1[count];
		count++;
	}
	while (s2 && s2[index])
	{
		dest[count + index] = s2[index];
		index++;
	}
	dest[count + index] = '\0';
	return (dest);
}
