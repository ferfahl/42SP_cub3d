/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:04:51 by feralves          #+#    #+#             */
/*   Updated: 2023/08/22 10:19:45 by feralves         ###   ########.fr       */
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

typedef struct s_map_line	t_map_line;
typedef struct s_input		t_input;
typedef struct s_pos		t_pos;
typedef struct s_player		t_player;
typedef struct s_rays		t_rays;
typedef struct s_image		t_image;
typedef struct s_map		t_map;
typedef struct s_vars		t_vars;

//3d_rendering/background.c
void		draw_background(t_cub *cub);

//3d_rendering/nbr_adjustments.c
int			texture_offset_x(t_rays ray);
int			top_bot_pixel(t_cub *cub, int x, int control);
int			wall_strip(t_cub *cub, int x);

//3d_rendering/render_walls.c
void		generate_projection(t_cub *cub);

//checks/01_check_args.c
int			check_extension(char *path, char *extension);
int			check_args(int argc, char *argv[]);
int			open_file(char *file_name);

//checks/02_read_input.c
t_map_line	*skip_empty_lines(t_map_line *start);
t_map		*get_map(t_input **input);

//checks/03_check_colors.c
int			check_all(char *line, t_input *input);
int			check_c(char *line, t_input *input);
int			check_f(char *line, t_input *input);
char		**trim_color(char **color);

//checks/04_check_textures.c
int			check_ea(char *line, t_input *input);
int			check_we(char *line, t_input *input);
int			check_so(char *line, t_input *input);
int			check_no(char *line, t_input *input);

//exit/errors.c
int			ft_error(char *str);
void		ft_exit_error(char *str, t_cub *cub);

//exit/exit.c
void		ft_exit(int status, t_cub *cub);
void		if_error(char *str);

//exit/free_all.c
void		free_all(t_map_line *map_line, t_input *input, int **map);
void		free_input(t_input *input);
void		free_map(t_map *map);
void		free_map_lines(t_map_line *map_line);
void		ft_free_map_array(int **array, int y);

//exit/free_cub.c
void		free_cub(t_cub *cub);

//map_handle/check_map.c
int			get_tile(char c, t_input **input, int x, int y);
int			verify_map(t_map_line *map, t_input **input, int inside_map);

//map_handle/check_path.c
int			verify_path(t_map *map, int x, int y);

//map_handle/draw_minimap.c
void		draw_mini_map(t_cub *cub, t_map *map);

//map_handle/map_limit.c
int			map_wall(t_map *map, float x, float y);
int			map_floor(t_map *map, float x, float y);

//map_handle/print_map.c
void		print_map(t_map *map, int **print);

//map_handle/read_map.c
int			**create_map(t_map_line *start, t_input **input,
				size_t counter, size_t i);
int			**read_map(int fd, t_input **input, t_map_line *node);
t_map_line	*new_map_node(void);

//mlx_util/click_handler.c
int			click_hook(t_cub *cub);

//mlx_util/draw_line.c
void		draw_line(t_image *image, t_pos a, t_pos b, int color);

//mlx_util/draw.c
void		my_mlx_pixel_put(t_image *image, int x, int y, int color);
void		draw_square(t_image *image, t_pos id, int size, int color);
void		print_tile(t_image *image, size_t x, size_t y, int color);
void		draw_circle(t_image *image, int xc, int yc, int r);

//mlx_util/render.c
int			render(t_cub *cub);
t_image		create_var_image(void *addr);
void		creating_img(t_cub *cub);

//mlx_util/click_handler.c
int			key_hook(int key, t_cub *cub);

//mlx_util/load_textures.c
void		load_textures(t_cub *cub);

//mlx_util/window.c
void		mlx_hooks(t_cub *cub);
void		open_window(t_cub	*cub);

//player_handle/player_moves.c
void		move_player(t_cub *cub, int walk, int control);
void		change_player_pos(int keycode, t_cub *cub);
void		turn_player(int keycode, t_cub *cub);

//rays/cast_rays.c
void		find_closest_wall(t_hit *h, t_hit *v, t_player *p, float angle);
void		find_hit(t_cub *cub, t_player *player, t_rays *ray);
void		cast_all_rays(t_cub *cub);

//rays/find_hit_horz.c
t_hit		get_horz_hit(t_cub *cub, t_rays ray);

//rays/find_hit_vert.c
t_hit		get_vert_hit(t_cub *cub, t_rays ray);

//rays/ray_check.c
int			is_facing_down(float angle);
int			is_facing_up(float angle);
int			is_facing_right(float angle);
int			is_facing_left(float angle);

//rays/ray_utils.c
void		start_ray(t_rays *ray, t_player *player, float angle);
float		get_dist(t_player *p, t_hit h);

//calculate.c
float		normalize_angle(float angle);
float		dist_points(float x1, float y1, float x2, float y2);
double		radians(double degree);

//start_cub.c
t_player	*start_player(int x, int y, int dir);
t_input		*start_input(int argc, char *argv[]);
t_map		*generate_map(int fd, t_input **input);
void		start_game(t_map *map, t_player *p1);

#endif