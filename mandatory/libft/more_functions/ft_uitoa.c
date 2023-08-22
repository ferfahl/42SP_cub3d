/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:19:50 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:38:47 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(unsigned int number);
static void	ft_write(int size, char *string, unsigned int n);

/**
*@brief Allocates and returns a string representing the unsigned integer 
*received as an argument
*@param n: the unsigned integer to convert
*@return the string representing the unsigned integer. NULL if the allocation 
*fails
*/
char	*ft_uitoa(unsigned int n)
{
	int		size;
	char	*string;

	size = 0;
	size = (ft_counter(n));
	string = malloc(size + 1);
	if (!string)
		return (NULL);
	string[size] = '\0';
	size--;
	ft_write(size, string, n);
	return (string);
}

static int	ft_counter(unsigned int number)
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

static void	ft_write(int size, char *string, unsigned int n)
{
	while (size >= 0)
	{
		string[size] = '0' + (n % 10);
		n = n / 10;
		size--;
	}
}
