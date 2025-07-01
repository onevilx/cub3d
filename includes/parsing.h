/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:25:57 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/01 01:59:44 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

//main func
int		parsing(t_cubed	*cubed);
int		r_paths(t_cubed	*cubed);
int		r_map(t_cubed	*cubed);
int		is_emptyl(char *str);
void	free_cubed(t_cubed *cubed);
int		parse_it(char	**map);
int		is_valid_map(char **map);
#endif