/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_custom.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 04:06:24 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/09 12:20:58 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/helpers.h"

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
