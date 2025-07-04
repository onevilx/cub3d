/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:29:15 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/03 23:32:09 by yaboukir         ###   ########.fr       */
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

# include "parsing.h"
# include "helpers.h"
# include "raycasting.h"

#endif