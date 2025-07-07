/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onevil_x <onevil_x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:36:39 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/07 16:34:04 by onevil_x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

static void	init_dda_vars(t_player *p, double ray_dir_x, double ray_dir_y,
		t_dda *dda)
{
	dda->map_x = (int)p->pos_x;
	dda->map_y = (int)p->pos_y;
	dda->delta_x = fabs(1 / ray_dir_x);
	dda->delta_y = fabs(1 / ray_dir_y);
	if (ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_x = (p->pos_x - dda->map_x) * dda->delta_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_x = (dda->map_x + 1.0 - p->pos_x) * dda->delta_x;
	}
	if (ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_y = (p->pos_y - dda->map_y) * dda->delta_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_y = (dda->map_y + 1.0 - p->pos_y) * dda->delta_y;
	}
}

static void	perform_dda(char **map, t_dda *dda)
{
	dda->hit = 0;
	while (dda->hit == 0)
	{
		if (dda->side_x < dda->side_y)
		{
			dda->side_x += dda->delta_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_y += dda->delta_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (map[dda->map_y][dda->map_x] == '1')
			dda->hit = 1;
	}
}

static void	draw_wall(mlx_image_t *img, int x, t_dda *dda,
				t_player *p, t_cubed *cubed)
{
	double	dist;
	int		height;
	int		start;
	int		end;
	int		y;

	if (dda->side == 0)
		dist = (dda->map_x - p->pos_x + (1 - dda->step_x) / 2)
			/ dda->ray_dir_x;
	else
		dist = (dda->map_y - p->pos_y + (1 - dda->step_y) / 2)
			/ dda->ray_dir_y;
	height = (int)(HEIGHT / dist);
	start = -height / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = height / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	y = 0;
	while (y < start)
		mlx_put_pixel(img, x, y++, cubed->ceiling_rgb);
	while (y <= end)
		mlx_put_pixel(img, x, y++, 0xFF0000FF);
	while (y < HEIGHT)
		mlx_put_pixel(img, x, y++, cubed->floor_rgb);
}

void	render_3d_view(mlx_image_t *img, t_player *p, t_cubed *cubed)
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	t_dda	dda;

	x = 0;
	while (x < WIDTH)
	{
		init_ray_vars(p, x, &camera_x, &ray_dir_x, &ray_dir_y);
		dda.ray_dir_x = ray_dir_x;
		dda.ray_dir_y = ray_dir_y;
		init_dda_vars(p, ray_dir_x, ray_dir_y, &dda);
		perform_dda(cubed->map, &dda);
		draw_wall(img, x, &dda, p, cubed);
		x++;
	}
}

void	draw_minimap(mlx_image_t *img, t_cubed *cubed, t_player *player)
{
	int	y;
	int	x;

	y = 0;
	while (cubed->map[y])
	{
		x = 0;
		while (cubed->map[y][x])
		{
			if (cubed->map[y][x] == '1')
				draw_square(img, x, y, 0xFFFFFFFF); // Wall
			else if (cubed->map[y][x] == '0' || ft_strrchr("NSEW", cubed->map[y][x]))
				draw_square(img, x, y, 0x333333FF); // Floor
			x++;
		}
		y++;
	}
	draw_player(img, player);
}
