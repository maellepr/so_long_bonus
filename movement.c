/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:01:45 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/03 15:10:58 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	game->pos = pos_perso(game->map_ptr->content);
	if (game->map_ptr->content[game->pos.x - 1][game->pos.y] == 'E' || \
	game->map_ptr->content[game->pos.x - 1][game->pos.y] == 'Y')
	{
		if (game->co == game->init_co || \
		game->map_ptr->content[game->pos.x - 1][game->pos.y] == 'Y')
			ft_exit(game);
		game->trig = 1;
		game->map_ptr->content[game->pos.x - 1][game->pos.y] = 'P';
		game->map_ptr->content[game->pos.x][game->pos.y] = '0';
		count_move(game);
	}
	else if (game->map_ptr->content[game->pos.x - 1][game->pos.y] == '0'\
	|| game->map_ptr->content[game->pos.x - 1][game->pos.y] == 'C')
		move_up2(game);
}

void	move_down(t_game *game)
{
	game->pos = pos_perso(game->map_ptr->content);
	if (game->map_ptr->content[game->pos.x + 1][game->pos.y] == 'E' || \
	game->map_ptr->content[game->pos.x + 1][game->pos.y] == 'Y')
	{
		if (game->co == game->init_co || \
		game->map_ptr->content[game->pos.x + 1][game->pos.y] == 'Y')
			ft_exit(game);
		game->trig = 1;
		game->map_ptr->content[game->pos.x + 1][game->pos.y] = 'P';
		game->map_ptr->content[game->pos.x][game->pos.y] = '0';
		count_move(game);
	}
	else if (game->map_ptr->content[game->pos.x + 1][game->pos.y] == '0'\
	|| game->map_ptr->content[game->pos.x + 1][game->pos.y] == 'C')
		move_down2(game);
}

void	move_right(t_game *game)
{
	game->pos = pos_perso(game->map_ptr->content);
	if (game->map_ptr->content[game->pos.x][game->pos.y + 1] == 'E' || \
	game->map_ptr->content[game->pos.x][game->pos.y + 1] == 'Y')
	{
		if (game->co == game->init_co || \
		game->map_ptr->content[game->pos.x][game->pos.y + 1] == 'Y')
			ft_exit(game);
		game->trig = 1;
		game->map_ptr->content[game->pos.x][game->pos.y + 1] = 'P';
		game->map_ptr->content[game->pos.x][game->pos.y] = '0';
		count_move(game);
	}
	else if (game->map_ptr->content[game->pos.x][game->pos.y + 1] == '0'\
	|| game->map_ptr->content[game->pos.x][game->pos.y + 1] == 'C')
		move_right2(game);
}

void	move_left(t_game *game)
{
	game->pos = pos_perso(game->map_ptr->content);
	if (game->map_ptr->content[game->pos.x][game->pos.y - 1] == 'E' || \
	game->map_ptr->content[game->pos.x][game->pos.y - 1] == 'Y')
	{
		if (game->co == game->init_co || \
		game->map_ptr->content[game->pos.x][game->pos.y - 1] == 'Y')
			ft_exit(game);
		game->trig = 1;
		game->map_ptr->content[game->pos.x][game->pos.y - 1] = 'P';
		game->map_ptr->content[game->pos.x][game->pos.y] = '0';
		count_move(game);
	}
	else if (game->map_ptr->content[game->pos.x][game->pos.y - 1] == '0'\
	|| game->map_ptr->content[game->pos.x][game->pos.y - 1] == 'C')
		move_left2(game);
}
