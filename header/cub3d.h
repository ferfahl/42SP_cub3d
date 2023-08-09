/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:33:44 by feralves          #+#    #+#             */
/*   Updated: 2023/08/08 18:36:55 by feralves         ###   ########.fr       */
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

typedef struct	s_image
{
	void	*ptr;
	int		*data;
	//items to start the img on mlx
	int		bpp;
	int		line_len;
	int		endian;
}				t_image;

typedef struct	s_map
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*floor;
	char	*ceiling;
	char	**map;
}				t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_map	*fullmap;
	t_image	img;
}				t_vars;

//main.c
void	if_error(char *str);
void	ft_exit(int status, t_vars *vars);

//sources/00_errors.c
int		ft_error(char *str);

//sources/01_check_args.c
int		check_args(int argc, char *argv[]);

//sources/mlx_util/window.c
void	open_window(t_map *map);

//sources/mlx_util/key_handler.c
int		key_hook(int keycode, t_vars *vars);

//sources/mlx_util/click_handler.c
int		click_hook(t_vars *vars);

//sources/mlx_util/image.c
t_image	create_image(void *addr);

#endif