/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:35:23 by feralves          #+#    #+#             */
/*   Updated: 2023/08/19 14:12:30 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_input
{
	int		has_no;
	int		has_so;
	int		has_we;
	int		has_ea;
	int		has_f;
	int		has_c;
	int		no_fd;
	int		so_fd;
	int		we_fd;
	int		ea_fd;
	int		f;
	int		c;
	int		**map;
}				t_input;

typedef struct s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct s_hit
{
	float	distance;
	float	hit[2];
	float	intercept[2];
	float	step[2];
	int		hitted;
}				t_hit;

typedef struct s_player
{
	float	angle;
	float	pos[2];
	float	rotate;
	int		turn_direction;
	int		walk_direction;
}				t_player;

typedef struct s_rays
{
	int		facing_down;
	int		facing_up;
	int		facing_right;
	int		facing_left;
	int		was_hit_vert;
	float	angle;
	float	dist;
	float	init[2];
	float	wall_hit[2];
}				t_rays;

typedef struct s_image
{
	void	*ptr;
	int		*data;
	int		bpp;
	int		line_len;
	int		endian;
}				t_image;

typedef struct s_map
{
	int		north;
	int		south;
	int		east;
	int		west;
	int		floor;
	int		ceiling;
	int		x_len;
	int		y_len;
	int		**map;
	int		depth;
}				t_map;

typedef struct s_cub
{
	int			nbr_rays;
	void		*mlx;
	void		*win;
	t_map		*fullmap;
	t_rays		*rays;
	t_image		img;
	t_player	*player;
}				t_cub;


#endif