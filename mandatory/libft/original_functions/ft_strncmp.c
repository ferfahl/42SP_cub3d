/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 02:02:11 by feralves          #+#    #+#             */
/*   Updated: 2023/06/20 17:01:06 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief Compares the first (at most) 'n' bytes of strings s1 and s2. The locale 
*is not taken into account. 
*@param s1 Pointer to the first string. 
*@param s2 Pointer to the second string. 
*@param n Buffer size in bytes to compare both strings. 
*@return An integer less than, equal to, or greater than zero if s1 (or the 
*first n bytes thereof) is found, respectively, to be less than, to match, or 
*be greater than s2.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	if (!s1 || !s2)
		return (-1);
	if (n == 0)
		return (0);
	while (((*s1 == *s2) && *s1 != '\0') && count < n - 1)
	{
		s1++;
		s2++;
		count++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
