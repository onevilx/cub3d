/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_paths.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:35:15 by adechaji          #+#    #+#             */
/*   Updated: 2025/06/29 20:05:10 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	valid_path(char *path)
{
	int		fd;
	
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

static int	valid_color(char *str, int *clr)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_old_split(str, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		return (1);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (1);
	*clr = (r << 16) | (g << 8) | b;
	free_splited(rgb);
	return (0);
}

static int	pars_paths(t_cubed *cubed, char *buf)
{
	char	**splited;
	char	*arg;

	splited = ft_old_split(buf, ' ');
	if (!splited || !splited[0] || !splited[1] || splited[2])
		return (free_splited(splited), 1);
	arg = ft_strtrim(splited[1], " \n\t");
	if (!arg)
		return (free_splited(splited), 1);
	if (ft_strcmp(splited[0], "NO") == 0)
	{
		if (cubed->no_path || valid_path(arg) == 1)
			return (free(arg), free_splited(splited), 1);
		cubed->no_path = ft_strdup(arg);
		if (!cubed->no_path)
			return (free(arg), free_splited(splited), 1);
	}
	else if (ft_strcmp(splited[0], "SO") == 0)
	{
		if (cubed->so_path || valid_path(arg) == 1)
			return (free(arg), free_splited(splited), 1);
		cubed->so_path = ft_strdup(arg);
		if (!cubed->so_path)
			return (free(arg), free_splited(splited), 1);
	}
	else if (ft_strcmp(splited[0], "WE") == 0)
	{
		if (cubed->we_path || valid_path(arg) == 1)
			return (free(arg), free_splited(splited), 1);
		cubed->we_path = ft_strdup(arg);
		if (!cubed->we_path)
			return (free(arg), free_splited(splited), 1);
	}
	else if (ft_strcmp(splited[0], "EA") == 0)
	{
		if (cubed->ea_path || valid_path(arg) == 1)
			return (free(arg), free_splited(splited), 1);
		cubed->ea_path = ft_strdup(arg);
		if (!cubed->ea_path)
			return (free(arg), free_splited(splited), 1);
	}
	else if (ft_strcmp(splited[0], "F") == 0)
	{
		if (cubed->f_set != 0 || valid_color(arg, &cubed->floor_rgb) == 1)
			return (free(arg), free_splited(splited), 1);
		cubed->f_set = 1;
	}
	else if (ft_strcmp(splited[0], "C") == 0)
	{
		if (cubed->c_set != 0 || valid_color(arg, &cubed->ceiling_rgb) == 1)
			return (free(arg), free_splited(splited), 1);
		cubed->c_set = 1;
	}
	else
		return (free(arg), free_splited(splited), 1);
	free(arg);
	free_splited(splited);
	return (0);
}

int	r_paths(t_cubed	*cubed)
{
	char	*buf;
	int		ctr;

	ctr = 0;
	while (ctr < 6) // nigger while
	{
		buf = get_next_line(cubed->map_fd);
		if (!buf)
			break ;
		if (is_emptyl(buf))
		{
			free(buf);
			continue ;
		}
		// printf("%s", buf);
		if (pars_paths(cubed, buf) != 0)
			return (free(buf), 1);
		ctr++;
		free(buf);
	}
	return (0);
}
