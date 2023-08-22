/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:13:21 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:31:04 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief Applies the function 'f' to each character of the string 's', and 
*passing its index as first argument to create a new string (with malloc()) 
*resulting from successive applications of 'f'. 
*@param s The string on which to iterate. 
*@param f The function to apply to each character. 
*@return The string created from the successive applications of 'f' or NULL if 
*the allocation fails.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	count;
	char			*dest;

	count = 0;
	if (!s || !f)
		return (NULL);
	dest = malloc((ft_strlen(s) + 1) * sizeof(*dest));
	if (!dest)
		return (NULL);
	while (s[count] != '\0')
	{
		dest[count] = f(count, s[count]);
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
