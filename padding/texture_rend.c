/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_rend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 06:40:10 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/07 16:38:44 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	load_textures(t_cubed *cubed)
{
	cubed->textr.no = mlx_load_png(cubed->no_path);
	if (!cubed->textr.no)
		return (ft_putstr_fd("Error: failed to load north texture\n", 2), 0);

	cubed->textr.so = mlx_load_png(cubed->so_path);
	if (!cubed->textr.so)
		return (ft_putstr_fd("Error: failed to load south texture\n", 2), 0);

	cubed->textr.we = mlx_load_png(cubed->we_path);
	if (!cubed->textr.we)
		return (ft_putstr_fd("Error: failed to load west texture\n", 2), 0);

	cubed->textr.ea = mlx_load_png(cubed->ea_path);
	if (!cubed->textr.ea)
		return (ft_putstr_fd("Error: failed to load east texture\n", 2), 0);

	return (1);
}

void	free_textures(t_cubed *cubed)
{
	if (cubed->textr.no)
		mlx_delete_texture(cubed->textr.no);
	if (cubed->textr.so)
		mlx_delete_texture(cubed->textr.so);
	if (cubed->textr.we)
		mlx_delete_texture(cubed->textr.we);
	if (cubed->textr.ea)
		mlx_delete_texture(cubed->textr.ea);
}

