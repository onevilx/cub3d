/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:44:35 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/07 16:44:40 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	**grow_map_array(char **old, int new_size)
{
	char	**new;
	int		i;

	new = malloc(sizeof(char *) * (new_size + 1));
	if (!new)
		return (NULL);
	i = 0;
	if (old)
	{
		while (i < new_size && old[i])
		{
			new[i] = old[i];
			i++;
		}
	}
	while (i < new_size + 1)
		new[i++] = NULL;
	if (old)
		free(old);
	return (new);
}

static int	is_map_line(char *line)
{
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	return (*line == '1');
}

static int	validate_and_store_map(t_cubed *cubed, char **map)
{
	if (parse_it(map) == 0)
	{
		free_splited(map);
		return (1);
	}
	cubed->map = map;
	return (0);
}

static char	**r_map__(t_cubed *cubed, char *trimmed)
{
	char	**map;
	char	*line;
	int		count;

	map = NULL;
	count = 0;
	while (1)
	{
		map = grow_map_array(map, count + 1);
		if (!map)
			return (free(trimmed), NULL);
		map[count++] = trimmed;
		map[count] = NULL;
		line = get_next_line(cubed->map_fd);
		if (!line)
			break ;
		trimmed = ft_strtrim(line, "\n\t");
		free(line);
		if (!trimmed || !is_map_line(trimmed))
			return (free(trimmed), free_splited(map), NULL);
	}
	return (map);
}

int	r_map(t_cubed *cubed)
{
	char	**map;
	char	*line;
	char	*trimmed;

	map = NULL;
	line = get_next_line(cubed->map_fd);
	while (line != NULL && is_emptyl(line))
	{
		free(line);
		line = get_next_line(cubed->map_fd);
	}
	if (line == NULL)
		return (ft_putstr_fd("Error: No map found\n", 2), 1);
	trimmed = ft_strtrim(line, "\n\t");
	free(line);
	if (!trimmed || !is_map_line(trimmed))
		return (ft_putstr_fd("Error\n", 2), free(trimmed), 1);
	map = r_map__(cubed, trimmed);
	if (!map)
		return (ft_putstr_fd("Map creation failed\n", 2), 1);
	return (validate_and_store_map(cubed, map));
}
