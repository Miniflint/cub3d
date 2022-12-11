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
int		check_ext(char *path);
int		check_walls(char **map);
int		check_nb_player(char *str);
int		check_map_height(char *str);
char	check_player_letter(char *str);
char	**get_map(t_all *all);
char	*read_map(char *path_map);
char	*ft_strstr_map(char *s1, char *substr);
char	*cut_strstr_dup(char *str, int c, int map);
void	check_path_player(char **map, int row, int col, char value);

// FREE
void	free_all(void);
void	free_map(t_all *all);
void	free_textures(t_all *all);
void	handle_error(char *str);
void	everything_null(t_all *all);

// UTILS
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		ft_occurence(char *str, char c);
int		ft_strlen_uc(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*ft_strldup(char *str, int size);
char	*ft_strstr(char *s1, char *substr);

#endif
