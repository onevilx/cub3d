/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_states.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:04:05 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/11 18:04:36 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d.h"

int	is_player_near_door(t_cubed *cubed, t_player *player)
{
	int		y;
	int		x;
	double	dx;
	double	dy;

	y = 0;
	while (cubed->map[y])
	{
		x = 0;
		while (cubed->map[y][x])
		{
			if (cubed->map[y][x] == 'H')
			{
				dx = (x + 0.5) - player->pos_x;
				dy = (y + 0.5) - player->pos_y;
				if ((dx * dx + dy * dy) < 1.0)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
