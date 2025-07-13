/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_things4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:42:32 by onevil_x          #+#    #+#             */
/*   Updated: 2025/07/13 16:18:40 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/raycasting.h"

double	calculate_dist(t_dda *dda, t_player *p)
{
	if (dda->side == 0)
		return ((dda->map_x - p->pos_x + (1 - dda->step_x) / 2)
			/ dda->ray_dir_x);
	return ((dda->map_y - p->pos_y + (1 - dda->step_y) / 2) / dda->ray_dir_y);
}

mlx_texture_t	*select_texture(t_dda *dda, t_cubed *cubed)
{
	if (cubed->map[dda->map_y][dda->map_x] == 'H' && !cubed->op_door)
		return (cubed->textr.hd);
	if (dda->side == 0)
	{
		if (dda->ray_dir_x > 0)
			return (cubed->textr.ea);
		return (cubed->textr.we);
	}
	if (dda->ray_dir_y > 0)
		return (cubed->textr.so);
	return (cubed->textr.no);
}

void	draw_column_ceiling(mlx_image_t *img, int x, int start, t_cubed *cubed)
{
	int	y;

	y = 0;
	while (y < start)
	{
		mlx_put_pixel(img, x, y, cubed->ceiling_rgb);
		y++;
	}
}

void	draw_column_floor(mlx_image_t *img, int x, int end, t_cubed *cubed)
{
	int	y;

	y = end + 1;
	while (y < HEIGHT)
	{
		mlx_put_pixel(img, x, y, cubed->floor_rgb);
		y++;
	}
}

int	get_tex_x(mlx_texture_t *tex, t_dda *dda, t_player *p, double dist)
{
	double	wall_x;
	int		tex_x;

	if (dda->side == 0)
		wall_x = p->pos_y + dist * dda->ray_dir_y;
	else
		wall_x = p->pos_x + dist * dda->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->width);
	if ((dda->side == 0 && dda->ray_dir_x > 0)
		|| (dda->side == 1 && dda->ray_dir_y < 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}
