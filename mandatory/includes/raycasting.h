/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onevil_x <onevil_x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:26:39 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/09 17:21:01 by onevil_x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"

# define WIDTH 1800
# define HEIGHT 920
# define ROT_SPEED 0.05
# define MOVE_SPEED 0.15

void	init_game(t_game *game, t_cubed *cubed, t_player *player);
void	init_game_img(t_game *game, mlx_image_t *img, mlx_t *mlx);
void	init_ray_vars(t_player *p, int x, t_ray_vars *vars);
void	perform_dda(char **map, t_dda *dda);
void	init_dda_vars(t_player *p, double ray_dir_x,
			double ray_dir_y, t_dda *dda);
void	render_3d_view(mlx_image_t *img, t_player *player, t_cubed *cubed);
void	set_player_dir(t_player *p, char dir);
void	game_loop(void *param);
void	init_player(t_player *player, char **map);
void	*ft_memset(void *b, int c, size_t len);
void	rotate_player(t_player *p, double angle);

#endif
