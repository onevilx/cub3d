/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:26:39 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/16 11:10:32 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"

# define TILE_SIZE 10
# define WIDTH 1800
# define HEIGHT 920
# define ROT_SPEED 0.05
# define MOVE_SPEED 0.12
# define MOUSE_SENSITIVITY 0.002
# define MINIMAP_TILE 10
# define MINIMAP_RADIUS 10

void			init_game(t_game *game, t_cubed *cubed, t_player *player);
void			init_game_img(t_game *game, mlx_image_t *img, mlx_t *mlx);
void			init_sword_image(t_game *game, mlx_t *mlx);
void			animate_sword(t_game *game);
void			init_ray_vars(t_player *p, int x, t_ray_vars *vars);
void			render_3d_view(mlx_image_t *img, t_player *player,
					t_cubed *cubed);
mlx_image_t		*resize_texture_to_image(mlx_t *mlx, mlx_texture_t *tex,
					int new_w, int new_h);
void			draw_minimap(mlx_image_t *img, t_cubed *cubed,
					t_player *player);
void			init_dda_vars(t_player *p, double ray_dir_x, double ray_dir_y,
					t_dda *dda);
double			calculate_dist(t_dda *dda, t_player *p);
mlx_texture_t	*select_texture(t_dda *dda, t_cubed *cubed);
void			draw_column_ceiling(mlx_image_t *img, int x,
					int start, t_cubed *cubed);
void			draw_column_floor(mlx_image_t *img, int x,
					int end, t_cubed *cubed);
int				get_tex_x(mlx_texture_t *tex, t_dda *dda,
					t_player *p, double dist);
void			perform_dda(char **map, t_dda *dda, t_cubed *cubed);
void			set_player_dir(t_player *p, char dir);
void			mouse_look(t_game *game);
void			game_loop(void *param);
void			init_player(t_player *player, char **map);
void			rotate_player(t_player *p, double angle);
int				is_player_near_door(t_cubed *cubed, t_player *player);
int				is_in_map(t_cubed *cubed, int y, int x);
#endif
