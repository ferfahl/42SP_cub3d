/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_whitespaces.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:34:26 by rarobert          #+#    #+#             */
/*   Updated: 2023/08/16 20:35:03 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_whitespaces(const char *str)
{
	char	*whitespaces;

	whitespaces = malloc(sizeof(char) * 8);
	whitespaces[0] = 9;
	whitespaces[1] = 10;
	whitespaces[2] = 11;
	whitespaces[3] = 12;
	whitespaces[4] = 13;
	whitespaces[5] = 32;
	whitespaces[6] = 133;
	whitespaces[7] = 0;
	return (ft_strtrim(str, whitespaces));
}
