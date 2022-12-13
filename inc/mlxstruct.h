/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxstruct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:11:13 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/12 15:51:22 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	void	*image;
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
	K_Q = 12,
	K_ESC = 53,
	K_A = 0,
	K_LEFT = 123,
	K_S = 1,
	K_RIGHT = 124,
	K_D = 2,
	K_DOWN = 125,
	K_W = 13,
	K_UP = 126,
};
