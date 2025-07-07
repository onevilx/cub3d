/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 00:28:49 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/07 00:37:21 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	val_hlp(char *str)
{
	int	r;
	int	g;

	g = 0;
	r = 0;
	while (str[r])
	{
		if (!ft_isdigit(str[r]) && str[r] != ',')
			return (1);
		if (str[r] == ',')
			g++;
		r++;
	}
	if (g > 2)
		return (1);
	return (0);
}

int	valid_color(char *str, int *clr)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	if (val_hlp(str) == 1)
		return (1);
	rgb = ft_old_split(str, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		return (1);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (1);
	*clr = (r << 16) | (g << 8) | b;
	free_splited(rgb);
	return (0);
}
