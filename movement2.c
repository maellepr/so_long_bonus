/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:31:27 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/03 13:58:59 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up2(t_game *game)
{
	if (game->trig == 1)
	{
		if (game->map_ptr->content[game->pos.x - 1][game->pos.y] == 'C')
			game->co += 1;
		game->map_ptr->content[game->pos.x - 1][game->pos.y] = 'P';
		game->map_ptr->content[game->pos.x][game->pos.y] = 'E';
		game->trig = 0;
		count_move(game);
	}
	else
	{
		if (game->map_ptr->content[game->pos.x - 1][game->pos.y] == 'C')
			game->co += 1;
		game->map_ptr->content[game->pos.x - 1][game->pos.y] = 'P';
		game->map_ptr->content[game->pos.x][game->pos.y] = '0';
		count_move(game);
	}
}

void	move_down2(t_game *game)
{
	if (game->trig == 1)
	{
		if (game->map_ptr->content[game->pos.x - 1][game->pos.y] == 'C')
			game->co += 1;
		game->map_ptr->content[game->pos.x + 1][game->pos.y] = 'P';
		game->map_ptr->content[game->pos.x][game->pos.y] = 'E';
		game->trig = 0;
		count_move(game);
	}
	else
	{
		if (game->map_ptr->content[game->pos.x + 1][game->pos.y] == 'C')
			game->co += 1;
		game->map_ptr->content[game->pos.x + 1][game->pos.y] = 'P';
		game->map_ptr->content[game->pos.x][game->pos.y] = '0';
		count_move(game);
	}
}

void	move_right2(t_game *game)
{
	if (game->trig == 1)
	{
		if (game->map_ptr->content[game->pos.x][game->pos.y + 1] == 'C')
			game->co += 1;
		game->map_ptr->content[game->pos.x][game->pos.y + 1] = 'P';
		game->map_ptr->content[game->pos.x][game->pos.y] = 'E';
		game->trig = 0;
		count_move(game);
	}
	else
	{
		if (game->map_ptr->content[game->pos.x][game->pos.y + 1] == 'C')
			game->co += 1;
		game->map_ptr->content[game->pos.x][game->pos.y + 1] = 'P';
		game->map_ptr->content[game->pos.x][game->pos.y] = '0';
		count_move(game);
	}
}

void	move_left2(t_game *game)
{
	if (game->trig == 1)
	{
		if (game->map_ptr->content[game->pos.x][game->pos.y - 1] == 'C')
			game->co += 1;
		game->map_ptr->content[game->pos.x][game->pos.y - 1] = 'P';
		game->map_ptr->content[game->pos.x][game->pos.y] = 'E';
		game->trig = 0;
		count_move(game);
	}
	else
	{
		if (game->map_ptr->content[game->pos.x][game->pos.y - 1] == 'C')
			game->co += 1;
		game->map_ptr->content[game->pos.x][game->pos.y - 1] = 'P';
		game->map_ptr->content[game->pos.x][game->pos.y] = '0';
		count_move(game);
	}
}
