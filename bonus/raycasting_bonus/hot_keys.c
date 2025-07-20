/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hot_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:05:00 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/20 15:34:14 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/raycasting.h"

static int	is_valid_walkable(char **map, double x, double y)
{
	int	mx;
	int	my;
	int	map_height;

	mx = (int)x;
	my = (int)y;
	if (my < 0 || mx < 0)
		return (0);
	map_height = 0;
	while (map[map_height])
		map_height++;
	if (my >= map_height)
		return (0);
	if (mx >= (int)ft_strlen(map[my]))
		return (0);
	return (map[my][mx] != '1');
}

static void	handle_move_ws(t_player *p, t_cubed *cubed, mlx_t *mlx)
{
	double	nx;
	double	ny;

	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		nx = p->pos_x + p->dir_x * MOVE_SPEED;
		ny = p->pos_y + p->dir_y * MOVE_SPEED;
		if (is_valid_walkable(cubed->map, nx, p->pos_y))
			p->pos_x = nx;
		if (is_valid_walkable(cubed->map, p->pos_x, ny))
			p->pos_y = ny;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		nx = p->pos_x - p->dir_x * MOVE_SPEED;
		ny = p->pos_y - p->dir_y * MOVE_SPEED;
		if (is_valid_walkable(cubed->map, nx, p->pos_y))
			p->pos_x = nx;
		if (is_valid_walkable(cubed->map, p->pos_x, ny))
			p->pos_y = ny;
	}
}

static void	handle_move_ad(t_player *p, t_cubed *cubed, mlx_t *mlx)
{
	double	nx;
	double	ny;

	if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		nx = p->pos_x - p->plane_x * MOVE_SPEED;
		ny = p->pos_y - p->plane_y * MOVE_SPEED;
		if (is_valid_walkable(cubed->map, nx, p->pos_y))
			p->pos_x = nx;
		if (is_valid_walkable(cubed->map, p->pos_x, ny))
			p->pos_y = ny;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		nx = p->pos_x + p->plane_x * MOVE_SPEED;
		ny = p->pos_y + p->plane_y * MOVE_SPEED;
		if (is_valid_walkable(cubed->map, nx, p->pos_y))
			p->pos_x = nx;
		if (is_valid_walkable(cubed->map, p->pos_x, ny))
			p->pos_y = ny;
	}
}

static void	handle_rotation_and_exit(t_player *p, mlx_t *mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		rotate_player(p, -ROT_SPEED);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		rotate_player(p, ROT_SPEED);
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	game_loop(void *param)
{
	t_game	*game;

	if (MOVE_SPEED > 1.0)
	{
		ft_putstr_fd("Error: MOVE_SPEED exceeds maximum allowed value of 1.0\n",
			2);
		exit(EXIT_FAILURE);
	}
	game = (t_game *)param;
	handle_move_ws(game->player, game->cubed, game->mlx);
	handle_move_ad(game->player, game->cubed, game->mlx);
	handle_rotation_and_exit(game->player, game->mlx);
	mouse_look(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_R) && !game->cubed->sword_animating)
	{
		game->cubed->sword_animating = 1;
		game->cubed->sword_frame = 0;
	}
	animate_sword(game);
	ft_memset(game->img->pixels, 0, WIDTH * HEIGHT * sizeof(uint32_t));
	render_3d_view(game->img, game->player, game->cubed);
	ft_memset(game->minimap->pixels, 0,
		game->minimap->width * game->minimap->height * sizeof(uint32_t));
	draw_minimap(game->minimap, game->cubed, game->player);
	game->cubed->op_door = is_player_near_door(game->cubed, game->player);
}
