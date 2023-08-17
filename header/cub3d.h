/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:33:44 by feralves          #+#    #+#             */
/*   Updated: 2023/08/20 16:22:53 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "defs.h"
# include "structs.h"
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

typedef struct s_map_line
{
	char				*line;
	struct s_map_line	*next;
}				t_map_line;

typedef struct s_list_gnl
{
	char				*str;
	struct s_list_gnl	*next;
}				t_list_gnl;

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
	size_t	map_height;
	size_t	map_width;
	int		**map;
}				t_input;

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
void	ft_exit(int status, t_cub *cub);

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
int		open_file(char *file_name);

//sources/mlx_util/window.c
void	open_window(t_cub	*cub);
void	mlx_hooks(t_cub *cub);

//sources/mlx_util/key_handler.c
int		key_hook(int keycode, t_cub *cub);

//sources/mlx_util/click_handler.c
int		click_hook(t_cub *cub);

//sources/mlx_util/image.c
t_image	create_var_image(void *addr);
int		render(t_cub *cub);

//sources/mlx_util/draw.c
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
void	print_tile(t_image *image, size_t x, size_t y, int color);
void	draw_square(t_image *image, t_pos id, int size, int color);
void	draw_circle(t_image *image, int xc, int yc, int r);

//sources/mlx_util/draw_line.c
void	draw_line(t_image *image, t_pos a, t_pos b, int color);

//sources/mlx_util/temp.c
void	draw_background(t_cub *cub);
void	creating_img(t_cub *cub);
void	draw_mini_map(t_cub *cub, t_map *map);

//sources/player/player_moves.c
void	change_player_pos(int keycode, t_cub *cub);
void	turn_player(int keycode, t_cub *cub);

//sources/map_handle.c
int		map_wall(t_map *mapped, float x, float y);

//sources/player_handle/cast_rays.c
void	cast_all_rays(t_cub *cub);

//sources/rays/ray_check.c
int		is_facing_down(float angle);
int		is_facing_up(float angle);
int		is_facing_right(float angle);
int		is_facing_left(float angle);

//sources/rays/find_hit_horz.c
t_hit	get_horz_hit(t_cub *cub, t_rays ray);

//sources/rays/find_hit_horz.c
t_hit	get_vert_hit(t_cub *cub, t_rays ray);

//sources/ray/ray_utils.c
void	start_ray(t_rays *ray, t_player *player, float angle);
float	get_dist(t_player *player, t_hit hit);

//sources/checks/02_check_textures.c
int		check_no(char *line, t_input *input);
int		check_so(char *line, t_input *input);
int		check_we(char *line, t_input *input);
int		check_ea(char *line, t_input *input);

//sources/checks/03_check_colors.c
int		check_c(char *line, t_input *input);
int		check_f(char *line, t_input *input);

void	check_all(char *line, t_input *input);
char	*gnl(int fd);

void	generate_projection(t_cub *cub);
int		wall_strip(t_cub *cub, int x);

#endif