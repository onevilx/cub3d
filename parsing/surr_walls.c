/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surr_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:48:54 by adechaji          #+#    #+#             */
/*   Updated: 2025/06/29 21:59:49 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int	validate_map(char **map)
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
