/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:30:59 by feralves          #+#    #+#             */
/*   Updated: 2023/08/16 20:08:03 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief checks for a digit (0 through 9).
*@param c String as a void
*@return returns non-zero value if c is a digit, else it returns 0
*/
int	ft_strisdigit(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		return (FALSE);
	while (*str && ft_isdigit(*str))
		str++;
	if (*str)
		return (FALSE);
	return (TRUE);
}
