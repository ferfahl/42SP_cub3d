/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 01:38:50 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:46:03 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//Libraries
# include "../libft.h"
# include <stdarg.h>

//Functions

int	ft_print_char(va_list args);
int	ft_print_hexadecimal(va_list args, char placeholder);
int	ft_print_integer(va_list args);
int	ft_print_pointer(va_list args);
int	ft_print_unsigned(va_list args);
int	ft_print_string(va_list args);
int	search_placeholder(char placeholder, va_list args);
int	ft_printf(const char *format, ...);

#endif
