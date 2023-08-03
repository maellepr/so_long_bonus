/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:07:56 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/03 13:42:42 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	init_bricks(t_game *game)
{
	t_img	img_bricks;

	img_bricks = new_file_img("./images/063bricksq06.xpm", game);
	return (img_bricks);
}

t_img	init_floor(t_game *game)
{
	t_img	img_floor;

	img_floor = new_file_img("./images/063bricksq08.xpm", game);
	return (img_floor);
}

t_img	init_collectible(t_game *game)
{
	t_img	img_collect;

	img_collect = new_file_img("./images/joker2.xpm", game);
	return (img_collect);
}

t_img	init_enemy(t_game *game)
{
	t_img	img_enemy;

	img_enemy = new_file_img("./images/burning_loop_5.xpm", game);
	game->sp_enemy.nb_frames = 7;
	game->sp_enemy.w = 30;
	game->sp_enemy.h = 40;
	return (img_enemy);
}

t_img	init_exit(t_game *game)
{
	t_img	img_exit;

	img_exit = new_file_img("./images/063bricks_exit.xpm", game);
	return (img_exit);
}
