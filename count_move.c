/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:31:41 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/03 12:44:53 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	count_move(t_game *game)
{
	game->move += 1;
	ft_putnbr(game->move);
	write (1, "\n", 1);
}

int	count_collec(t_game *game)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (game->map_ptr->content[i])
	{
		j = 0;
		while (game->map_ptr->content[i][j])
		{
			if (game->map_ptr->content[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}
