/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_things5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 02:21:54 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/15 17:18:22 by adechaji         ###   ########.fr       */
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

void	init_sword_image(t_game *game, mlx_t *mlx)
{
	int				sword_x;
	int				sword_y;
	mlx_image_t		*sword_img;

	sword_img = resize_texture_to_image(mlx,
			game->cubed->textr.sword_frames[0], 700, 700);
	if (!sword_img)
	{
		ft_putstr_fd("Error: Failed to convert sword texture to image\n", 2);
		exit(EXIT_FAILURE);
	}
	game->cubed->sword_img = sword_img;
	sword_x = (WIDTH - sword_img->width) / 2;
	sword_y = HEIGHT - sword_img->height;
	if (mlx_image_to_window(mlx, sword_img, sword_x, sword_y) < 0)
	{
		ft_putstr_fd("Error: Failed to put sword image to window\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	mouse_look(t_game *game)
{
	double	angle;
	int		mouse_x;
	int		mouse_y;
	int		delta_x;

	mlx_get_mouse_pos(game->mlx, &mouse_x, &mouse_y);
	delta_x = mouse_x - (WIDTH / 2);
	if (delta_x > 100)
		delta_x = 100;
	else if (delta_x < -100)
		delta_x = -100;
	if (delta_x != 0)
	{
		angle = delta_x * MOUSE_SENSITIVITY;
		rotate_player(game->player, angle);
		mlx_set_mouse_pos(game->mlx, (WIDTH / 2), HEIGHT / 2);
	}
}

int	is_in_map(t_cubed *cubed, int y, int x)
{
	if (y < 0 || x < 0)
		return (0);
	if (!cubed->map[y])
		return (0);
	if (x >= (int)ft_strlen(cubed->map[y]))
		return (0);
	return (1);
}
