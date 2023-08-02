/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:50:10 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/02 18:59:48 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(t_game *game)
{
	if (!game || !(game->mlx_ptr) || !(game->win_ptr) || !(game->image_base.img_ptr))
		return (0);
	game->move_nb = ft_itoa(game->move);
	draw_bricks(game);
	draw_floor(game);
	draw_collect(game);
	draw_exit(game);
	draw_perso_enemy(game);
	mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, game->image_base.img_ptr, 0, 0);
	render_rect(game, (t_rect){39, 12, 115, 15, (int)0xffffff});
	render_rect(game, (t_rect){40, 13, 113, 13, (int)0x000000});	
	mlx_string_put(game->mlx_ptr, game->win_ptr, 42, 23, (int)0xffffff, "moves counter");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 130, 23, (int)0xffffff, game->move_nb);
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

void	ft_free_lst(t_game *game, t_list *frame)
{
	t_list	*p;
	t_list	*tmp;

	p = frame; 
	while(p)
	{
		tmp = p->next;
		if ((*(t_img *)p->content).img_ptr)
			mlx_destroy_image(game->mlx_ptr, (*(t_img *)p->content).img_ptr);
		if (p->content)
			free(p->content);
		free(p);
		p = tmp;
	}
	frame = NULL;
}

void	free_img(t_game *game)
{
		if (game && game->bricks.img_ptr)
			mlx_destroy_image(game->mlx_ptr, game->bricks.img_ptr);
		if (game && game->floor.img_ptr)
			mlx_destroy_image(game->mlx_ptr, game->floor.img_ptr);
		if (game && game->c.img_ptr)
			mlx_destroy_image(game->mlx_ptr, game->c.img_ptr);
		if (game && game->perso.img_ptr)
			mlx_destroy_image(game->mlx_ptr, game->perso.img_ptr);
		if (game && game->perso_back.img_ptr)
			mlx_destroy_image(game->mlx_ptr, game->perso_back.img_ptr);
		if (game && game->perso_left.img_ptr)
			mlx_destroy_image(game->mlx_ptr, game->perso_left.img_ptr);
		if (game && game->perso_right.img_ptr)
			mlx_destroy_image(game->mlx_ptr, game->perso_right.img_ptr);
		if (game && game->enemy.img_ptr)
			mlx_destroy_image(game->mlx_ptr, game->enemy.img_ptr);
		if (game && game->exit.img_ptr)
			mlx_destroy_image(game->mlx_ptr, game->exit.img_ptr);
		if (game && game->image_base.img_ptr)
			mlx_destroy_image(game->mlx_ptr, game->image_base.img_ptr);			
}

int	ft_exit(t_game *game)
{	
		ft_free_map(game->map_ptr->content);
		free_img(game);
		if (game->sp_perso.frame)
			ft_free_lst(game, game->sp_perso.frame);
		if (game->sp_perso_back.frame)
			ft_free_lst(game, game->sp_perso_back.frame);
		if (game->sp_perso_left.frame)
			ft_free_lst(game, game->sp_perso_left.frame);
		if (game->sp_perso_right.frame)
			ft_free_lst(game, game->sp_perso_right.frame);
		if (game->sp_enemy.frame)
			ft_free_lst(game, game->sp_enemy.frame);
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		if (game->mlx_ptr)
			mlx_destroy_display(game->mlx_ptr);
		if (game->mlx_ptr)
			free(game->mlx_ptr);
	exit (0);
}

void	init_map(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		ft_free_map(game->map_ptr->content);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, (game->map_ptr->nb_colomn * 40), (game->map_ptr->nb_line * 40), "*~^.^~*");//creer une nouvelle fenetre
	if (!game->win_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		ft_free_map(game->map_ptr->content);
	}
	// continuer check des cas ou le programme doit quitter propre
	game->image_base = new_img((game->map_ptr->nb_colomn * 40), (game->map_ptr->nb_line * 40), game);
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
	init_sprite(game, &game->sp_perso, &game->perso, 80);
	init_sprite(game, &game->sp_perso_back, &game->perso_back, 80);
	init_sprite(game, &game->sp_perso_left, &game->perso_left, 80);
	init_sprite(game, &game->sp_perso_right, &game->perso_right, 80);
	init_sprite(game, &game->sp_enemy, &game->enemy, 80);
	mlx_loop_hook(game->mlx_ptr, &handle_no_event, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_input, game);
	mlx_hook(game->win_ptr, ClientMessage, NoEventMask, &ft_exit, game);
	mlx_loop(game->mlx_ptr);
}
