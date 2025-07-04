/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:36:39 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/04 12:40:50 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

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
				draw_square(img, x, y, 0xFFFFFFFF); // Wall
			else if (cubed->map[y][x] == '0' || ft_strrchr("NSEW", cubed->map[y][x]))
				draw_square(img, x, y, 0x333333FF); // Floor
			x++;
		}
		y++;
	}
	draw_player(img, player);
}
