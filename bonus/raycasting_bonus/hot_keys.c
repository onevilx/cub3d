/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hot_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:05:00 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/11 18:26:52 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/raycasting.h"

static int	is_walkable(char **map, double x, double y)
{
	int	mx;
	int	my;

	mx = (int)x;
	my = (int)y;
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
		if (is_walkable(cubed->map, nx, p->pos_y))
			p->pos_x = nx;
		if (is_walkable(cubed->map, p->pos_x, ny))
			p->pos_y = ny;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		nx = p->pos_x - p->dir_x * MOVE_SPEED;
		ny = p->pos_y - p->dir_y * MOVE_SPEED;
		if (is_walkable(cubed->map, nx, p->pos_y))
			p->pos_x = nx;
		if (is_walkable(cubed->map, p->pos_x, ny))
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
		if (is_walkable(cubed->map, nx, p->pos_y))
			p->pos_x = nx;
		if (is_walkable(cubed->map, p->pos_x, ny))
			p->pos_y = ny;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		nx = p->pos_x + p->plane_x * MOVE_SPEED;
		ny = p->pos_y + p->plane_y * MOVE_SPEED;
		if (is_walkable(cubed->map, nx, p->pos_y))
			p->pos_x = nx;
		if (is_walkable(cubed->map, p->pos_x, ny))
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

void	animate_sword(t_game *game)
{
	static int frame_timer = 0;

	if (!game->cubed->sword_animating)
		return ;
	if (++frame_timer < 1)
		return ;
	frame_timer = 0;
	game->cubed->sword_frame++;
	if (game->cubed->sword_frame >= 7)
	{
		game->cubed->sword_frame = 0;
		game->cubed->sword_animating = 0;
	}
	if (game->cubed->sword_img)
		mlx_delete_image(game->mlx, game->cubed->sword_img);
	game->cubed->sword_img = resize_texture_to_image(game->mlx,
		game->cubed->textr.sword_frames[game->cubed->sword_frame], 700, 700);
	int sword_x = (WIDTH - game->cubed->sword_img->width) / 2;
	int sword_y = HEIGHT - game->cubed->sword_img->height;
	mlx_image_to_window(game->mlx, game->cubed->sword_img, sword_x, sword_y);
	game->cubed->sword_img->instances[0].z = 10;
}

void	game_loop(void *param)
{
	t_game	*game;

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
}
