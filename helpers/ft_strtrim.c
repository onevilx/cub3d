/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:26:43 by adechaji          #+#    #+#             */
/*   Updated: 2025/06/29 21:06:58 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/helpers.h"

static int	ft_trim_strlen(const char	*s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

static int	checkerr(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		first;
	int		len;
	int		last;

	if (!s1 || !set)
		return (NULL);
	first = 0;
	last = ft_trim_strlen(s1) - 1;
	while (s1[first] && checkerr(set, s1[first]))
		first++;
	while (last >= first && checkerr(set, s1[last]))
		last--;
	len = last - first + 1;
	newstr = ft_calloc(len + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	ft_memcpy(newstr, s1 + first, len);
	return (newstr);
}
