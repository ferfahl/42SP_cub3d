/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 00:33:14 by feralves          #+#    #+#             */
/*   Updated: 2023/06/20 17:23:12 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	size_till_break(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\n' && str[size]  != '\0')
		size++;
	if (str[size]  == '\n')
		size++;
	return (size);
}
