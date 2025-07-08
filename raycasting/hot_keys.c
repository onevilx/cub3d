/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hot_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onevil_x <onevil_x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:05:00 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/09 00:56:13 by onevil_x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

static int	is_walkable(char **map, double x, double y)
{
	int	mx;
	int	my;

	mx = (int)x;
	my = (int)y;
	return (map[my][mx] != '1');
}

void	game_loop(void *param)
{
	t_game *game = (t_game *)param;
	t_player *p = game->player;
	t_cubed *cubed = game->cubed;
	double nx, ny;

	// Move forward
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		nx = p->pos_x + p->dir_x * MOVE_SPEED;
		ny = p->pos_y + p->dir_y * MOVE_SPEED;
		if (is_walkable(cubed->map, nx, p->pos_y)) p->pos_x = nx;
		if (is_walkable(cubed->map, p->pos_x, ny)) p->pos_y = ny;
	}

	// Move backward
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		nx = p->pos_x - p->dir_x * MOVE_SPEED;
		ny = p->pos_y - p->dir_y * MOVE_SPEED;
		if (is_walkable(cubed->map, nx, p->pos_y)) p->pos_x = nx;
		if (is_walkable(cubed->map, p->pos_x, ny)) p->pos_y = ny;
	}

	// Strafe left
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		nx = p->pos_x - p->plane_x * MOVE_SPEED;
		ny = p->pos_y - p->plane_y * MOVE_SPEED;
		if (is_walkable(cubed->map, nx, p->pos_y)) p->pos_x = nx;
		if (is_walkable(cubed->map, p->pos_x, ny)) p->pos_y = ny;
	}

	// Strafe right
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		nx = p->pos_x + p->plane_x * MOVE_SPEED;
		ny = p->pos_y + p->plane_y * MOVE_SPEED;
		if (is_walkable(cubed->map, nx, p->pos_y)) p->pos_x = nx;
		if (is_walkable(cubed->map, p->pos_x, ny)) p->pos_y = ny;
	}

	// Rotate left
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_player(p, -ROT_SPEED);

	// Rotate right
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_player(p, ROT_SPEED);

	// Exit
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);

	// Redraw frame
	ft_memset(game->img->pixels, 0, WIDTH * HEIGHT * sizeof(uint32_t));
	render_3d_view(game->img, game->player, game->cubed);
}

