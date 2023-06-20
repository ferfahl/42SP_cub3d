/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:08:12 by feralves          #+#    #+#             */
/*   Updated: 2023/06/20 17:06:04 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief allocates and returns a copy of 's1' with the characters specified in 
*'set' removed from begining and end of string
*@param s1: The string to be trimmed.
*@param set: The reference set of characters to trim.
*@return The trimmed string. NULL if the allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		lenght;
	int		size;
	char	*dest;

	if (!s1)
		return (NULL);
	if (!set || !ft_strlen(set))
		return (ft_strdup(s1));
	lenght = (ft_strlen(s1) - 1);
	start = 0;
	size = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (lenght > start && ft_strchr(set, s1[lenght]))
		lenght--;
	if (start <= lenght)
		dest = malloc(((++lenght - start) + 1) * sizeof(*dest));
	else
		dest = malloc(1);
	while (start < lenght)
		dest[size++] = s1[start++];
	dest[size] = '\0';
	return (dest);
}
