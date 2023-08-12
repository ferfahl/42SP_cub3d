/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:33:44 by feralves          #+#    #+#             */
/*   Updated: 2023/08/12 15:15:22 by feralves         ###   ########.fr       */
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

// int		turn_direction; //-1 for left, +1 for right
// int		walk_direction; //-1 for back, +1 for front

typedef struct s_player
{
	int		x;
	int		y;
	int		size;
	int		turn_direction;
	int		walk_direction;
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
}				t_player;

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
	void		*mlx;
	void		*win;
	t_map		*fullmap;
	t_image		img;
	t_player	*player;
}				t_vars;

//exit.c
void	if_error(char *str);
void	ft_exit(int status, t_vars *vars);

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
void	print_square(t_image *image, size_t x, size_t y, int size);

//sources/mlx_util/temp.c
void	draw_background(t_vars *vars);
void	creating_img(t_vars *vars);

//sources/player/player_moves.c
void	move_player(t_map *mapped, t_player *p1);
void	change_player_pos(int keycode, t_vars *vars);

//sources/map_handle.c
int		map_wall(t_map *mapped, float x, float y);

#endif