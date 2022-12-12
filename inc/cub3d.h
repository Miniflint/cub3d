/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:02:57 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/12 15:56:45 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../minilib/mlx.h"
# include "cub3dstruct.h"

# define FILL '-'

/* GET */
void	test(void);
t_all	*ft_get_all(t_all *all);
void print_double_tab(char **array_double);

/* INIT */
int		__init__(t_all *all);
int	__init_textures(t_all *all);

/* PARSING */
int		check_ext(char *path);
int		check_walls(char **map);
int		contains_fill(char *str);
int		check_nb_player(char *str);
int		check_map_height(char *str);
int		check_view_player(t_all *all);
int		check_map_open(char **modified_map);
int		*letter_pos_on_map(char **map, char letter, int i[2]);
char	**get_map(t_all *all);
char	*read_map(char *path_map);
char	check_player_letter(char *str);
char	*ft_strstr_map(char *s1, char *substr);
char	*cut_strstr_dup(char *str, int c, int map, int offset);
void	check_path_player(char **map, int row, int col, char value);

/* FREE */
void	free_all(void);
void	free_map(t_all *all);
void	handle_error(char *str);
void	free_textures(t_all *all);
void	everything_null(t_all *all);
void	free_double_tab(char **str);

/* UTILS */
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		ft_occurence(char *str, char c);
int		ft_strlen_uc(char *str, char c);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strldup(char *str, int size);
char	*ft_strstr(char *s1, char *substr);
char	**cp_map(char **map, int height_map);

/* MLX */
int		win_mlx_loop(t_all *all);

#endif
