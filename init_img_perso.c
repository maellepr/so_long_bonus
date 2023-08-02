/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_perso.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:06:57 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/02 14:26:41 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	init_perso(t_game *game)
{
	t_img	img_perso;

	img_perso = new_file_img("./images/idle_front.xpm", game);
	game->sp_perso.nb_frames = 1;
	game->sp_perso.w = 40;
	game->sp_perso.h = 40;
	return (img_perso);
}

t_img	init_perso_back(t_game *game)
{
	t_img	img_perso;

	img_perso = new_file_img("./images/idle_back.xpm", game);
	game->sp_perso_back.nb_frames = 1;
	game->sp_perso_back.w = 40;
	game->sp_perso_back.h = 40;
	return (img_perso);
}

t_img	init_perso_left(t_game *game)
{
	t_img	img_perso;

	img_perso = new_file_img("./images/idle_left.xpm", game);
	game->sp_perso_left.nb_frames = 1;
	game->sp_perso_left.w = 40;
	game->sp_perso_left.h = 40;
	return (img_perso);
}

t_img	init_perso_right(t_game *game)
{
	t_img	img_perso;

	img_perso = new_file_img("./images/idle_right.xpm", game);
	game->sp_perso_right.nb_frames = 1;
	game->sp_perso_right.w = 40;
	game->sp_perso_right.h = 40;
	return (img_perso);
}