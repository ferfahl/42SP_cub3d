/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:54:46 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:24:03 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief compares the first n bytes (each interpreted as unsigned char) of the
*memory areas s1 and s2
*@param s1 First memory area where 'n' bytes will be compared.
*@param s2 Second memory area where 'n' bytes will be compared.
*@param n Number of Bytes to be compared
*@return a pointer to the matching byte or NULL if the character does not occur
*in the given memory area
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		count;
	const char	*first;
	const char	*second;

	first = (const char *)s1;
	second = (const char *)s2;
	count = 0;
	if (n == 0)
		return (0);
	while ((*first == *second) && count < n - 1)
	{
		first++;
		second++;
		count++;
	}
	return ((unsigned char)*first - (unsigned char)*second);
}
