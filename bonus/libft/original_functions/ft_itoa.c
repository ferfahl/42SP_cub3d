/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:19:50 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:23:56 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(int number);
static void	ft_write(int size, int negative, char *string, int n);

/**
*@brief Allocates and returns a string representing the integer received as an
*argument
*@param n: the integer to convert
*@return the string representing the integer. NULL if the allocation fails
*/
char	*ft_itoa(int n)
{
	int		size;
	int		negative;
	char	*string;

	negative = 0;
	size = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		negative = 1;
		n *= -1;
	}
	size = (ft_counter(n) + negative);
	string = malloc(size + 1);
	if (!string)
		return (NULL);
	if (negative)
		string[0] = '-';
	string[size] = '\0';
	size--;
	ft_write(size, negative, string, n);
	return (string);
}

static int	ft_counter(int number)
{
	int	count;

	count = 1;
	while (number > 9)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

static void	ft_write(int size, int negative, char *string, int n)
{
	while (size - negative >= 0)
	{
		string[size] = '0' + (n % 10);
		n = n / 10;
		size--;
	}
}
