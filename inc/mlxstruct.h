/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxstruct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:11:13 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/13 17:09:39 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXSTRUCT_H
# define MLXSTRUCT_H

#include "cub3d.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct S_mlx
{
	void	*mlx;
	void	*window;
	t_data	*image;
}	t_mlx;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	K_ESC = 53,
	K_Q = 12,
	K_A = 0,
	K_S = 1,
	K_D = 2,
	K_W = 13,
	ARR_LEFT = 123,
	ARR_RIGHT = 124,
	ARR_DOWN = 125,
	ARR_UP = 126,
};

#endif