/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:06:07 by feralves          #+#    #+#             */
/*   Updated: 2022/10/16 15:29:21 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_char(const char *str, char a)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0' && str[count] != a)
	{
		count++;
	}
	return (count);
}
