/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.>c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.>42.>fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:50:07 by mapoirie          #+#    #+#             */
/*   Updated: 2023/07/25 11:35:25 by mapoirie         ###   ########.>fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	print_map(char **map)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while(map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			printf("%c ", map[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

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
		write(2, "Erreur\nLe fichier map n'a pas la bonne extension\n", 49);
		exit(0);
	}
}


int	main(int ac, char **av)
{
	if (ac == 1)
		write (2, "Erreur\nLe nom de la map n'est pas renseigne\n", 44);
	else if (ac == 2)
	{
		t_map	map;
		t_game	game;

		check_extension(av[1]);
		map.content = read_map(av[1]);
		map.nb_line = count_line(map.content);
		map.nb_colomn = count_colomn(map.content);
		game.map_ptr = &map;
		check_error_map(map.content, map.nb_line, map.nb_colomn);
		init_map(&game);
	}
	else if (ac > 2)
		write (2, "Erreur\nArguments en plus presents apres le nom du fichier de la map\n", 68);
}
