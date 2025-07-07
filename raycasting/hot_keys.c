/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hot_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onevil_x <onevil_x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:05:00 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/07 16:45:23 by onevil_x         ###   ########.fr       */
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

static void	ifis_w_or_s(mlx_key_data_t keydata, t_game *game)
{
	t_player	*p;
	t_cubed		*cubed;
	double		nx;
	double		ny;

	p = game->player;
	cubed = game->cubed;
	if (keydata.key == MLX_KEY_W)
	{
		nx = p->pos_x + p->dir_x * MOVE_SPEED;
		ny = p->pos_y + p->dir_y * MOVE_SPEED;
		if (is_walkable(cubed->map, nx, p->pos_y))
			p->pos_x = nx;
		if (is_walkable(cubed->map, p->pos_x, ny))
			p->pos_y = ny;
	}
	else if (keydata.key == MLX_KEY_S)
	{
		nx = p->pos_x - p->dir_x * MOVE_SPEED;
		ny = p->pos_y - p->dir_y * MOVE_SPEED;
		if (is_walkable(cubed->map, nx, p->pos_y))
			p->pos_x = nx;
		if (is_walkable(cubed->map, p->pos_x, ny))
			p->pos_y = ny;
	}
}

static void	ifis_a_or_d(mlx_key_data_t keydata, t_game *game)
{
	t_player	*p;
	t_cubed		*cubed;
	double		nx;
	double		ny;

	p = game->player;
	cubed = game->cubed;
	if (keydata.key == MLX_KEY_A)
	{
		nx = p->pos_x - p->plane_x * MOVE_SPEED;
		ny = p->pos_y - p->plane_y * MOVE_SPEED;
		if (is_walkable(cubed->map, nx, p->pos_y))
			p->pos_x = nx;
		if (is_walkable(cubed->map, p->pos_x, ny))
			p->pos_y = ny;
	}
	else if (keydata.key == MLX_KEY_D)
	{
		nx = p->pos_x + p->plane_x * MOVE_SPEED;
		ny = p->pos_y + p->plane_y * MOVE_SPEED;
		if (is_walkable(cubed->map, nx, p->pos_y))
			p->pos_x = nx;
		if (is_walkable(cubed->map, p->pos_x, ny))
			p->pos_y = ny;
	}
}

void	player_move(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.action != MLX_PRESS && keydata.action != MLX_REPEAT)
		return ;
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
		ifis_w_or_s(keydata, game);
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		ifis_a_or_d(keydata, game);
	else if (keydata.key == MLX_KEY_LEFT)
		rotate_player(game->player, -ROT_SPEED);
	else if (keydata.key == MLX_KEY_RIGHT)
		rotate_player(game->player, ROT_SPEED);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
}

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	player_move(keydata, game);
	ft_memset(game->img->pixels, 0, WIDTH * HEIGHT * sizeof(uint32_t));
	// draw_minimap(game->img, game->cubed, game->player);
	render_3d_view(game->img, game->player, game->cubed);
}

