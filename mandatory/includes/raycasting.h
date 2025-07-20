/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:26:39 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/16 11:09:10 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"

# define WIDTH 1800
# define HEIGHT 920
# define ROT_SPEED 0.05
# define MOVE_SPEED 0.12

void			init_game(t_game *game, t_cubed *cubed, t_player *player);
void			init_game_img(t_game *game, mlx_image_t *img, mlx_t *mlx);
void			init_ray_vars(t_player *p, int x, t_ray_vars *vars);
void			perform_dda(char **map, t_dda *dda);
void			init_dda_vars(t_player *p, double ray_dir_x,
					double ray_dir_y, t_dda *dda);
void			draw_column_ceiling(mlx_image_t *img, int x, int start,
					t_cubed *cubed);
void			draw_column_floor(mlx_image_t *img, int x, int end,
					t_cubed *cubed);
int				get_tex_x(mlx_texture_t *tex, t_dda *dda, t_player *p,
					double dist);
double			calculate_dist(t_dda *dda, t_player *p);
void			render_3d_view(mlx_image_t *img, t_player *player,
					t_cubed *cubed);
void			set_player_dir(t_player *p, char dir);
void			game_loop(void *param);
void			init_player(t_player *player, char **map);
void			rotate_player(t_player *p, double angle);
mlx_texture_t	*select_texture(t_dda *dda, t_cubed *cubed);

#endif
