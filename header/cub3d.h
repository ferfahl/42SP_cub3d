/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:33:44 by feralves          #+#    #+#             */
/*   Updated: 2023/08/21 00:16:49 by feralves         ###   ########.fr       */
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
void	draw_background(t_cub *cub);

//3d_rendering/nbr_adjustments.c
int		texture_offset_x(t_rays ray);
int		top_bot_pixel(t_cub *cub, int x, int control);
int		wall_strip(t_cub *cub, int x);

//3d_rendering/render_walls.c
void	generate_projection(t_cub *cub);

//sources/00_errors.c
int		ft_error(char *str);

//sources/01_check_args.c
int		check_extension(char *path, char *extension);
int		check_args(int argc, char *argv[]);
int		open_file(char *file_name);

//checks/02_check_textures.c


#endif