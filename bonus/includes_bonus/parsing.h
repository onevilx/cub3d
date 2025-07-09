/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:25:57 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/09 12:14:21 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

//main func
int			parsing(t_cubed	*cubed);
int			r_paths(t_cubed	*cubed);
int			r_map(t_cubed	*cubed);
int			is_emptyl(char *str);
void		free_cubed(t_cubed *cubed);
int			parse_it(char	**map);
int			is_valid_map(char **map);
int			valid_path(char *path);
int			valid_color(char *str, int *clr);
char		*valid_tex_path(char *arg);
int			is_texture(t_cubed *cubed, char *str, char *arg);
int			load_textures(t_cubed *cubed);
void		free_textures(t_cubed *cubed);
uint32_t	tex_clr_finder(mlx_texture_t *tex, int x, int y);
int			valid_storeit(t_cubed *cubed, char **map);

#endif