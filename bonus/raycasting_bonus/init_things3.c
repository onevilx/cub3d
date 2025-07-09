/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_things3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onevil_x <onevil_x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 01:44:26 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/09 12:22:05 by onevil_x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/raycasting.h"

void	init_game_img(t_game *game, mlx_image_t *img, mlx_t *mlx)
{
	game->img = img;
	game->mlx = mlx;
}

void	init_game(t_game *game, t_cubed *cubed, t_player *player)
{
	game->cubed = cubed;
	game->player = player;
}

void	mouse_look(t_game *game)
{
	double	angle;
	int		mouse_x, mouse_y;
	int		delta_x;
	int		center_x = WIDTH / 2;

	mlx_get_mouse_pos(game->mlx, &mouse_x, &mouse_y);
	delta_x = mouse_x - center_x;

	// Optional: Clamp for stability
	if (delta_x > 100)
		delta_x = 100;
	else if (delta_x < -100)
		delta_x = -100;

	if (delta_x != 0)
	{
		angle = delta_x * MOUSE_SENSITIVITY;
		rotate_player(game->player, angle);
		mlx_set_mouse_pos(game->mlx, center_x, HEIGHT / 2);
	}
}

