/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:32:58 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/16 12:29:55 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/raycasting.h"

void	draw_player_on_minimap(mlx_image_t *img, t_player *p,
	int start_x, int start_y)
{
	int	tile_x;
	int	tile_y;

	tile_x = (int)(p->pos_x - start_x);
	tile_y = (int)(p->pos_y - start_y);
	if (tile_x >= 0 && tile_y >= 0
		&& tile_x < (2 * MINIMAP_RADIUS + 1)
		&& tile_y < (2 * MINIMAP_RADIUS + 1))
		draw_square(img, tile_x, tile_y, 0xFF0000FF);
}

void	draw_minimap_loop(mlx_image_t *img, t_cubed *cubed,
	t_player *player, int start_x)
{
	int	x;
	int	y;
	int	start_y;
	int	end_x;
	int	end_y;

	start_y = (int)player->pos_y - MINIMAP_RADIUS;
	end_x = (int)player->pos_x + MINIMAP_RADIUS;
	end_y = (int)player->pos_y + MINIMAP_RADIUS;
	y = start_y - 1;
	while (++y <= end_y)
	{
		x = start_x - 1;
		while (++x <= end_x)
		{
			if (!is_in_map(cubed, y, x))
				continue ;
			if (cubed->map[y][x] == '1')
				draw_square(img, x - start_x, y - start_y, 0xFFFFFFFF);
			else if (cubed->map[y][x] == '0'
				|| ft_strrchr("NSEW", cubed->map[y][x]))
				draw_square(img, x - start_x, y - start_y, 0x333333FF);
		}
	}
}

void	draw_minimap(mlx_image_t *img, t_cubed *cubed, t_player *player)
{
	int	start_x;

	start_x = (int)player->pos_x - MINIMAP_RADIUS;
	draw_minimap_loop(img, cubed, player, start_x);
	draw_player_on_minimap(img, player, start_x,
		(int)player->pos_y - MINIMAP_RADIUS);
}
