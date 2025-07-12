/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_things3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 01:44:26 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/11 18:19:40 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/raycasting.h"

void	init_game(t_game *game, t_cubed *cubed, t_player *player)
{
	game->cubed = cubed;
	game->player = player;
}

void	get_map_dimensions(char **map, int *width, int *height)
{
	int	i;
	int	len;

	i = 0;
	*width = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > *width)
			*width = len;
		i++;
	}
	*height = i;
}

void	init_game_img(t_game *game, mlx_image_t *img, mlx_t *mlx)
{
	int	map_w;
	int	map_h;
	int	mm_width;
	int	mm_height;
	mlx_image_t	*sword_img;

	game->mlx = mlx;
	game->img = img;
	get_map_dimensions(game->cubed->map, &map_w, &map_h);
	mm_width = map_w * TILE_SIZE;
	mm_height = map_h * TILE_SIZE;
	game->minimap = mlx_new_image(mlx, mm_width, mm_height);
	if (!game->minimap)
	{
		printf("Error creating minimap image\n");
		exit(EXIT_FAILURE);
	}
	mlx_image_to_window(mlx, game->img, 0, 0);
	mlx_image_to_window(mlx, game->minimap, 10, 10);
	game->cubed->sword_frame = 0;
	game->cubed->sword_animating = 0;
	sword_img = resize_texture_to_image(mlx, game->cubed->textr.sword_frames[0], 700, 700);
	if (!sword_img)
	{
		printf("Error: Failed to convert sword texture to image\n");
		exit(EXIT_FAILURE);
	}
	game->cubed->sword_img = sword_img;
	int sword_x = (WIDTH - sword_img->width) / 2;
	int sword_y = HEIGHT - sword_img->height;
	if (mlx_image_to_window(mlx, sword_img, sword_x, sword_y) < 0)
	{
		printf("Error: Failed to put sword image to window\n");
		exit(EXIT_FAILURE);
	}
}

void	mouse_look(t_game *game)
{
	double	angle;
	int		mouse_x;
	int		mouse_y;
	int		delta_x;

	mlx_get_mouse_pos(game->mlx, &mouse_x, &mouse_y);
	delta_x = mouse_x - (WIDTH / 2);
	if (delta_x > 100)
		delta_x = 100;
	else if (delta_x < -100)
		delta_x = -100;
	if (delta_x != 0)
	{
		angle = delta_x * MOUSE_SENSITIVITY;
		rotate_player(game->player, angle);
		mlx_set_mouse_pos(game->mlx, (WIDTH / 2), HEIGHT / 2);
	}
}

void	draw_minimap(mlx_image_t *img, t_cubed *cubed, t_player *player)
{
	int	y;
	int	x;

	y = 0;
	while (cubed->map[y])
	{
		x = 0;
		while (cubed->map[y][x])
		{
			if (cubed->map[y][x] == '1')
				draw_square(img, x, y, 0xFFFFFFFF);
			else if (cubed->map[y][x] == '0'
				|| ft_strrchr("NSEW", cubed->map[y][x]))
				draw_square(img, x, y, 0x333333FF);
			x++;
		}
		y++;
	}
	draw_player(img, player);
}
