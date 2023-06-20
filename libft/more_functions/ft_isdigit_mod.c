/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:30:59 by feralves          #+#    #+#             */
/*   Updated: 2023/04/05 19:27:50 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief checks for a digit (0 through 9).
*@param c String as a void
*@return returns non-zero value if c is a digit, else it returns 0
*/
int	ft_isdigit_mod(char *string)
{
	int	i;

	i = 0;
	while (string[++i])
	{
		if (!ft_isdigit(string[i]) && string[0] != '-' && string[0] != '+')
			return (0);
	}
	return (2);
}
