/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:21:32 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/03 14:59:01 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill_is(char c, char *to_fill)
{
	int	i;

	i = 0;
	while (to_fill[i])
	{
		if (c == to_fill[i])
			return (1);
		i++;
	}
	return (0);
}

void	fill(char **map, t_point cur, t_point size, char *to_fill)
{
	if (cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y || \
	!fill_is(map[cur.x][cur.y], to_fill))
		return ;
	map[cur.x][cur.y] = 'X';
	fill(map, (t_point){cur.x - 1, cur.y}, size, to_fill);
	fill(map, (t_point){cur.x + 1, cur.y}, size, to_fill);
	fill(map, (t_point){cur.x, cur.y - 1}, size, to_fill);
	fill(map, (t_point){cur.x, cur.y + 1}, size, to_fill);
}

void	flood_fill(char **map, char **map_cpy)
{
	char	to_fill[5];
	t_point	begin;
	t_point	size;

	begin = pos_perso(map);
	size.x = count_line(map);
	size.y = count_colomn(map);
	to_fill[0] = '0';
	to_fill[1] = 'C';
	to_fill[2] = 'P';
	to_fill[3] = 'E';
	to_fill[4] = '\0';
	fill(map_cpy, begin, size, to_fill);
}

int	check_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_access(char **map)
{
	char	**map_cpy;

	map_cpy = make_copy(map);
	if (!map_cpy)
	{
		write (2, "Error while checking the map\n", 29);
		ft_free_map(map);
		exit(0);
	}
	flood_fill(map, map_cpy);
	if (check_map(map_cpy) != 0)
	{
		write (2, "Error\nInvalid map\n", 18);
		ft_free_map(map_cpy);
		ft_free_map(map);
		exit (0);
	}
	ft_free_map(map_cpy);
}
