/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_check_colors_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:31:10 by rarobert          #+#    #+#             */
/*   Updated: 2023/08/22 16:21:06 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	get_color(char **color)
{
	int	colour;
	int	red;
	int	green;
	int	blue;

	red = ft_atoi(color[0]);
	green = ft_atoi(color[1]);
	blue = ft_atoi(color[2]);
	if ((red < 0 || red >= 255) || (blue < 0 || blue >= 255)
		|| (green < 0 || green >= 255))
		return (ft_error("Invalid RGB color"));
	colour = RED_RGB * red;
	colour += GREEN_RGB * green;
	colour += BLUE_RGB * blue;
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

	if (!ft_strncmp(line, "F ", 2))
	{
		if (input->has_f)
			return (ft_error("More than one floor"));
		input->has_f = TRUE;
		color = ft_split(line + 1, ',');
		if (!(color[0]) || !(color[1]) || !(color[2]))
		{
			ft_free_array(color);
			return (ft_error("Invalid ceiling RGB"));
		}
		color = trim_color(color);
		if (!strisnum(color[0]) || !strisnum(color[1]) || !strisnum(color[2]))
		{
			ft_free_array(color);
			return (ft_error("Invalid ceiling RGB"));
		}
		input->f = get_color(color);
		ft_free_array(color);
		if (input->f == -1)
			return (-1);
	}
	return (0);
}

int	check_c(char *line, t_input *input)
{
	char	**color;

	if (!ft_strncmp(line, "C ", 2))
	{
		if (input->has_c)
			return (ft_error("More than one ceiling"));
		input->has_c = TRUE;
		color = ft_split(line + 1, ',');
		if (!(color[0]) || !(color[1]) || !(color[2]))
		{
			ft_free_array(color);
			return (ft_error("Invalid ceiling RGB"));
		}
		color = trim_color(color);
		if (!strisnum(color[0]) || !strisnum(color[1]) || !strisnum(color[2]))
		{
			ft_free_array(color);
			return (ft_error("Invalid ceiling RGB"));
		}
		input->c = get_color(color);
		ft_free_array(color);
		if (input->c == -1)
			return (-1);
	}
	return (0);
}

int	check_all(char *line, t_input *input)
{
	if (line[0] && !check_env(line))
	{
		ft_error("Invalid elements order or elements missing");
		return (FALSE);
	}
	if (check_no(line, input))
		return (FALSE);
	if (check_so(line, input))
		return (FALSE);
	if (check_ea(line, input))
		return (FALSE);
	if (check_we(line, input))
		return (FALSE);
	if (check_f(line, input))
		return (FALSE);
	if (check_c(line, input))
		return (FALSE);
	return (TRUE);
}
