/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:35:23 by feralves          #+#    #+#             */
/*   Updated: 2023/08/20 20:19:55 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>

typedef struct s_map_line
{
	char				*line;
	struct s_map_line	*next;
}				t_map_line;

typedef struct s_input
{
	int		has_no;
	int		has_so;
	int		has_we;
	int		has_ea;
	int		has_f;
	int		has_c;
	char*	no_path;
	char*	so_path;
	char*	we_path;
	char*	ea_path;
	int		f;
	int		c;
	size_t	map_height;
	size_t	map_width;
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
	float	hit[2];
}				t_rays;

typedef struct s_image
{
	void	*ptr;
	void	*texture;
	int		*data;
	int		bpp;
	int		line_len;
	int		endian;
}				t_image;

typedef struct s_map
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		floor;
	int		ceiling;
	int		x_len;
	int		y_len;
	int		**map;
	float	proj_plane;
}				t_map;

typedef struct s_cub
{
	int			nbr_rays;
	void		*mlx;
	void		*win;
	t_map		*map;
	t_rays		*rays;
	t_image		img;
	t_image		north;
	t_image		south;
	t_image		west;
	t_image		east;
	t_player	*player;
}				t_cub;

#endif