/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3dstruct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:11:13 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/11 17:00:37 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3DSTRUCT_H
# define CUB3DSTRUCT_H

# include "cub3d.h"

typedef struct S_raycast
{
	float	x;
	float	y;

}	t_raycast;

typedef struct S_player
{
	char	letter;
	int		start_x;
	int		start_y;
	float	x;
	float	y;
}	t_player;

typedef struct S_map
{
	int		map_height;
	char	*file;
	char	*map_array;
	char	**map;
}	t_map;

typedef struct S_textures
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		f_int[3];
	int		c_int[3];
}	t_textures;

typedef struct S_all
{
	char		*path_to_map;
	t_map		map;
	t_textures	txtr;
	t_player	player;
	t_raycast	*raycast;
}	t_all;

#endif
