/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 23:06:37 by feralves          #+#    #+#             */
/*   Updated: 2022/08/20 01:38:24 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	search_placeholder(char placeholder, va_list args)
{
	int	count;

	if (placeholder == 'c')
		count = ft_print_char(args);
	if (placeholder == 's')
		count = ft_print_string(args);
	if (placeholder == 'p')
		count = ft_print_pointer(args);
	if (placeholder == 'd' || placeholder == 'i')
		count = ft_print_integer(args);
	if (placeholder == 'u')
		count = ft_print_unsigned(args);
	if (placeholder == '%')
		count = write(1, "%", 1);
	if (placeholder == 'x' || placeholder == 'X')
		count = ft_print_hexadecimal(args, placeholder);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		index;
	int		count;

	va_start(args, format);
	index = 0;
	count = 0;
	while (format[index])
	{
		if (format[index] == '%')
		{
			index++;
			count += search_placeholder(format[index], args);
		}
		else
		{
			write(1, &format[index], 1);
			count += 1;
		}
		index++;
	}
	return (count);
}
