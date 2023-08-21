/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:54:27 by feralves          #+#    #+#             */
/*   Updated: 2023/08/20 20:37:53 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_xpm(t_cub *cub, t_image *img, char *path)
{
	int		width;
	int		height;

	img->ptr = mlx_xpm_file_to_image(cub->mlx, path, &width, &height);
	img->texture = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_len, &img->endian);
	// if (width != height)
		//error texture must be square
}

void	load_textures(t_cub *cub)
{
	load_xpm(cub, &cub->north, cub->map->north);
	load_xpm(cub, &cub->south, cub->map->south);
	load_xpm(cub, &cub->east, cub->map->east);
	load_xpm(cub, &cub->west, cub->map->west);
}