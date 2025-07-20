/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_things2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 01:28:49 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/13 02:32:57 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

void	init_ray_vars(t_player *p, int x, t_ray_vars *vars)
{
	vars->camera_x = 2 * x / (double)WIDTH - 1;
	vars->ray_dir_x = p->dir_x + p->plane_x * vars->camera_x;
	vars->ray_dir_y = p->dir_y + p->plane_y * vars->camera_x;
}

void	init_dda_vars(t_player *p, double ray_dir_x,
	double ray_dir_y, t_dda *dda)
{
	dda->map_x = (int)p->pos_x;
	dda->map_y = (int)p->pos_y;
	dda->delta_x = fabs(1 / ray_dir_x);
	dda->delta_y = fabs(1 / ray_dir_y);
	if (ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_x = (p->pos_x - dda->map_x) * dda->delta_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_x = (dda->map_x + 1.0 - p->pos_x) * dda->delta_x;
	}
	if (ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_y = (p->pos_y - dda->map_y) * dda->delta_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_y = (dda->map_y + 1.0 - p->pos_y) * dda->delta_y;
	}
}

int	is_wall_hit(char **map, t_dda *dda, int map_height)
{
	if (dda->map_x < 0 || dda->map_y < 0 || dda->map_y >= map_height)
		return (1);
	if (dda->map_x >= (int)ft_strlen(map[dda->map_y]))
		return (1);
	if (map[dda->map_y][dda->map_x] == '1')
	{
		dda->hit = 1;
		return (1);
	}
	return (0);
}

void	perform_dda(char **map, t_dda *dda)
{
	int	map_height;

	map_height = 0;
	while (map[map_height])
		map_height++;
	dda->hit = 0;
	while (dda->hit == 0)
	{
		if (dda->side_x < dda->side_y)
		{
			dda->side_x += dda->delta_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_y += dda->delta_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (is_wall_hit(map, dda, map_height))
			break ;
	}
}
