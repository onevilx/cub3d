/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:07:35 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/13 02:25:36 by yaboukir         ###   ########.fr       */
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

void	animate_sword(t_game *game)
{
	static int	frame_timer = 0;
	int			sword_x;
	int			sword_y;

	if (!game->cubed->sword_animating)
		return ;
	frame_timer++;
	if (frame_timer < 1)
		return ;
	frame_timer = 0;
	game->cubed->sword_frame++;
	if (game->cubed->sword_frame >= 7)
	{
		game->cubed->sword_frame = 0;
		game->cubed->sword_animating = 0;
	}
	if (game->cubed->sword_img)
		mlx_delete_image(game->mlx, game->cubed->sword_img);
	game->cubed->sword_img = resize_texture_to_image(game->mlx,
			game->cubed->textr.sword_frames[game->cubed->sword_frame],
			700, 700);
	sword_x = (WIDTH - game->cubed->sword_img->width) / 2;
	sword_y = HEIGHT - game->cubed->sword_img->height;
	mlx_image_to_window(game->mlx, game->cubed->sword_img, sword_x, sword_y);
	game->cubed->sword_img->instances[0].z = 10;
}
