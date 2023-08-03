/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:12:46 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/03 14:07:59 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprite(t_game *game, t_sprite *sprite, t_img *img, int t)
{
	t_list		*temp;

	sprite->frame = malloc(sizeof(t_list));
	if (!sprite->frame)
	{
		write (2, "Error\nFailed to create a sprite\n", 32);
		sprite->frame = NULL;
		ft_exit(game);
	}
	sprite->update_time = t;
	sprite->time = 0;
	sprite->cur_nb = 0;
	sprite->frame->content = slice_sprite(game, img, sprite, (t_point){0, 0});
	sprite->frame->next = NULL;
	temp = sprite->frame;
	create_frames(game, img, temp, sprite);
}

t_img	*slice_sprite(t_game *game, t_img *img, t_sprite *sprite, t_point coord)
{
	t_img	*frame;

	frame = ft_calloc(sizeof(t_img), 1);
	if (!frame)
	{
		free(sprite->frame);
		sprite->frame = NULL;
		write(2, "Error\nFailed to create a frame\n", 31);
		ft_exit(game);
	}
	new_img_ptr(frame, sprite->w, sprite->h, game);
	if (!frame->img_ptr)
	{
		free(frame);
		free(sprite->frame);
		sprite->frame = NULL;
		ft_exit(game);
	}
	slice_sprite2(frame, img, coord, sprite);
	return (frame);
}

void	slice_sprite2(t_img *frame, t_img *img, t_point coord, t_sprite *sprite)
{
	int	i;
	int	j;

	i = 0;
	while (i < sprite->w)
	{
		j = 0;
		while (j < sprite->h)
		{
			put_pixel_img_sprite(frame, i, j, \
			get_pixel_img(*img, coord.x + i, coord.y + j));
			j++;
		}
		i++;
	}
}

void	create_frames(t_game *game, t_img *img, t_list *temp, t_sprite *sprite)
{
	int		i;
	t_point	coord;

	i = 0;
	coord.x = 0;
	coord.y = sprite->h;
	while (i < (sprite->nb_frames))
	{
		temp->next = ft_lstnew(slice_sprite(game, img, sprite, \
		(t_point){coord.x, coord.y}));
		if (!temp->next)
			ft_exit(game);
		temp = temp->next;
		coord.y += sprite->h;
		i++;
	}
}

void	update_sprite(t_game *game, t_sprite *sprite, t_list *frame, \
t_point coord)
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
		put_img_to_img(game->image_base, img, coord.x * 40, coord.y * 40 - 12);
	}
	else
	{
		img = *(t_img *)ft_lstgetlast(temp, sprite->cur_nb)->content;
		put_img_to_img(game->image_base, img, coord.x * 40, coord.y * 40 - 12);
	}
}
