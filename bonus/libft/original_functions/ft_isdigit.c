/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 04:25:13 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:23:43 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief checks for a digit (0 through 9).
*@param c Character as an integer
*@return returns non-zero value if c is a digit, else it returns 0
*/
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2);
	return (0);
}
