/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:29:55 by mapoirie          #+#    #+#             */
/*   Updated: 2023/08/03 15:04:12 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char **map)
{
	int		i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	count_colomn(char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i][j])
		j++;
	return (j - 1);
}

int	count_digit(int nbr)
{
	int	digit;

	digit = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -nbr;
		digit += 1;
	}
	while (nbr > 0)
	{
		digit++;
		nbr /= 10;
	}
	return (digit);
}

char	*ft_itoa(int nbr)
{
	int		digit;
	int		i;
	char	*str;

	i = 0;
	digit = count_digit(nbr);
	str = malloc(sizeof(char) * digit + 1);
	if (!str || nbr < 0 || nbr > 2147483647)
		return (NULL);
	i = digit - 1;
	while (i >= 0)
	{
		str[i] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	}
	str[digit] = '\0';
	return (str);
}
