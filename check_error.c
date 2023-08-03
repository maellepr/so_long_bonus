/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:36:53 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/03 14:51:53 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_line(char **map)
{
	int	i;
	int	j;
	int	nb_char;

	i = 0;
	j = 0;
	nb_char = 0;
	while (map[i][j++])
		nb_char++;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		i++;
		if ((j != nb_char && map[i]) || ((j + 1) != nb_char && !map[i]))
		{
			write (2, "Error\nThe map is not a rectangle\n", 33);
			ft_free_map(map);
			exit (0);
		}
	}
}

void	check_size(int nb_line, int nb_colomn, char **map)
{
	if (nb_line < 4 || nb_colomn < 4)
	{
		write (2, "Error\nThe map is too small\n", 27);
		ft_free_map(map);
		exit (0);
	}
}

int	check_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'C' \
			|| map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == '\n' \
			|| map[i][j] == 'Y')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

void	check_error_map(char **map, int nb_line, int nb_colomn)
{
	check_size(nb_line, nb_colomn, map);
	check_line(map);
	if (check_char(map) == 1)
	{
		write(2, \
		"Error\nThe map has caracters other than 1, 0, P, C, E ou Y.\n", 59);
		ft_free_map(map);
		exit(0);
	}
	check_p(map);
	check_e(map);
	check_c(map);
	check_border(map);
	check_access(map);
}
