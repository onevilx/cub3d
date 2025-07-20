/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:03:33 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/14 17:25:21 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/helpers.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmps;

	tmps = (unsigned char *)s;
	while (n > 0)
	{
		*tmps = 0;
		tmps++;
		n--;
	}
}
