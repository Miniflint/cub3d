/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:02:57 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/08 12:24:26 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "cub3dstruct.h"

// GET ALL
t_all	*ft_get_all(t_all *all);

// INIT
int		__init__(t_all *all);

// PARSE
char	*read_map(char *path_map);
char	*cut_strstr_dup(char *str, int c);
int		check_ext(char *path);
char	*ft_strstr_map(char *s1, char *substr);

// FREE
void	free_all(void);
void	free_map(t_all *all);
void	free_textures(t_all *all);
void	handle_error(char *str);

// UTILS
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*ft_strldup(char *str, int size);
char	*ft_strstr(char *s1, char *substr);

#endif
