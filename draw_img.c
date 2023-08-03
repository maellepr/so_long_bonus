/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:02:33 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/03 13:31:46 by mapoirie         ###   ########.fr       */
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
				put_img_to_img(game->image_base, game->bricks, \
				(j * 40), (i * 40));
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
			if (game->map_ptr->content[i][j] == '0' || \
			game->map_ptr->content[i][j] == 'C' || \
			game->map_ptr->content[i][j] == 'P' || \
			game->map_ptr->content[i][j] == 'E' || \
			game->map_ptr->content[i][j] == 'Y')
				put_img_to_img(game->image_base, game->floor, \
				(j * 40), (i * 40));
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

void	draw_perso(t_game *game)
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
				update_sprite(game, &game->sp_perso, \
				game->sp_perso.frame, (t_point){j, i});
			else if (game->map_ptr->content[i][j] == 'P' && game->move_pos == 5)
				update_sprite(game, &game->sp_perso_back, \
				game->sp_perso_back.frame, (t_point){j, i});
			else if (game->map_ptr->content[i][j] == 'P' && game->move_pos == 3)
				update_sprite(game, &game->sp_perso_right, \
				game->sp_perso_right.frame, (t_point){j, i});
			else if (game->map_ptr->content[i][j] == 'P' && game->move_pos == 1)
				update_sprite(game, &game->sp_perso_left, \
				game->sp_perso_left.frame, (t_point){j, i});
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
		while (game->map_ptr->content[i][j])
		{
			if (game->map_ptr->content[i][j] == 'E')
				put_img_to_img(game->image_base, game->exit, \
				(j * 40), (i * 40));
			j++;
		}
		i++;
	}
}
