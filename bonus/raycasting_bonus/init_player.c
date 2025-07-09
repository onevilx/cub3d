/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onevil_x <onevil_x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 01:47:03 by yaboukir          #+#    #+#             */
/*   Updated: 2025/07/09 12:06:39 by onevil_x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/raycasting.h"

static void	set_dir_north(t_player *p)
{
	p->dir_x = 0;
	p->dir_y = -1;
	p->plane_x = 0.66;
	p->plane_y = 0;
}

static void	set_dir_south(t_player *p)
{
	p->dir_x = 0;
	p->dir_y = 1;
	p->plane_x = -0.66;
	p->plane_y = 0;
}

static void	set_dir_east(t_player *p)
{
	p->dir_x = 1;
	p->dir_y = 0;
	p->plane_x = 0;
	p->plane_y = 0.66;
}

static void	set_dir_west(t_player *p)
{
	p->dir_x = -1;
	p->dir_y = 0;
	p->plane_x = 0;
	p->plane_y = -0.66;
}

void	set_player_dir(t_player *p, char dir)
{
	if (dir == 'N')
		set_dir_north(p);
	else if (dir == 'S')
		set_dir_south(p);
	else if (dir == 'E')
		set_dir_east(p);
	else if (dir == 'W')
		set_dir_west(p);
}
