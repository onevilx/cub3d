/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_rend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 06:40:10 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/13 16:47:30 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d.h"

int	load_sword_frames(t_cubed *cubed)
{
	char	path[64];
	char	*frame_num;
	int		i;

	i = 0;
	while (i < 7)
	{
		ft_strcpy(path, "bonus/textures_bonus/animated_sword/frame_0");
		frame_num = ft_itoa(i + 1);
		if (!frame_num)
			return (ft_putstr_fd("Error: malloc failed\n", 2), 0);
		ft_strcat(path, frame_num);
		ft_strcat(path, ".png");
		free(frame_num);
		cubed->textr.sword_frames[i] = mlx_load_png(path);
		if (!cubed->textr.sword_frames[i])
			return (ft_putstr_fd("Error: failed to load sword frame\n", 2), 0);
		i++;
	}
	return (1);
}

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
	cubed->textr.hd = mlx_load_png(cubed->door_path);
	if (!cubed->textr.hd)
		return (ft_putstr_fd("Error: failed to load door texture\n", 2), 0);
	if (!load_sword_frames(cubed))
		return (0);
	return (1);
}

void	free_textures(t_cubed *cubed)
{
	int	i;

	i = 0;
	if (cubed->textr.no)
		mlx_delete_texture(cubed->textr.no);
	if (cubed->textr.so)
		mlx_delete_texture(cubed->textr.so);
	if (cubed->textr.we)
		mlx_delete_texture(cubed->textr.we);
	if (cubed->textr.ea)
		mlx_delete_texture(cubed->textr.ea);
	if (cubed->textr.hd)
		mlx_delete_texture(cubed->textr.hd);
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
