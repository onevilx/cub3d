/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_custom.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 04:06:24 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/14 17:26:45 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/helpers.h"

char	*ft_strrchr_custom(const char *s, int c)
{
	char	*lastseen;
	int		i;

	lastseen = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			break ;
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		return ((char *) &s[i]);
	}
	return (lastseen);
}
