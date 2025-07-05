/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onevil_x <onevil_x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:41:46 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/05 20:23:41 by onevil_x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

void	init_game(t_game *game, t_cubed *cubed, t_player *player, mlx_image_t *img, mlx_t *mlx)
{
	game->cubed = cubed;
	game->player = player;
	game->img = img;
	game->mlx = mlx;
}

void	init_ray_vars(t_player *p, int x, double *camera_x,
		double *ray_dir_x, double *ray_dir_y)
{
	*camera_x = 2 * x / (double)WIDTH - 1;
	*ray_dir_x = p->dir_x + p->plane_x * (*camera_x);
	*ray_dir_y = p->dir_y + p->plane_y * (*camera_x);
}

void	rotate_player(t_player *p, double angle)
{
	double	old_dir_x = p->dir_x;
	double	old_plane_x = p->plane_x;

	p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dir_x * sin(angle) + p->dir_y * cos(angle);

	p->plane_x = p->plane_x * cos(angle) - p->plane_y * sin(angle);
	p->plane_y = old_plane_x * sin(angle) + p->plane_y * cos(angle);
	printf("%f\n", angle);
}

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
				if (map[y][x] == 'N')
				{
					player->dir_x = 0;
					player->dir_y = -1;
					player->plane_x = 0.66;
					player->plane_y = 0;
				}
				else if (map[y][x] == 'S')
				{
					player->dir_x = 0;
					player->dir_y = 1;
					player->plane_x = -0.66;
					player->plane_y = 0;
				}
				else if (map[y][x] == 'E')
				{
					player->dir_x = 1;
					player->dir_y = 0;
					player->plane_x = 0;
					player->plane_y = 0.66;
				}
				else if (map[y][x] == 'W')
				{
					player->dir_x = -1;
					player->dir_y = 0;
					player->plane_x = 0;
					player->plane_y = -0.66;
				}
				return ;
			}
			x++;
		}
		y++;
	}
}

void	draw_square(mlx_image_t *img, int x, int y, uint32_t color)
{
	uint32_t	*pixels;
	int			width;
	int			i;
	int			j;
	int			px;
	int			py;

	width = img->width;
	pixels = (uint32_t *)img->pixels;
	j = 0;
	while (j < TILE_SIZE)
	{
		i = 0;
		while (i < TILE_SIZE)
		{
			px = x * TILE_SIZE + i;
			py = y * TILE_SIZE + j;
			if (px >= 0 && py >= 0 && px < (int)width && py < (int)img->height)
				pixels[py * width + px] = color;
			i++;
		}
		j++;
	}
}

void	draw_player(mlx_image_t *img, t_player *player)
{
	int			half_size;
	uint32_t	*pixels;
	int			width;
	int			height;
	int			draw_x;
	int			draw_y;
	int			px;
	int			py;
	int			y;
	int			x;

	pixels = (uint32_t *)img->pixels;
	width = img->width;
	height = img->height;
	px = (int)(player->pos_x * TILE_SIZE);
	py = (int)(player->pos_y * TILE_SIZE);
	half_size = PLAYER_DRAW_SIZE / 8;
	y = -half_size;
	while (y <= half_size)
	{
		x = -half_size;
		while (x <= half_size)
		{
			draw_x = px + x;
			draw_y = py + y;
			if (draw_x >= 0 && draw_y >= 0 && draw_x < width && draw_y < height)
				pixels[draw_y * width + draw_x] = 0xFF0000FF;
			x++;
		}
		y++;
	}
}
