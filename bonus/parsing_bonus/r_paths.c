/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_paths.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:35:15 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/10 16:37:24 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d.h"

int	is_color(t_cubed *cubed, char *str, char *arg)
{
	if (ft_strcmp(str, "F") == 0)
	{
		if (cubed->floor_rgb != -1
			|| valid_color(arg, &cubed->floor_rgb) == 1)
			return (1);
	}
	if (ft_strcmp(str, "C") == 0)
	{
		if (cubed->ceiling_rgb != -1
			|| valid_color(arg, &cubed->ceiling_rgb) == 1)
			return (1);
	}
	return (0);
}

static int	what_is_it(char *str)
{
	if (ft_strcmp(str, "NO") == 0)
		return (1);
	if (ft_strcmp(str, "SO") == 0)
		return (1);
	if (ft_strcmp(str, "WE") == 0)
		return (1);
	if (ft_strcmp(str, "EA") == 0)
		return (1);
	if (ft_strcmp(str, "F") == 0)
		return (2);
	if (ft_strcmp(str, "C") == 0)
		return (2);
	return (0);
}

static int	check_args(char **args)
{
	if (!args || !args[0] || !args[1])
		return (1);
	if (args[2])
	{
		if (is_emptyl(args[2]) == 1)
			return (0);
	}
	else
		return (0);
	return (1);
}

static int	pars_paths(t_cubed *cubed, char *buf)
{
	char	**splited;
	char	*arg;

	splited = ft_old_split(buf, ' ');
	if (check_args(splited) == 1)
		return (free_splited(splited), 1);
	arg = ft_strtrim(splited[1], " \n\t");
	if (!arg)
		return (free_splited(splited), 1);
	if (what_is_it(splited[0]) == 1)
	{
		if (is_texture(cubed, splited[0], arg) == 1)
			return (free(arg), free_splited(splited), 1);
	}
	else if (what_is_it(splited[0]) == 2)
	{
		if (is_color(cubed, splited[0], arg) == 1)
			return (free(arg), free_splited(splited), 1);
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
	while (ctr < 7)
	{
		buf = get_next_line(cubed->map_fd);
		if (!buf)
			break ;
		if (is_emptyl(buf))
		{
			free(buf);
			continue ;
		}
		if (pars_paths(cubed, buf) != 0)
			return (free(buf), 1);
		ctr++;
		free(buf);
	}
	return (0);
}
