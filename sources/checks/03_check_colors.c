/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_check_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:31:10 by rarobert          #+#    #+#             */
/*   Updated: 2023/08/16 21:02:02 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_color(char **color)
{
	int	colour;

	colour = RED_RGB * ft_atoi(color[0]);
	colour += GREEN_RGB * ft_atoi(color[1]);
	colour += BLUE_RGB * ft_atoi(color[2]);
	return (colour);
}

char	**trim_color(char **color)
{
	char	*temp;
	int		i;

	i = 0;
	while (i < 3)
	{
		temp = ft_strtrim_whitespaces(color[i]);
		free(color[i]);
		color[i] = temp;
		i++;
	}
	return (color);
}

int	check_f(char *line, t_input *input)
{
	char	**color;

	if (!ft_strncmp(line, "F", 1))
	{
		if (input->has_f)
			return (ft_error("More than one floor"));
		input->has_f = TRUE;
		color = ft_split(line + 1, ',');
		color = trim_color(color);
		if (!ft_strisdigit(color[0]) || !ft_strisdigit(color[1])
			|| !ft_strisdigit(color[2]))
			return (ft_error("Invalid floor RGB"));
		input->f = get_color(color);
		ft_free_array(color);
	}
	return (0);
}

int	check_c(char *line, t_input *input)
{
	char	**color;

	if (!ft_strncmp(line, "C", 1))
	{
		if (input->has_c)
			return (ft_error("More than one ceiling"));
		input->has_c = TRUE;
		color = ft_split(line + 1, ',');
		color = trim_color(color);
		if (!ft_strisdigit(color[0]) || !ft_strisdigit(color[1])
			|| !ft_strisdigit(color[2]))
			return (ft_error("Invalid ceiling RGB"));
		input->c = get_color(color);
		ft_free_array(color);
	}
	return (0);
}

void	check_all(char *line, t_input *input)
{
	if (check_no(line, input))
		return ;
	if (check_so(line, input))
		return ;
	if (check_ea(line, input))
		return ;
	if (check_we(line, input))
		return ;
	if (check_f(line, input))
		return ;
	if (check_c(line, input))
		return ;
}
