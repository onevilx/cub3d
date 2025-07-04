/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:49:25 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/04 12:31:01 by adechaji         ###   ########.fr       */
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

int	valid_color(char *str, int *clr)
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
