/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:01:45 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/01 10:17:59 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	game->pos = pos_perso(game->map_ptr->content);
	if (game->map_ptr->content[game->pos.x - 1][game->pos.y] == 'E' ||\
	 game->map_ptr->content[game->pos.x - 1][game->pos.y] == 'Y')
	{
		if (game->co == game->init_co || game->map_ptr->content[game->pos.x - 1][game->pos.y] == 'Y')
			ft_exit(game);		
		game->trig = 1;
		game->map_ptr->content[game->pos.x - 1][game->pos.y] = 'P';
		game->map_ptr->content[game->pos.x][game->pos.y] = '0';
		count_move(game);
	}
	else if (game->map_ptr->content[game->pos.x - 1][game->pos.y] == '0'\
	|| game->map_ptr->content[game->pos.x - 1][game->pos.y] == 'C')
	{
		if (game->trig == 1)
			move_up_reexit(game);
		else 
		{
			if (game->map_ptr->content[game->pos.x - 1][game->pos.y] == 'C')
				game->co += 1;
			game->map_ptr->content[game->pos.x - 1][game->pos.y] = 'P';
			game->map_ptr->content[game->pos.x][game->pos.y] = '0';
			count_move(game);
		}
	}
}

void	move_down(t_game *game)
{
	game->pos = pos_perso(game->map_ptr->content);
	if (game->map_ptr->content[game->pos.x + 1][game->pos.y] == 'E' ||\
	 game->map_ptr->content[game->pos.x + 1][game->pos.y] == 'Y')
	{
		if (game->co == game->init_co || game->map_ptr->content[game->pos.x + 1][game->pos.y] == 'Y')
			ft_exit(game);
		game->trig = 1;
		game->map_ptr->content[game->pos.x + 1][game->pos.y] = 'P';
		game->map_ptr->content[game->pos.x][game->pos.y] = '0';
		count_move(game);
	}
	else if (game->map_ptr->content[game->pos.x + 1][game->pos.y] == '0'\
	|| game->map_ptr->content[game->pos.x + 1][game->pos.y] == 'C')
	{
		if (game->trig == 1)
			move_down_reexit(game);
		else
		{
			if (game->map_ptr->content[game->pos.x + 1][game->pos.y] == 'C')
				game->co += 1;
			game->map_ptr->content[game->pos.x + 1][game->pos.y] = 'P';
			game->map_ptr->content[game->pos.x][game->pos.y] = '0';
			count_move(game);
		}
	}
}

void	move_right(t_game *game)
{
	game->pos = pos_perso(game->map_ptr->content);
	if (game->map_ptr->content[game->pos.x][game->pos.y + 1] == 'E' ||\
	 game->map_ptr->content[game->pos.x][game->pos.y + 1] == 'Y')
	{
		if (game->co == game->init_co || game->map_ptr->content[game->pos.x][game->pos.y + 1] == 'Y')
			ft_exit(game);
		game->trig = 1;
		game->map_ptr->content[game->pos.x][game->pos.y + 1] = 'P';
		game->map_ptr->content[game->pos.x][game->pos.y] = '0';
		count_move(game);
	}
	else if (game->map_ptr->content[game->pos.x][game->pos.y + 1] == '0'\
	|| game->map_ptr->content[game->pos.x][game->pos.y + 1] == 'C')
	{
		if (game->trig == 1)
			move_right_reexit(game);
		else
		{
			if (game->map_ptr->content[game->pos.x][game->pos.y + 1] == 'C')
				game->co += 1;
			game->map_ptr->content[game->pos.x][game->pos.y + 1] = 'P';
			game->map_ptr->content[game->pos.x][game->pos.y] = '0';
			count_move(game);
		}
	}
}

void	move_left(t_game *game)
{
	game->pos = pos_perso(game->map_ptr->content);
	if (game->map_ptr->content[game->pos.x][game->pos.y - 1] == 'E' ||\
	 game->map_ptr->content[game->pos.x][game->pos.y - 1] == 'Y')
	{
		if (game->co == game->init_co || game->map_ptr->content[game->pos.x][game->pos.y - 1] == 'Y')
			ft_exit(game);
		game->trig = 1;
		game->map_ptr->content[game->pos.x][game->pos.y - 1] = 'P';
		game->map_ptr->content[game->pos.x][game->pos.y] = '0';
		count_move(game);
	}
	else if (game->map_ptr->content[game->pos.x][game->pos.y - 1] == '0'\
	|| game->map_ptr->content[game->pos.x][game->pos.y - 1] == 'C')
	{
		if (game->trig == 1)
			move_left_reexit(game);
		else
		{
			if (game->map_ptr->content[game->pos.x][game->pos.y - 1] == 'C')
				game->co += 1;
			game->map_ptr->content[game->pos.x][game->pos.y - 1] = 'P';
			game->map_ptr->content[game->pos.x][game->pos.y] = '0';
			count_move(game);
		}
	}
}
