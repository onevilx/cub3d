/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_map_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 20:48:31 by adechaji          #+#    #+#             */
/*   Updated: 2025/06/29 22:11:11 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == ' ');
}

static int	count_spawn_points(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	inside_bounds(char **map, int i, int j)
{
	return (i >= 0 && map[i] && j >= 0 && j < (int)ft_strlen(map[i]));
}

static int	touches_void(char **map, int i, int j)
{
	int	di[] = {-1, 1, 0, 0};
	int	dj[] = {0, 0, -1, 1};
	int	k;

	k = 0;
	while (k < 4)
	{
		int ni = i + di[k];
		int nj = j + dj[k];
		if (!inside_bounds(map, ni, nj) || map[ni][nj] == ' ')
			return (1);
		k++;
	}
	return (0);
}

int	isclosed(char **map)
{
	int	i;
	int	j;
	int	spawn;

	if (!map || !map[0])
		return (write(2, "Error: map is empty\n", 20), 0);
	spawn = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_valid_char(map[i][j]))
				return (write(2, "Error: invalid char in map\n", 27), 0);
			if (count_spawn_points(map[i][j]))
				spawn++;
			if (map[i][j] == '0' || count_spawn_points(map[i][j]))
			{
				if (touches_void(map, i, j))
					return (write(2, "Error: map not surrounded by walls\n", 35), 0);
			}
			j++;
		}
		i++;
	}
	if (spawn != 1)
		return (write(2, "Error: map must have 1 spawn point\n", 35), 0);
	return (1);
}


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
					map[i][j] != ' ')
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
	if (!is_valid_map(map))
		return (0);
	return (1);
}
