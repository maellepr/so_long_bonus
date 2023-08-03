/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:44:33 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/03 15:06:01 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(t_game *game)
{
	game->move_nb = ft_itoa(game->move);
	if (!game->move_nb)
		ft_exit(game);
	draw_bricks(game);
	draw_floor(game);
	draw_collect(game);
	draw_exit(game);
	draw_perso(game);
	draw_enemy(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->image_base.img_ptr, 0, 0);
	render_rect(game, (t_rect){39, 12, 115, 15, (int)0xffffff});
	render_rect(game, (t_rect){40, 13, 113, 13, (int)0x000000});
	mlx_string_put(game->mlx_ptr, game->win_ptr, 42, 23, \
	(int)0xffffff, "move counter");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 130, 23, \
	(int)0xffffff, game->move_nb);
	free(game->move_nb);
	return (0);
}

int	handle_input(int keysym, t_game *game)
{
	if (keysym == XK_w)
	{	
		move_up(game);
		game->move_pos = 5;
	}
	else if (keysym == XK_s)
	{
		move_down(game);
		game->move_pos = 2;
	}
	else if (keysym == XK_d)
	{
		move_right(game);
		game->move_pos = 3;
	}
	else if (keysym == XK_a)
	{
		move_left(game);
		game->move_pos = 1;
	}
	else if (keysym == XK_Escape)
		ft_exit(game);
	return (0);
}
