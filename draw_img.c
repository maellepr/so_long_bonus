/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:02:33 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/02 12:14:04 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_bricks(t_game	*game)
{
	int	i;
	int	j;
	
	i = 0;
	while (game->map_ptr->content[i])
	{
		j = 0;
		while (game->map_ptr->content[i][j])
		{
			if (game->map_ptr->content[i][j] == '1')
				put_img_to_img(game->image_base, game->bricks, (j * 40), (i * 40));
			j++;
		}
		i++;
	}
}

void	draw_floor(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_ptr->content[i])
	{
		j = 0;
		while (game->map_ptr->content[i][j])
		{
			if (game->map_ptr->content[i][j] == '0' || game->map_ptr->content[i][j] == 'C' || game->map_ptr->content[i][j] \
			== 'P' || game->map_ptr->content[i][j] == 'E' || game->map_ptr->content[i][j] == 'Y')
				put_img_to_img(game->image_base, game->floor, (j * 40), (i * 40));
			j++;
		}
		i++;
	}
}

void	draw_collect(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_ptr->content[i])
	{
		j = 0;
		while (game->map_ptr->content[i][j])
		{
			if (game->map_ptr->content[i][j] == 'C')
				put_img_to_img(game->image_base, game->c, (j * 40), (i * 40));
			j++;
		}
		i++;
	}
}

void	draw_perso_enemy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_ptr->content[i])
	{
		j = 0;
		while (game->map_ptr->content[i][j])
		{
			if (game->map_ptr->content[i][j] == 'P' && game->move_pos == 2)
				update_sprite(game, &game->sp_perso, game->sp_perso.frame, (t_point){j, i});// echange j et i
			else if (game->map_ptr->content[i][j] == 'P' && game->move_pos == 5)
				update_sprite(game, &game->sp_perso_back, game->sp_perso_back.frame, (t_point){j, i});
			else if (game->map_ptr->content[i][j] == 'P' && game->move_pos == 3)
				update_sprite(game, &game->sp_perso_right, game->sp_perso_right.frame, (t_point){j, i});
			else if (game->map_ptr->content[i][j] == 'P' && game->move_pos == 1)
				update_sprite(game, &game->sp_perso_left, game->sp_perso_left.frame, (t_point){j, i});
			if (game->map_ptr->content[i][j] == 'Y')
				update_sprite(game, &game->sp_enemy, game->sp_enemy.frame, (t_point){j, i});			
			j++;
		}
		i++;
	}
}

void	draw_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_ptr->content[i])
	{
		j = 0;
		while(game->map_ptr->content[i][j])
		{
			if (game->map_ptr->content[i][j] == 'E')
				put_img_to_img(game->image_base, game->exit, (j * 40), (i * 40));
			j++;
		}
		i++;
	}
}

int render_rect(t_game *data, t_rect rect)
{
    int	i;
    int j;

    if (data->win_ptr == NULL)
        return (1);
    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, rect.color);
        ++i;
    }
    return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
