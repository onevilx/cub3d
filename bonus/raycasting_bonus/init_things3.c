/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_things3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 01:44:26 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/13 02:25:06 by yaboukir         ###   ########.fr       */
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

void	create_minimap_image(t_game *game, mlx_t *mlx)
{
	int	map_w;
	int	map_h;
	int	mm_width;
	int	mm_height;

	get_map_dimensions(game->cubed->map, &map_w, &map_h);
	mm_width = map_w * TILE_SIZE;
	mm_height = map_h * TILE_SIZE;
	game->minimap = mlx_new_image(mlx, mm_width, mm_height);
	if (!game->minimap)
	{
		printf("Error creating minimap image\n");
		exit(EXIT_FAILURE);
	}
	mlx_image_to_window(mlx, game->minimap, 10, 10);
}

void	init_game_img(t_game *game, mlx_image_t *img, mlx_t *mlx)
{
	game->mlx = mlx;
	game->img = img;
	game->cubed->sword_frame = 0;
	game->cubed->sword_animating = 0;
	mlx_image_to_window(mlx, game->img, 0, 0);
	create_minimap_image(game, mlx);
	init_sword_image(game, mlx);
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
