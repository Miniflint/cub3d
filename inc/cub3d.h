/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:02:57 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/20 15:56:44 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include "../minilib/mlx.h"
# include "mlxstruct.h"
# include "cub3dstruct.h"

# define FILL '-'
# define DISTANCE 0.15
# define PI_DIVIDE 16
# define PX 32

/* GET */
void	test(void);
t_all	*ft_get_all(t_all *all);
void    print_double_tab(char **array_double);
void	print_wth_is_that(t_raycast r);

/* INIT */
int		__init__(t_all *all);
int		__init_textures(t_all *all);
t_data	*__img_init(void *mlx, int w, int h);
// t_data	*__init__image(t_all *all, int width, int height);
bool     open_xpm_images(t_all *all);

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
int 	check_fd_valid(char *path);
int 	check_xpm_exist(t_all *all);
int		ft_occurence(char *str, char c);
int		ft_strlen_uc(char *str, char c);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strldup(char *str, int size);
char	*ft_strstr(char *s1, char *substr);
char	**cp_map(char **map, int height_map);

/* MLX */
int		close_window(void);
int		win_mlx_loop(t_all *all);
int	    create_trgb(int t, int r, int g, int b);
void    draw_map(t_all *all);
void    drawray(t_all *all);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/* MOVES */
void	move_with_key(t_all *all);
int		keyUpped(int keycode, t_all *all);
int		keyDowned(int keycode, t_all *all);
void	translate_key(int keycode, t_all *all, int value);

/* WIZARD CALCULUS */
double	calculus_view(t_all *all);
// void	drawray(t_all *all);
void    plot_image(t_all *all);

/* DRAW */
void    draw_cubes(t_all   *all, int *col_size);
int     get_col_text_pixel(t_data *img, int x, int y);
void    draw_column_texture(t_data *src, t_data *dst, int x, int cube_height);

#endif
