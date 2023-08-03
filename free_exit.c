/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:20:10 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/03 13:35:40 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_free_lst(t_game *game, t_list *frame)
{
	t_list	*p;
	t_list	*tmp;

	p = frame;
	while (p)
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
	if (game->image_base.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->image_base.img_ptr);
	if (game->bricks.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->bricks.img_ptr);
	if (game->floor.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->floor.img_ptr);
	if (game->c.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->c.img_ptr);
	if (game->perso.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->perso.img_ptr);
	if (game->perso_back.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->perso_back.img_ptr);
	if (game->perso_left.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->perso_left.img_ptr);
	if (game->perso_right.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->perso_right.img_ptr);
	if (game->enemy.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->enemy.img_ptr);
	if (game->exit.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->exit.img_ptr);
}

int	ft_exit(t_game *game)
{
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
	if (game->map_ptr->content)
		ft_free_map(game->map_ptr->content);
	exit (0);
}
