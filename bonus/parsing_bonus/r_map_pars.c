/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_map_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 20:48:31 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/10 17:19:57 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d.h"

int	hasanotherchar(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N' &&
					map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W' &&
					map[i][j] != ' ' && map[i][j] != 'H')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	parsmap(char **map)
{
	if (!map || !map[0])
	{
		write(2, "Error map is empty || NULL\n", 27);
		return (0);
	}
	if (hasanotherchar(map) == 0)
	{
		write(2, "Error map has an invalid char\n", 30);
		return (0);
	}
	return (1);
}

int	countit(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	mapelements(char **map)
{
	int	n_cc;
	int	s_cc;
	int	e_cc;
	int	w_cc;

	n_cc = countit(map, 'N');
	s_cc = countit(map, 'S');
	e_cc = countit(map, 'E');
	w_cc = countit(map, 'W');
	if ((n_cc + s_cc + e_cc + w_cc) != 1)
	{
		write(2, "Error gimme 1 SPAWN!\n", 21);
		return (0);
	}
	return (1);
}

int	parse_it(char	**map)
{
	if (parsmap(map) == 0)
		return (0);
	if (mapelements(map) == 0)
		return (0);
	if (is_valid_map(map) == 0)
		return (0);
	return (1);
}
