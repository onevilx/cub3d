/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 19:53:54 by adechaji          #+#    #+#             */
/*   Updated: 2025/06/29 20:03:52 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_cubed(t_cubed *cubed)
{
	if (!cubed)
		return;
	if (cubed->no_path)
		free(cubed->no_path);
	if (cubed->so_path)
		free(cubed->so_path);
	if (cubed->we_path)
		free(cubed->we_path);
	if (cubed->ea_path)
		free(cubed->ea_path);
	if (cubed->map)
		free_splited(cubed->map);
	if (cubed->map_fd >= 0)
		close(cubed->map_fd);
}
