/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surr_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:48:54 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/01 02:01:24 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int longest_line(char **map)
{
	int	max;
	int	i;

	if (!map || !map[1])
		return 0;
	max = 0;
	i = 0;
	while (map[i])
	{
		if (max < ft_strlen(map[i]))
			max = ft_strlen(map[i]);
		i++;
	}
	return (max);
}

static char **mapping(char **map, int max)
{
	char	**copy;
	int		i;
	int		j;

	i = ft_strlen(map[0]);
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		copy[i] = malloc(max + 1);
		if (!copy[i])
			return (free_splited(copy), NULL);
		j = -1;
		while (map[i][++j])
			copy[i][j] = map[i][j];
		while (j < max)
			copy[i][j++] = ' ';
		copy[i][j] = '\0';
	}
	copy[j] = NULL;
	return (copy);
} 

static int	spawn_p(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	surr_check(char	**map, int i, int j)
{
	char	c;

	c = map[i][j];
	if (c == '0' || spawn_p(c))
	{
		if (!map[i + 1] || !map[i - 1] || !map[i][j + 1] || j == 0)
			return (0);
		if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' ||
			map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
			return (0);
	}
	return (1);
}

int	is_valid_map(char **map)
{
	char	**copy;
	int		i;
	int		j;
	int		w_max;

	w_max = longest_line(map);
	copy = mapping(map, w_max);
	if (!copy)
		return (ft_putstr_fd("map copying fail\n", 2), 2);
	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (!surr_check(copy, i, j))
			{
				free_splited(copy);
				ft_putstr_fd("Map nto unclosed by walls\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_splited(copy);
	return (1);
}
