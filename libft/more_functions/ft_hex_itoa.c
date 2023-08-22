/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:19:50 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:39:41 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(unsigned int number);
static void	ft_write(int size, char *string, unsigned int n);

/**
*@brief Allocates and returns a string representing the hexadecimal received as 
*an argument
*@param n: the hexadecimal to convert
*@return the string representing the hexadecimal. NULL if the allocation fails
*/
char	*ft_hex_itoa(unsigned int n)
{
	int		size;
	char	*string;

	size = 0;
	size = (ft_counter(n));
	string = malloc(size + 1);
	if (!string)
		return (NULL);
	string[size] = '\0';
	ft_write(size, string, n);
	return (string);
}

static int	ft_counter(unsigned int number)
{
	int	count;

	count = 1;
	while (number > 15)
	{
		number = number / 16;
		count++;
	}
	return (count);
}

static void	ft_write(int size, char *string, unsigned int n)
{
	while (size > 0)
	{
		if ((n % 16) > 9)
			string[size - 1] = 'a' + (n % 16) - 10;
		else
			string[size - 1] = '0' + (n % 16);
		n = n / 16;
		size--;
	}
}
