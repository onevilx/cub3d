/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:25:57 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/04 12:05:57 by adechaji         ###   ########.fr       */
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
int     valid_path(char *path);
int     valid_color(char *str, int *clr);
char	*valid_tex_path(char *arg);

#endif