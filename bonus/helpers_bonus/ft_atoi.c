/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:00:22 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/14 17:25:11 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/helpers.h"

static int	of(int s)
{
	if (s == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		s;
	ssize_t	num;

	num = 0;
	s = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num > ((9223372036854775807 - (str[i] - '0')) / 10))
			return (of(s));
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)num * s);
}
