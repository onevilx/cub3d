/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:36:39 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/10 16:31:25 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/raycasting.h"

static void	draw_wall_slice(t_render_ctx *ctx)
{
	double		step;
	double		tex_pos;
	int			tex_y;
	int			y;
	uint32_t	clr;

	step = 1.0 * ctx->tex->height / ctx->height;
	tex_pos = (ctx->start - HEIGHT / 2 + ctx->height / 2) * step;
	y = ctx->start;
	while (y <= ctx->end)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= (int)ctx->tex->height)
			tex_y = ctx->tex->height - 1;
		clr = tex_clr_finder(ctx->tex, ctx->tex_x, tex_y);
		mlx_put_pixel(ctx->img, ctx->x, y, clr);
		tex_pos += step;
		y++;
	}
}

void	draw_wall(int x, t_dda *dda, double dist, t_render_ctx *ctx)
{
	ctx->x = x;
	ctx->height = (int)(HEIGHT / dist);
	ctx->start = -ctx->height / 2 + HEIGHT / 2;
	if (ctx->start < 0)
		ctx->start = 0;
	ctx->end = ctx->height / 2 + HEIGHT / 2;
	if (ctx->end >= HEIGHT)
		ctx->end = HEIGHT - 1;
	draw_column_ceiling(ctx->img, ctx->x, ctx->start, ctx->cubed);
	ctx->tex = select_texture(dda, ctx->cubed);
	ctx->tex_x = get_tex_x(ctx->tex, dda, ctx->p, dist);
	draw_wall_slice(ctx);
	draw_column_floor(ctx->img, ctx->x, ctx->end, ctx->cubed);
}

void	render_3d_view(mlx_image_t *img, t_player *p, t_cubed *cubed)
{
	int				x;
	t_ray_vars		vars;
	t_dda			dda;
	t_render_ctx	ctx;
	double			dist;

	ctx.img = img;
	ctx.p = p;
	ctx.cubed = cubed;
	x = 0;
	while (x < WIDTH)
	{
		init_ray_vars(p, x, &vars);
		dda.ray_dir_x = vars.ray_dir_x;
		dda.ray_dir_y = vars.ray_dir_y;
		init_dda_vars(p, vars.ray_dir_x, vars.ray_dir_y, &dda);
		perform_dda(cubed->map, &dda);
		dist = calculate_dist(&dda, p);
		draw_wall(x, &dda, dist, &ctx);
		x++;
	}
}
