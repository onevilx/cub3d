/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:07:35 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/15 19:12:32 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/raycasting.h"

static uint32_t	get_scaled_pixel_color(mlx_texture_t *tex,
		int x, int y, t_img_size size)
{
	int			src_x;
	int			src_y;
	uint8_t		*src_pixel;
	uint32_t	color;

	src_x = x * tex->width / size.width;
	src_y = y * tex->height / size.height;
	src_pixel = &tex->pixels[(src_y * tex->width + src_x) * 4];
	color = (src_pixel[0] << 24)
		| (src_pixel[1] << 16)
		| (src_pixel[2] << 8)
		| src_pixel[3];
	return (color);
}

mlx_image_t	*resize_texture_to_image(mlx_t *mlx, mlx_texture_t *tex,
		int new_w, int new_h)
{
	mlx_image_t	*resized;
	int			x;
	int			y;
	uint32_t	color;
	t_img_size	size;

	size.width = new_w;
	size.height = new_h;
	resized = mlx_new_image(mlx, new_w, new_h);
	if (!resized)
		return (NULL);
	y = 0;
	while (y < new_h)
	{
		x = 0;
		while (x < new_w)
		{
			color = get_scaled_pixel_color(tex, x, y, size);
			mlx_put_pixel(resized, x, y, color);
			x++;
		}
		y++;
	}
	return (resized);
}

static void	update_sword_pixels(t_game *game, mlx_texture_t *tex)
{
	int			x;
	int			y;
	uint32_t	color;
	t_img_size	size;

	size.width = game->cubed->sword_img->width;
	size.height = game->cubed->sword_img->height;
	y = -1;
	while (++y < size.height)
	{
		x = -1;
		while (++x < size.width)
		{
			color = get_scaled_pixel_color(tex, x, y, size);
			mlx_put_pixel(game->cubed->sword_img, x, y, color);
		}
	}
}

void	animate_sword(t_game *game)
{
	static int		frame_timer = 0;
	mlx_texture_t	*tex;

	if (!game->cubed->sword_animating)
		return ;
	if (++frame_timer < 1)
		return ;
	frame_timer = 0;
	game->cubed->sword_frame++;
	if (game->cubed->sword_frame >= 7)
	{
		game->cubed->sword_frame = 0;
		game->cubed->sword_animating = 0;
		return ;
	}

	tex = game->cubed->textr.sword_frames[game->cubed->sword_frame];
	update_sword_pixels(game, tex);
}
