/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:51:02 by mapoirie          #+#    #+#             */
/*   Updated: 2023/07/31 10:20:06 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	new_img(int w, int h, t_game *game)
{
	t_img	image;

	image.img_ptr = mlx_new_image(game->mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.width = w;
	image.height = h;
	return (image);
}

t_img	new_file_img(char * path, t_game *game)
{
	t_img image;

	image.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path, &image.width, &image.height);
	if (!image.img_ptr)
		write(2, "File could not be read\n", 23);
	else
		image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	return (image);
}

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.width && y < img.height) {
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

unsigned int	get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.addr + (y * img.line_len) + (x * img.bpp / 8))));
}

void	put_img_to_img(t_img dst, t_img src, int x, int y)
{
	int i;
	int j;

	i = 0;
	while(i < src.width)
	{
		j = 0;
		while (j < src.height) {
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}