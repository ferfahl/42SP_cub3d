/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 23:06:17 by feralves          #+#    #+#             */
/*   Updated: 2022/08/20 01:43:50 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list args)
{
	int	alpha;

	alpha = va_arg(args, int);
	write(1, &alpha, 1);
	return (1);
}

int	ft_print_string(va_list args)
{
	char	*string;

	string = va_arg(args, char *);
	if (!string)
	{
		return (write(1, "(null)", 6));
	}
	ft_putstr_fd(string, 1);
	return (ft_strlen(string));
}

int	ft_print_integer(va_list args)
{
	int		number;
	char	*string;
	int		size;

	number = va_arg(args, int);
	string = ft_itoa(number);
	ft_putstr_fd(string, 1);
	size = ft_strlen(string);
	free(string);
	return (size);
}

int	ft_print_unsigned(va_list args)
{
	unsigned int	number;
	char			*string;
	int				size;

	number = va_arg(args, unsigned int);
	string = ft_uitoa(number);
	ft_putstr_fd(string, 1);
	size = ft_strlen(string);
	free(string);
	return (size);
}
