/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:49:25 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/17 18:38:02 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_emptyl(char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	valid_path(char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

char	*valid_tex_path(char *arg)
{
	char	*path;

	if (valid_path(arg) == 1)
		return (NULL);
	path = ft_strdup(arg);
	if (!path)
		return (NULL);
	return (path);
}

static int	is_texture__(t_cubed *cubed, char *str, char *arg)
{
	if (ft_strcmp(str, "WE") == 0 && !cubed->we_path)
	{
		cubed->we_path = valid_tex_path(arg);
		if (!cubed->we_path)
			return (1);
	}
	else if (ft_strcmp(str, "EA") == 0 && !cubed->ea_path)
	{
		cubed->ea_path = valid_tex_path(arg);
		if (!cubed->ea_path)
			return (1);
	}
	else
		return (1);
	return (0);
}

int	is_texture(t_cubed *cubed, char *str, char *arg)
{
	if (ft_strcmp(str, "NO") == 0 && !cubed->no_path)
	{
		cubed->no_path = valid_tex_path(arg);
		if (!cubed->no_path)
			return (1);
	}
	else if (ft_strcmp(str, "SO") == 0 && !cubed->so_path)
	{
		cubed->so_path = valid_tex_path(arg);
		if (!cubed->so_path)
			return (1);
	}
	else
		return (is_texture__(cubed, str, arg));
	return (0);
}
