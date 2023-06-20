/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:35:00 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:23:35 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief allocates memory for an array of nmemb elements of size bytes each and
*returns a pointer to the allocated memory
*@param
*@return a pointer to the allocated memory, which is suitably aligned for any
*built-in type. Or NULL if it fails
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	int		total;
	char	*str;

	total = nmemb * size;
	if (size != 0 && total / size != nmemb)
		return (NULL);
	str = malloc(total * sizeof(*str));
	if (!str)
		return (NULL);
	ft_bzero(str, total);
	return (str);
}
