/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:49:13 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/03 14:48:09 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line_fd(char *av1)
{
	int		fd;
	int		nb_line;
	char	*line;

	fd = open(av1, O_RDONLY);
	nb_line = 0;
	line = get_next_line(fd);
	if (!line)
		exit(0);
	while (line != NULL)
	{	
		free(line);
		nb_line++;
		if (nb_line > 2147483647 || nb_line < 0)
		{
			write(2, "Error\nToo many lines\n", 21);
			exit(0);
		}
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
	return (nb_line);
}

char	**read_map(char *av1)
{
	int		fd;
	int		nb_line;
	int		i;
	char	**map;

	nb_line = count_line_fd(av1);
	fd = open(av1, O_RDONLY);
	i = 0;
	map = malloc(sizeof(char *) * (nb_line + 1));
	if (!map)
		return (NULL);
	while (i < nb_line)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
		{
			ft_free_map(map);
			return (NULL);
		}
		i++;
	}
	close (fd);
	map[nb_line] = 0;
	return (map);
}
