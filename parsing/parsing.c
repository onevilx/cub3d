/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:48:02 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/04 12:33:13 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	valid_ext(char *stmap)
{
	char	*tmp;

	if (!stmap)
		return (1);
	tmp = ft_strrchr(stmap, '.');
	if (!tmp)
		return (ft_putstr_fd("Invalid map extention\n", 2), 1);
	if (tmp && ft_strncmp(tmp, ".cub", 5) != 0)
	{
		ft_putstr_fd("Invalid map extention\n", 2);
		return (1);
	}
	return (0);
}

static void	set_some(t_cubed *cubed)
{
	cubed->ceiling_rgb = -1;
	cubed->floor_rgb = -1;
}

int	parsing(t_cubed	*cubed)
{
	if (valid_ext(cubed->map_path) != 0)
		return (1);
	cubed->map_fd = open(cubed->map_path, O_RDONLY);
	if (cubed->map_fd < 0)
	{
		perror("Error opening map");
		return (1);
	}
	set_some(cubed);
	if (r_paths(cubed) == 1)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (r_map(cubed) == 1)
		return (1);
	return (printf("success\n"), 0);
}
