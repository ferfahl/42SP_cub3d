/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 05:08:46 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:23:37 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief checks for an alphanumeric character
*@param c Character as an integer
*@return non-zero value if c is an alphanumeric, else it returns 0
*/
int	ft_isalnum(int c)
{
	if (ft_isdigit(c))
		return (2);
	else if (ft_isalpha(c))
		return (1);
	return (0);
}
