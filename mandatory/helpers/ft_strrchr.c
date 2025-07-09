/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:13:01 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/09 12:20:48 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/helpers.h"

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
