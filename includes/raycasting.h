/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:26:39 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/04 12:35:33 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"

# define TILE_SIZE 30
# define PLAYER_DRAW_SIZE 35
# define WIDTH 1000
# define HEIGHT 500
# define MOVE_SPEED 0.15

void	draw_minimap(mlx_image_t *img, t_cubed *cubed, t_player *player);
void	draw_square(mlx_image_t *img, int x, int y, uint32_t color);
void	draw_player(mlx_image_t *img, t_player *player);
void	key_handler(mlx_key_data_t keydata, void *param);
void	init_player(t_player *player, char **map);

#endif
