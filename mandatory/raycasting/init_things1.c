/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_things1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onevil_x <onevil_x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:41:46 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/09 16:59:48 by onevil_x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

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
