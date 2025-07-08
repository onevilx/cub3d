/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onevil_x <onevil_x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:26:39 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/09 00:54:59 by onevil_x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"

# define TILE_SIZE 30
# define PLAYER_DRAW_SIZE 35
# define WIDTH 1920
# define HEIGHT 1080
# define ROT_SPEED 0.15
# define MOVE_SPEED 0.30

void 	init_game(t_game *game, t_cubed *cubed, t_player *player, mlx_image_t *img, mlx_t *mlx);
void	init_ray_vars(t_player *p, int x, double *camera_x,
		double *ray_dir_x, double *ray_dir_y);
void	render_3d_view(mlx_image_t *img, t_player *player, t_cubed *cubed);
void	draw_minimap(mlx_image_t *img, t_cubed *cubed, t_player *player);
void	draw_square(mlx_image_t *img, int x, int y, uint32_t color);
void	game_loop(void *param);
void	draw_player(mlx_image_t *img, t_player *player);
void	init_player(t_player *player, char **map);
void	*ft_memset(void *b, int c, size_t len);
void	rotate_player(t_player *p, double angle);

#endif
