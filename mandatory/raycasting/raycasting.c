/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:36:39 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/10 15:17:54 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

static void	draw_wall(mlx_image_t *img, int x, t_dda *dda,
				t_player *p, t_cubed *cubed)
{
	double	dist;
	int		height;
	int		start;
	int		end;
	int		y;

	if (dda->side == 0)
		dist = (dda->map_x - p->pos_x + (1 - dda->step_x) / 2)
			/ dda->ray_dir_x;
	else
		dist = (dda->map_y - p->pos_y + (1 - dda->step_y) / 2)
			/ dda->ray_dir_y;
	height = (int)(HEIGHT / dist);
	start = -height / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = height / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	y = 0;
	while (y < start)
		mlx_put_pixel(img, x, y++, cubed->ceiling_rgb);
	if (y <= end)
	{
		mlx_texture_t *tex;
		uint32_t	clr;
		double 		wall_x;
		double		step;
		double		tex_pos;
		int			tex_x;
		int			tex_y;

		if (dda->side == 0)
		{
			if (dda->ray_dir_x > 0)
				tex = cubed->textr.ea;
			else
				tex = cubed->textr.we;				
		}
		else
		{
			if (dda->ray_dir_y > 0)
				tex = cubed->textr.so;
			else
				tex = cubed->textr.no;
		}
		if (dda->side == 0)
			wall_x = p->pos_y + dist * dda->ray_dir_y;
		else
			wall_x = p->pos_x + dist * dda->ray_dir_x;
		wall_x -= floor(wall_x);
		tex_x = (int)(wall_x * (double)tex->width);
		if ((dda->side == 0 && dda->ray_dir_x > 0) || (dda->side == 1 && dda->ray_dir_y < 0))
			tex_x = tex->width - tex_x - 1;
		step = 1.0 * tex->height / height;
		tex_pos = (start - HEIGHT / 2 + height / 2) * step;
		while (y <= end)
		{
			tex_y = (int)tex_pos;
			if (tex_y >= (int)tex->height)
    			tex_y = tex->height - 1;
			tex_pos += step;
			clr = tex_clr_finder(tex, tex_x, tex_y);
			mlx_put_pixel(img, x, y, clr);
			y++;
		}
	}
	while (y < HEIGHT)
		mlx_put_pixel(img, x, y++, cubed->floor_rgb);
}

void	render_3d_view(mlx_image_t *img, t_player *p, t_cubed *cubed)
{
	int		x;
	t_ray_vars vars;
	t_dda	dda;

	x = 0;
	while (x < WIDTH)
	{
		init_ray_vars(p, x, &vars);
		dda.ray_dir_x = vars.ray_dir_x;
		dda.ray_dir_y = vars.ray_dir_y;
		init_dda_vars(p, vars.ray_dir_x, vars.ray_dir_y, &dda);
		perform_dda(cubed->map, &dda);
		draw_wall(img, x, &dda, p, cubed);
		x++;
	}
}
