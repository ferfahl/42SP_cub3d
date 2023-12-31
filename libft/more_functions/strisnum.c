/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strisnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:22:00 by feralves          #+#    #+#             */
/*   Updated: 2023/08/17 18:22:03 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief checks for a digit (0 through 9).
*@param c String as a void
*@return returns non-zero value if c is a digit, else it returns 0
*/
int	strisnum(const char *str)
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
