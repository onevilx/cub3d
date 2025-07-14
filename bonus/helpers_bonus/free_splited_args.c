/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_splited_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:02:33 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/14 17:25:01 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/helpers.h"

void	free_splited(char **split)
{
	int	i;

	if (!split || !split[0])
		return ;
	i = 0;
	while (split[i])
	{
		if (split[i])
			free(split[i]);
		i++;
	}
	free(split);
}
