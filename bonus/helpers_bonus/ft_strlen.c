/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 02:16:23 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/12 22:46:29 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/helpers.h"

int	ft_strlen(const char	*s)
{
	int	i;

	i = 0;
	if (!s[i])
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}
