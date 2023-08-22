/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_itoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:19:50 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:40:22 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(unsigned long int number);
static void	ft_write(int size, char *string, unsigned long int n);

/**
*@brief Allocates and returns a string representing the unsigned long integer 
*received as an argument
*@param n: the unsigned long integer to convert
*@return the string representing the unsigned long integer. NULL if the 
*allocation fails
*/
char	*ft_pointer_itoa(unsigned long int n)
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

static int	ft_counter(unsigned long int number)
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

static void	ft_write(int size, char *string, unsigned long int n)
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
