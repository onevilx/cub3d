/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surr_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 07:02:22 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/13 17:32:52 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d.h"

static int	inside_bounds(char **map, int i, int j)
{
	if (i < 0 || j < 0)
		return (0);
	if (!map[i])
		return (0);
	if (j >= ft_strlen(map[i]))
		return (0);
	return (1);
}

static int	touches_void(char **map, int i, int j)
{
	static int	di[4] = {-1, 1, 0, 0};
	static int	dj[4] = {0, 0, -1, 1};
	int			k;
	int			ni;
	int			nj;

	k = 0;
	while (k < 4)
	{
		ni = i + di[k];
		nj = j + dj[k];
		if (!inside_bounds(map, ni, nj))
			return (1);
		if (map[ni][nj] == ' ')
			return (1);
		k++;
	}
	return (0);
}

static int	norm_map(char **map, int i, int j)
{
	if (is_walkable(map[i][j]))
	{
		if (touches_void(map, i, j))
		{
			write(2, "Error: map not surrounded by walls\n", 35);
			return (1);
		}
	}
	return (0);
}

static int	check_door(char **map, int i, int j)
{
	int	horz;
	int	vert;

	if (!inside_bounds(map, i, j - 1) || !inside_bounds(map, i, j + 1)
		|| !inside_bounds(map, i - 1, j) || !inside_bounds(map, i + 1, j))
		return (1);
	horz = (map[i][j - 1] == '1' && map[i][j + 1] == '1');
	vert = (map[i - 1][j] == '1' && map[i + 1][j] == '1');
	if (!(horz || vert))
	{
		ft_putstr_fd("Error: door must be between two walls\n", 2);
		return (1);
	}
	return (0);
}

int	is_valid_map(char **map)
{
	int	i;
	int	j;

	if (!map || !map[0])
		return (ft_putstr_fd("Error: map is empty\n", 2), 0);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (norm_map(map, i, j) == 1)
				return (0);
			if (map[i][j] == 'H')
			{
				if (check_door(map, i, j) == 1)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
