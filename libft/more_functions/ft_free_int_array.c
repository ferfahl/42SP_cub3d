/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_int_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:04:40 by feralves          #+#    #+#             */
/*   Updated: 2023/08/21 19:24:36 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief Frees the items and the array passed.
*@param array The array to be freed.
*@return none
*/
void	ft_free_int_array(int **array)
{
	void	*temp;

	temp = array;
	while (*array != NULL)
		free(*array++);
	free(temp);
}
