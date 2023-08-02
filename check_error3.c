/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:35:26 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/02 15:14:43 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_p(char **map)
{
	int i;
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
		write (2, "Erreur\nLa map contient 0 ou plusieurs personnages\n", 52);
		ft_free_map(map);
		exit (EXIT_FAILURE);
	}
}

void	check_e(char **map)
{
	int i;
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
		write (2, "Erreur\nLa map contient 0 ou plusieurs sorties\n", 48);
		ft_free_map(map);
		exit (EXIT_FAILURE);
	}
}

void	check_c(char **map)
{
	int i;
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
		write (2, "Erreur\nLa map ne contient pas d'item\n", 37);
		ft_free_map(map);
		exit (EXIT_FAILURE);
	}
}

void	quit_border(char **map)
{
	write (2, "Erreur\nLa map n'est pas valide\nRefaire l'encadrement\n", 53);
	ft_free_map(map);
	exit (EXIT_FAILURE);
}

void	check_border(char **map)
{
	int i;
	int j;

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