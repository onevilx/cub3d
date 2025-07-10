/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_things2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 01:28:49 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/10 14:21:39 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/raycasting.h"

void	init_ray_vars(t_player *p, int x, t_ray_vars *vars)
{
	vars->camera_x = 2 * x / (double)WIDTH - 1;
	vars->ray_dir_x = p->dir_x + p->plane_x * vars->camera_x;
	vars->ray_dir_y = p->dir_y + p->plane_y * vars->camera_x;
}

void	rotate_player(t_player *p, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir_x;
	old_plane_x = p->plane_x;
	p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dir_x * sin(angle) + p->dir_y * cos(angle);
	p->plane_x = p->plane_x * cos(angle) - p->plane_y * sin(angle);
	p->plane_y = old_plane_x * sin(angle) + p->plane_y * cos(angle);
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
