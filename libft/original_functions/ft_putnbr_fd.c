/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:27:33 by feralves          #+#    #+#             */
/*   Updated: 2023/02/26 19:24:15 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief outputs the integer ’n’ to the given file descriptor
*@param n: The integer to output
*@param fd: The file descriptor on which to write
*@return none
*/
void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	uns_n;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		uns_n = (unsigned int)(n * (-1));
	}
	else
		uns_n = (unsigned int)n;
	if (uns_n >= 10)
		ft_putnbr_fd((uns_n / 10), fd);
	ft_putchar_fd((uns_n % 10) + '0', fd);
}
