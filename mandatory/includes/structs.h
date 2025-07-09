/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onevil_x <onevil_x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:18:13 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/09 17:21:54 by onevil_x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct s_textr
{
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
}	t_textr;

typedef struct cubed
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor_rgb;
	int		ceiling_rgb;
	char	**map;
	char	*map_path;
	int		map_fd;
	t_textr	textr;
}	t_cubed;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_dda
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	int		hit;
	int		side;
	double	ray_dir_x;
	double	ray_dir_y;
}	t_dda;

typedef struct s_ray_vars
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
}	t_ray_vars;

typedef struct s_game
{
	t_cubed		*cubed;
	t_player	*player;
	mlx_image_t	*img;
	mlx_t		*mlx;
}	t_game;

#endif
