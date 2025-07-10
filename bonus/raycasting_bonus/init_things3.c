/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_things3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 01:44:26 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/10 14:29:51 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/raycasting.h"

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
}

void	init_game(t_game *game, t_cubed *cubed, t_player *player)
{
	game->cubed = cubed;
	game->player = player;
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
