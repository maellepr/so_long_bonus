/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:50:10 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/03 15:30:03 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprite_init_null(t_game *game)
{
	game->sp_perso.frame = NULL;
	game->sp_perso_back.frame = NULL;
	game->sp_perso_left.frame = NULL;
	game->sp_perso_right.frame = NULL;
	game->sp_enemy.frame = NULL;
}

void	img_init_null(t_game *game)
{
	game->image_base.img_ptr = NULL;
	game->bricks.img_ptr = NULL;
	game->floor.img_ptr = NULL;
	game->c.img_ptr = NULL;
	game->perso.img_ptr = NULL;
	game->perso_back.img_ptr = NULL;
	game->perso_left.img_ptr = NULL;
	game->perso_right.img_ptr = NULL;
	game->enemy.img_ptr = NULL;
	game->exit.img_ptr = NULL;
}

void	init_struct_game(t_game *game)
{
	game->image_base = new_img((game->map_ptr->nb_colomn * 40), \
	(game->map_ptr->nb_line * 40), game);
	game->bricks = init_bricks(game);
	game->floor = init_floor(game);
	game->c = init_collectible(game);
	game->perso = init_perso(game);
	game->perso_back = init_perso_back(game);
	game->perso_left = init_perso_left(game);
	game->perso_right = init_perso_right(game);
	game->enemy = init_enemy(game);
	game->exit = init_exit(game);
	game->move = 0;
	game->trig = 0;
	game->init_co = count_collec(game);
	game->co = 0;
	game->move_pos = 2;
}

void	sprite(t_game *game)
{
	init_sprite(game, &game->sp_perso, &game->perso, 80);
	init_sprite(game, &game->sp_perso_back, &game->perso_back, 80);
	init_sprite(game, &game->sp_perso_left, &game->perso_left, 80);
	init_sprite(game, &game->sp_perso_right, &game->perso_right, 80);
	init_sprite(game, &game->sp_enemy, &game->enemy, 80);
}

void	init_map(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		ft_free_map(game->map_ptr->content);
		exit(0);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	(game->map_ptr->nb_colomn * 40), (game->map_ptr->nb_line * 40), "so_long");
	if (!game->win_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		ft_free_map(game->map_ptr->content);
		exit(0);
	}
	img_init_null(game);
	sprite_init_null(game);
	init_struct_game(game);
	sprite(game);
	mlx_loop_hook(game->mlx_ptr, &handle_no_event, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_input, game);
	mlx_hook(game->win_ptr, ClientMessage, NoEventMask, &ft_exit, game);
	mlx_loop(game->mlx_ptr);
}
