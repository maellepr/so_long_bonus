/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:50:07 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/03 14:49:11 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *str1, char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}

void	check_extension(char *av1)
{
	int		size;
	char	*ext;

	size = ft_strlen(av1) - 4;
	ext = ".ber";
	if (ft_strcmp(ext, av1 + size) == 1)
	{
		write(2, "Error\nWrong file extension\n", 27);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_map	map;
	t_game	game;

	if (ac < 2)
		write(2, "Error\nNot enough argument\n", 26);
	else if (ac == 2)
	{
		check_extension(av[1]);
		map.content = read_map(av[1]);
		if (!map.content)
		{
			write(2, "Error\nMap couldn't be read\n", 27);
			exit(0);
		}
		map.nb_line = count_line(map.content);
		map.nb_colomn = count_colomn(map.content);
		game.map_ptr = &map;
		check_error_map(map.content, map.nb_line, map.nb_colomn);
		init_map(&game);
	}
	else if (ac > 2)
		write(2, "Error\nToo many arguments\n", 25);
}
