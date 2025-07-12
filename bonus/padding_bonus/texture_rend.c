/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_rend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 06:40:10 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/11 17:59:26 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d.h"

int	load_textures(t_cubed *cubed)
{
	char	path[100];
	int		i;

	i = 0;
	while (i < 7)
	{
		snprintf(path, sizeof(path), "bonus/textures_bonus/animated_sword/frame_0%d.png", i + 1);
		cubed->textr.sword_frames[i] = mlx_load_png(path);
		if (!cubed->textr.sword_frames[i])
			return (ft_putstr_fd("Error: failed to load sword frame\n", 2), 0);
		i++;
	}
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
	int i;

	i = 0;
	if (cubed->textr.no)
		mlx_delete_texture(cubed->textr.no);
	if (cubed->textr.so)
		mlx_delete_texture(cubed->textr.so);
	if (cubed->textr.we)
		mlx_delete_texture(cubed->textr.we);
	if (cubed->textr.ea)
		mlx_delete_texture(cubed->textr.ea);
	while (i < 7)
	{
		if (cubed->textr.sword_frames[i])
			mlx_delete_texture(cubed->textr.sword_frames[i]);
		i++;
	}
}

uint32_t	tex_clr_finder(mlx_texture_t *tex, int x, int y)
{
	uint8_t	*pix;

	pix = &tex->pixels[(y * tex->width + x) * 4];
	return ((pix[0] << 24) | (pix[1] << 16) | (pix[2] << 8) | pix[3]);
}
