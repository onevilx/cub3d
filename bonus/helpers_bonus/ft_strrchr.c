/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:13:01 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/14 17:26:48 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/helpers.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*lastseen;
	int		i;

	lastseen = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			lastseen = ((char *) &s[i]);
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		return ((char *) &s[i]);
	}
	return (lastseen);
}
