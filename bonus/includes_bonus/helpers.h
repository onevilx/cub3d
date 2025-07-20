/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 01:27:49 by adechaji          #+#    #+#             */
/*   Updated: 2025/07/14 18:19:39 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include "cub3d.h"

char	*ft_strrchr(const char *s, int c);
char	*ft_strrchr_custom(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	**ft_old_split(char const *s, char c);
int		ft_atoi(const char *str);
void	free_splited(char **split);
void	*ft_memcpy(void *dest, const void *src, size_t num);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_itoa(int n);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_isdigit(int c);

#endif
