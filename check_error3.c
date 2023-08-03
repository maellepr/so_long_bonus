/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:35:26 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/03 14:56:07 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_p(char **map)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	if (p == 0 || p > 1)
	{
		write (2, "Error\nThere is none or several P on the map\n", 44);
		ft_free_map(map);
		exit (0);
	}
}

void	check_e(char **map)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	e = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (e == 0 || e > 1)
	{
		write (2, "Error\nThere is none or several E on the map\n", 44);
		ft_free_map(map);
		exit (0);
	}
}

void	check_c(char **map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (c == 0)
	{
		write (2, "Error\nThere is no C on the map\n", 31);
		ft_free_map(map);
		exit (0);
	}
}

void	quit_border(char **map)
{
	write (2, "Error\nInvalid map, please redo the frame\n", 41);
	ft_free_map(map);
	exit (0);
}

void	check_border(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count_line(map))
	{
		while (j < count_colomn(map))
		{
			if (map[i][0] != '1')
				quit_border(map);
			if (map[i][count_colomn(map) - 1] != '1' )
				quit_border(map);
			if (map[0][j] != '1')
				quit_border(map);
			if (map[count_line(map) - 1][j] != '1')
				quit_border(map);
			j++;
		}
		i++;
	}
}
