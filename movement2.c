/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:31:27 by mapoirie          #+#    #+#             */
/*   Updated: 2023/07/27 10:55:05 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up_reexit(t_game *game)
{
	if (game->map_ptr->content[game->pos.x - 1][game->pos.y] == 'C')
		game->co += 1;
	game->map_ptr->content[game->pos.x - 1][game->pos.y] = 'P';
	game->map_ptr->content[game->pos.x][game->pos.y] = 'E';
	game->trig = 0;
	count_move(game);
}

void	move_down_reexit(t_game *game)
{
	if (game->map_ptr->content[game->pos.x - 1][game->pos.y] == 'C')
		game->co += 1;
	game->map_ptr->content[game->pos.x + 1][game->pos.y] = 'P';
	game->map_ptr->content[game->pos.x][game->pos.y] = 'E';
	game->trig = 0;
	count_move(game);
}

void	move_right_reexit(t_game *game)
{
	if (game->map_ptr->content[game->pos.x][game->pos.y + 1] == 'C')
		game->co += 1;
	game->map_ptr->content[game->pos.x][game->pos.y + 1] = 'P';
	game->map_ptr->content[game->pos.x][game->pos.y] = 'E';
	game->trig = 0;
	count_move(game);
}

void	move_left_reexit(t_game *game)
{
	if (game->map_ptr->content[game->pos.x][game->pos.y - 1] == 'C')
		game->co += 1;	
	game->map_ptr->content[game->pos.x][game->pos.y - 1] = 'P';
	game->map_ptr->content[game->pos.x][game->pos.y] = 'E';
	game->trig = 0;
	count_move(game);
}