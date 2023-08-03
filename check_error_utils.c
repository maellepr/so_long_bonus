/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:23:26 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/03 14:41:18 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*str_cpy(char *map)
{
	size_t	i;
	char	*new;

	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(map) + 1));
	if (!new)
		return (NULL);
	while (i < ft_strlen(map))
	{
		new[i] = map[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**make_copy(char **map)
{
	int		i;
	char	**map_cpy;

	map_cpy = malloc(sizeof(char *) * (count_line(map) + 1));
	if (!map_cpy)
		return (NULL);
	i = 0;
	while (i < count_line(map))
	{
		map_cpy[i] = str_cpy(map[i]);
		if (!map_cpy[i])
		{
			ft_free_map(map_cpy);
			exit(0);
		}
		i++;
	}
	map_cpy[i] = 0;
	return (map_cpy);
}

t_point	pos_perso(char **map)
{
	int		i;
	int		j;
	t_point	pos;

	i = 0;
	pos.x = 0;
	pos.y = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				pos.x = i;
				pos.y = j;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}
