/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:24:52 by mapoirie          #+#    #+#             */
/*   Updated: 2023/07/31 14:59:12 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_img_ptr(t_img *image, int w, int h, t_game *game)
{

	image->img_ptr = mlx_new_image(game->mlx_ptr, w, h);
	image->addr = mlx_get_data_addr(image->img_ptr, &(image->bpp),
			&(image->line_len), &(image->endian));
	image->width = w;
	image->height = h;
}

void	put_pixel_img_sprite(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img->width && y < img->height) {
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *) dst = color;
	}
}
