/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:44:35 by adechaji          #+#    #+#             */
/*   Updated: 2025/06/29 22:11:40 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char **fill_map2d(char **old, int new_size)
{
	char	**new_arr;
	int		i;

	new_arr = malloc(sizeof(char *) * (new_size + 1));
	if (!new_arr)
		return (NULL);
	i = 0;
	while (old && old[i] && i < new_size)
	{
		new_arr[i] = old[i];
		i++;
	}
	new_arr[i] = NULL;
	free(old);
	return (new_arr);
}

static int	is_map_line(char *line)
{
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	return (*line == '1');
}


int	r_map(t_cubed	*cubed)
{
	char	**map;
	char	*line;
	char	*trim;
	int		cc;

	map = NULL;
	cc = 0;
	while ((line = get_next_line(cubed->map_fd)))
	{
		if (is_emptyl(line))
		{
			free(line);
			continue ;
		}
		trim = ft_strtrim(line, " \n\t");
		free(line);
		if (!trim)
			return (free_splited(map), 1);
		if (!is_map_line(trim))
		{
			return (free(trim), 1);
		}
		else
			break ;
		free(trim);
	}
	if (!trim)
		return (ft_putstr_fd("No map found ", 2), 1);
	while (trim)
	{
		map = fill_map2d(map, cc + 1);
		if (!map)
			return (free(trim), free_splited(map), 1);
		map[cc++] = trim;
		line = get_next_line(cubed->map_fd);
		if (!line)
			break ;
		trim = ft_strtrim(line, " \n\t");
		free(line);
		if (!trim)
			return (free_splited(map), 1);
	}
	map = fill_map2d(map, cc + 1);
	map[cc] = NULL;
	int j = 0;
	while(map[j])
		printf("{%s}\n", map[j++]);
	if (parse_it(map) == 0) // implement from scratch
		return (free_splited(map), 1);
	cubed->map = map;
	return (0);
}
