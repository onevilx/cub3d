/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:07:35 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/11 18:24:30 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/raycasting.h"

mlx_image_t	*resize_texture_to_image(mlx_t *mlx, mlx_texture_t *tex, int new_w, int new_h)
{
	mlx_image_t	*resized;
	int			x, y;
	int			src_x, src_y;
	uint8_t		*src_pixel;
	uint32_t	color;

	resized = mlx_new_image(mlx, new_w, new_h);
	if (!resized)
		return (NULL);
	for (y = 0; y < new_h; y++)
	{
		for (x = 0; x < new_w; x++)
		{
			src_x = x * tex->width / new_w;
			src_y = y * tex->height / new_h;
			src_pixel = &tex->pixels[(src_y * tex->width + src_x) * 4];
			color = (src_pixel[0] << 24) | (src_pixel[1] << 16)
				| (src_pixel[2] << 8) | src_pixel[3];
			mlx_put_pixel(resized, x, y, color);
		}
	}
	return (resized);
}

void	mouse_press_handler(mlx_key_data_t keydata, void *param)
{
	t_game *game = (t_game *)param;

	if (keydata.key == MLX_MOUSE_BUTTON_LEFT && keydata.action == MLX_PRESS)
	{
		if (!game->cubed->sword_animating)
		{
			game->cubed->sword_animating = 1;
			game->cubed->sword_frame = 0;
		}
	}
}
