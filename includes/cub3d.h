/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:29:15 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/07 06:39:41 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>		// read, write, close
# include <fcntl.h>			// open
# include <stdio.h>			// printf, perror
# include <stdlib.h>		// malloc, free, exit
# include <string.h>		// strerror
# include <sys/time.h>		// gettimeofday
# include <math.h>			// sin, cos, sqrt, etc.
# include "MLX42/MLX42.h"	 // MLX42 library
# include "../helpers/Get_Next_Line/get_next_line.h"

typedef struct s_textr
{
	mlx_texture_t *no;
	mlx_texture_t *so;
	mlx_texture_t *we;
	mlx_texture_t *ea;
} t_textr;

typedef struct cubed
{
	char	*no_path;		//north_path
	char	*so_path;		//south_path
	char	*we_path;		//west_side_path crips
	char	*ea_path;		//east_path eaaaaaasiiiide mtfkrs ballas
	int		floor_rgb;
	int		f_set;
	int		ceiling_rgb;
	int		c_set;
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


typedef struct s_game
{
	t_cubed		*cubed;
	t_player	*player;
	mlx_image_t	*img;
	mlx_t		*mlx;
}	t_game;

# include "parsing.h"
# include "helpers.h"
# include "raycasting.h"

#endif
