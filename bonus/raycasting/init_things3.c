/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_things3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 01:44:26 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/09 01:45:01 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

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
