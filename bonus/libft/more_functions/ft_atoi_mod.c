/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:05:28 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:37:00 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief converts the initial portion of the string pointed to by nptr to int
*@param nptr Pointer to the area of memory of the string
*@return long int the converted value or 0 on error
*/
long int	ft_atoi_mod(char *nptr)
{
	long int	count;
	long int	result;
	long int	signal;

	signal = 1;
	count = 0;
	result = 0;
	while ((nptr[count] >= 9 && nptr[count] <= 13) || nptr[count] == ' ')
		count++;
	if (nptr[count] == '+' || nptr[count] == '-')
	{
		if (nptr[count] == '-')
			signal = -1;
		count++;
	}
	while (count < (int)ft_strlen(nptr) && ft_isdigit(nptr[count]))
	{
		result = result * 10 + (nptr[count] - 48);
		count++;
	}
	return (result * signal);
}
