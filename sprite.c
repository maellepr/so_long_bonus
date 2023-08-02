/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:12:46 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/02 14:11:42 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprite(t_game *game, t_sprite *sprite, t_img *img, int t)
{
	t_list		*temp;

	sprite->frame = malloc(sizeof(t_list));
	if (!sprite->frame)
	{
		sprite->frame = NULL;
		//ajouter protect
	}
	sprite->update_time = t;
	sprite->time = 0;
	sprite->cur_nb = 0;
	sprite->frame->content = slice_sprite(game, img, sprite, (t_point){0, 0});
	sprite->frame->next = NULL;
	temp = sprite->frame;
	create_frames(game, img, temp, sprite);
}

t_img	*slice_sprite(t_game *game, t_img *img, t_sprite *sprite, t_point coord)//slice sprite1-2
{
	t_img	*frame;
	int		i;
	int		j;

	frame = ft_calloc(sizeof(t_img), 1);
	if (!frame)
	{
		free(sprite->frame);
		sprite->frame = NULL;
		write(2, "Erreur\nUne frame n'a pas pu etre creee\n", 39);
		ft_exit(game);// ajouter plus de protections 
	}
	i = 0;
	new_img_ptr(frame, sprite->w, sprite->h, game);// va chercher l'image totale
	while (i < sprite->w)// affiche une partie de l'image selon les coordonnees envoyees 
	{
		j = 0;
		while (j < sprite->h)
		{
			put_pixel_img_sprite(frame, i, j, get_pixel_img(*img, coord.x + i, coord.y + j));//coord.x + i, coord.y + j
			j++;
		}
		i++;
	}
	return (frame);
}

void	create_frames(t_game *game, t_img *img, t_list *temp, t_sprite *sprite)
{
	int		i;
	t_point	coord;

	i = 0;
	coord.x = 0;
	coord.y = sprite->h;
	// coord.x = sprite->w;
	// coord.y = 0;
	while (i < (sprite->nb_frames))
	{
		temp->next = ft_lstnew(slice_sprite(game, img, sprite, (t_point){coord.x, coord.y}));
		if (!temp->next)
			ft_exit(game);
		temp = temp->next;
		// if (coord.x > game->perso.width)
		// {
		// 	coord.x += sprite->w;
		// 	coord.y = 0;
		// }
		coord.y += sprite->h;
		// coord.x += sprite->w;
		i++;
	}
}


void	update_sprite(t_game *game, t_sprite *sprite, t_list *frame, t_point coord)
{
	t_list	*temp;
	t_img	img;

	temp = frame;
	sprite->time++;
	if (sprite->time == sprite->update_time)
	{
		sprite->time = 0;
		sprite->cur_nb++;
		sprite->cur_nb %= ft_lstsize(frame);
		img = *(t_img *)ft_lstgetlast(temp, sprite->cur_nb)->content;
		put_img_to_img(game->image_base, img, coord.x * 40, coord.y * 40 - 12);// p etre h et w a echanger
	}
	else
	{
		img = *(t_img *)ft_lstgetlast(temp, sprite->cur_nb)->content;
		put_img_to_img(game->image_base, img, coord.x * 40, coord.y * 40 - 12);
	}
}
