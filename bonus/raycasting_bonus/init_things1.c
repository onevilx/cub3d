/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_things1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:41:46 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/10 14:21:08 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/raycasting.h"

void	init_player(t_player *player, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strrchr("NSEW", map[y][x]))
			{
				player->pos_x = x + 0.5;
				player->pos_y = y + 0.5;
				set_player_dir(player, map[y][x]);
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	draw_tile(mlx_image_t *img, int px, int py, uint32_t color)
{
	uint32_t	*pixels;

	if (px >= 0 && py >= 0
		&& px < (int)img->width && py < (int)img->height)
	{
		pixels = (uint32_t *)img->pixels;
		pixels[py * img->width + px] = color;
	}
}

void	draw_square(mlx_image_t *img, int x, int y, uint32_t color)
{
	int	i;
	int	j;
	int	px;
	int	py;

	j = 0;
	while (j < MINIMAP_TILE)
	{
		i = 0;
		while (i < MINIMAP_TILE)
		{
			px = x * MINIMAP_TILE + i;
			py = y * MINIMAP_TILE + j;
			draw_tile(img, px, py, color);
			i++;
		}
		j++;
	}
}
