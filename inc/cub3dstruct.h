/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3dstruct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:11:13 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/19 15:37:15 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3DSTRUCT_H
# define CUB3DSTRUCT_H

# include "cub3d.h"

// je sais pas encore quoi mettre la dedans
// mais je l'ai quand même crée parce qu'on sait jamais
// quand j'en aurai besoin
typedef struct S_raycast
{
	int		r;
	int		mx;
	int		my;
	int		mp;
	int		depth;
	double	x;
	double	y;
	double	angle;
	double	x_offset;
	double	y_offset;
}	t_raycast;

typedef struct S_movement
{
	int	key_w;
	int	key_a;
	int	key_s;
	int	key_d;
	int	arr_left;
	int	arr_right;
}	t_movement;

// va contenir les info du joueur
typedef struct S_player
{
	char		letter;
	double		x;
	double		y;
	double		dx;
	double		dy;
	double		angle;
	double		angle_per_key;
	t_movement	moves;
	t_raycast	raycast;
}	t_player;

// va contenir les info du joueur
typedef struct S_map
{
	int		map_height;
	char	*file;
	char	*map_array;
	char	**map;
}	t_map;

// va contenir les info du joueur
typedef struct S_textures
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_data	*no_img;
	t_data	*so_img;
	t_data	*we_img;
	t_data	*ea_img;
	char	*f;
	char	*c;
	char	*r;
	int		f_int[3];
	int		c_int[3];
	int		r_int[2];
}	t_textures;

// contient tout le programme
// peut être récuperé grace à la fonction
// all = ft_get_all(NULL);
// voir ft_get_all dans src/utils/ft_get_all.c
typedef struct S_all
{
	char		*path_to_map;
	t_map		map;
	t_textures	txtr;
	t_player	player;
	t_mlx		mlx;
}	t_all;

#endif
