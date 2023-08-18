/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:48:33 by feralves          #+#    #+#             */
/*   Updated: 2023/08/17 14:55:46 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_facing_down(float angle)
{
	if (angle > 0 && angle < PI)
		return (TRUE);
	return (FALSE);
}

int	is_facing_up(float angle)
{
	if (!is_facing_down(angle))
		return (TRUE);
	return (FALSE);
}

int	is_facing_right(float angle)
{
	if (angle < 0.5 * PI || angle > 1.5 * PI)
		return (TRUE);
	return (FALSE);
}

int	is_facing_left(float angle)
{
	if (!is_facing_right(angle))
		return (TRUE);
	return (FALSE);
}
