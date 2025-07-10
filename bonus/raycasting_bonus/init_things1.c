/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_things1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:41:46 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/10 16:25:00 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/raycasting.h"

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

static void	draw_player_pixel(mlx_image_t *img, int dx, int dy)
{
	uint32_t	*pixels;

	if (dx >= 0 && dy >= 0
		&& dx < (int)img->width && dy < (int)img->height)
	{
		pixels = (uint32_t *)img->pixels;
		pixels[dy * img->width + dx] = 0xFF0000FF;
	}
}

static void	draw_player_body(mlx_image_t *img, int px, int py, int half)
{
	int	x;
	int	y;
	int	dx;
	int	dy;

	y = -half;
	while (y <= half)
	{
		x = -half;
		while (x <= half)
		{
			dx = px + x;
			dy = py + y;
			draw_player_pixel(img, dx, dy);
			x++;
		}
		y++;
	}
}

void	draw_player(mlx_image_t *img, t_player *p)
{
	int	px;
	int	py;
	int	half;

	px = (int)(p->pos_x * MINIMAP_TILE);
	py = (int)(p->pos_y * MINIMAP_TILE);
	half = MINIMAP_TILE / 2;
	draw_player_body(img, px, py, half);
}
