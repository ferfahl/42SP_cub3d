/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:33:44 by feralves          #+#    #+#             */
/*   Updated: 2023/08/15 20:12:23 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "defs.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct s_point
{
	float	x;
	float	y;
}				t_point;

typedef struct s_player
{
	float	angle;
	float	x;
	float	y;
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
	t_point	init;
	t_point	wall_hit;
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
}				t_map;

typedef struct s_vars
{
	int			nbr_rays;
	void		*mlx;
	void		*win;
	t_map		*fullmap;
	t_rays		*rays;
	t_image		img;
	t_player	*player;
}				t_vars;

//exit.c
void	if_error(char *str);
void	ft_exit(int status, t_vars *vars);

//calculate.c
float	normalize_angle(float angle);
double	radians(double degree);
float	dist_points(float x1, float y1, float x2, float y2);

//start_cub.c
void	start_game(t_map *map, t_player *p1);

//sources/00_errors.c
int		ft_error(char *str);

//sources/01_check_args.c
int		check_args(int argc, char *argv[]);

//sources/mlx_util/window.c
void	open_window(t_vars	*vars);
void	mlx_hooks(t_vars *vars);

//sources/mlx_util/key_handler.c
int		key_hook(int keycode, t_vars *vars);

//sources/mlx_util/click_handler.c
int		click_hook(t_vars *vars);

//sources/mlx_util/image.c
t_image	create_var_image(void *addr);
int		render(t_vars *vars);

//sources/mlx_util/draw.c
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
void	print_tile(t_image *image, size_t x, size_t y, int color);
void	print_square(t_image *image, t_pos id, int size, int color);
void	print_circle(t_image *image, int xc, int yc, int r);

//sources/mlx_util/draw_line.c
void	print_line(t_image *image, t_pos a, t_pos b, int color);

//sources/mlx_util/temp.c
void	draw_background(t_vars *vars);
void	creating_img(t_vars *vars);
void	draw_mini_map(t_vars *vars, t_map *map);

//sources/player/player_moves.c
void	change_player_pos(int keycode, t_vars *vars);
void	turn_player(int keycode, t_vars *vars);

//sources/map_handle.c
int		map_wall(t_map *mapped, float x, float y);

//sources/player_handle/cast_rays.c
void	cast_all_rays(t_vars *vars);

//sources/mao_handle/ray_check.c
int		is_facing_down(float angle);
int		is_facing_up(float angle);
int		is_facing_right(float angle);
int		is_facing_left(float angle);

//sources/player_handle/find_hit_horz.c
t_point	get_horz_hit(t_vars *vars, t_rays ray);

//sources/player_handle/find_hit_horz.c
t_point	get_vert_hit(t_vars *vars, t_rays ray);

#endif