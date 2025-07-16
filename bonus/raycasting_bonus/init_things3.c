/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_things3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 01:44:26 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/16 10:42:22 by yaboukir         ###   ########.fr       */
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
	int	mm_width;
	int	mm_height;

	mm_width = (2 * MINIMAP_RADIUS + 1) * TILE_SIZE;
	mm_height = (2 * MINIMAP_RADIUS + 1) * TILE_SIZE;
	game->minimap = mlx_new_image(mlx, mm_width, mm_height);
	if (!game->minimap)
	{
		ft_putstr_fd("Error creating minimap image\n", 2);
		exit(EXIT_FAILURE);
	}
	mlx_image_to_window(mlx, game->minimap, 10, 10);
}

void	init_game_img(t_game *game, mlx_image_t *img, mlx_t *mlx)
{
	game->mlx = mlx;
	game->img = img;
	mlx_image_to_window(mlx, game->img, 0, 0);
	create_minimap_image(game, mlx);
	init_sword_image(game, mlx);
}
