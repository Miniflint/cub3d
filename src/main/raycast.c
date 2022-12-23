/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:45:04 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/14 21:30:41 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#define MAX_DEPTH 8

/* 
 * O		= ray direction
 * x, y		= player pos
 * dx, dy	= offset between tiles (1)
 * Depending on 0:
 *
 * 
*/

// void	drawray(t_all *all)
// {
// 	int		i;
// 	double	matan;

// 	i = 0;
// 	all->player.raycast.angle = all->player.angle;
// 	while (i++ < 1)
// 	{
// 		all->player.raycast2.depth = 0;
// 		matan =  atan(all->player.raycast2.angle);
// 		//printf("%f\n", matan);
// 		if (all->player.raycast.angle > M_PI)
// 		{
// 			all->player.raycast2.y = (int)all->player.y-0.000001;
// 			all->player.raycast2.x = all->player.x-all->player.y * matan + all->player.x;
// 			all->player.raycast2.y_offset = -1;
// 			all->player.raycast2.x_offset = all->player.raycast2.y_offset * matan;
// 		}
// 		if (all->player.raycast2.angle < M_PI)
// 		{
// 			all->player.raycast2.y = (int)all->player.y;
// 			all->player.raycast2.x = (all->player.x-all->player.y)*matan+all->player.x;
// 			all->player.raycast2.y_offset = -1;
// 			all->player.raycast2.x_offset = all->player.raycast2.y_offset * matan;
// 		}
// 		if ((all->player.raycast2.angle <= 0.00001 && all->player.raycast2.angle >= -0.00001)
// 			|| (all->player.raycast2.angle <= M_PI + 0.00001 && all->player.raycast2.angle >= M_PI - 0.00001)
// 			|| (all->player.raycast2.angle <= 2 * M_PI + 0.00001 && all->player.raycast2.angle >= 2 * M_PI - 0.00001))
// 		{
// 			all->player.raycast2.x = all->player.x;
// 			all->player.raycast2.y = all->player.y;
// 			all->player.raycast2.depth = MAX_DEPTH;
// 		}
// 		//printf("y: %f -x: %f -oy: %f - ox: %f\n", all->player.raycast2.y, all->player.raycast2.x, all->player.raycast2.y_offset, all->player.raycast2.x_offset);
// 		while (all->player.raycast2.depth < MAX_DEPTH)
// 		{
// 			all->player.raycast2.mx = (int)all->player.raycast2.x;
// 			all->player.raycast2.my = (int)all->player.raycast2.y;
// 			if (all->map.map[all->player.raycast2.my][all->player.raycast2.mx]
// 				&& all->map.map[all->player.raycast2.my][all->player.raycast2.mx] == '1')
// 				all->player.raycast2.depth = MAX_DEPTH;
// 			else
// 			{
// 				all->player.raycast2.x += all->player.raycast2.x_offset;
// 				all->player.raycast2.y += all->player.raycast2.y_offset;
// 				all->player.raycast2.depth += 1;
// 			}
// 			//all->player.raycast.depth += 1;
// 		}
// 	}
// }

// player pos, angle, dx, dy

static double	delete_virgule(double nb)
{
	while (nb > 1)
		nb -= 1;
	return (nb);
}

static void draw_hor(t_all *all)
{
	if (all->player.raycast.angle > 0 && all->player.raycast.angle < (M_PI / 2))
	{
		all->player.raycast.h.x = all->player.x + all->player.raycast.h.x_offset /* tan(all->player.raycast.angle) */;
		all->player.raycast.h.y = all->player.y - all->player.raycast.h.y_offset;
	}
	else if (all->player.raycast.angle > (M_PI / 2) && all->player.raycast.angle < M_PI)
	{
		all->player.raycast.h.x = all->player.x - all->player.raycast.h.x_offset /* tan(all->player.raycast.angle) */;
		all->player.raycast.h.y = all->player.y - all->player.raycast.h.y_offset;
	}
	else if (all->player.raycast.angle > M_PI && all->player.raycast.angle < (M_PI * 1.5))
	{
		all->player.raycast.h.x = all->player.x - all->player.raycast.h.x_offset /* tan(all->player.raycast.angle) */;
		all->player.raycast.h.y = all->player.y + all->player.raycast.h.y_offset;
	}
	else if (all->player.raycast.angle > (M_PI * 1.5) && all->player.raycast.angle < (M_PI * 2))
	{
		all->player.raycast.h.x = all->player.x + all->player.raycast.h.x_offset /* tan(all->player.raycast.angle) */;
		all->player.raycast.h.y = all->player.y + all->player.raycast.h.y_offset;
	}
}

static void draw_vert(t_all *all)
{
	if (all->player.raycast.angle > 0 && all->player.raycast.angle < (M_PI / 2))
	{
		all->player.raycast.v.x = all->player.x + all->player.raycast.v.x_offset;
		all->player.raycast.v.y = all->player.y - all->player.raycast.v.y_offset;
	}
	else if (all->player.raycast.angle > (M_PI / 2) && all->player.raycast.angle < M_PI)
	{
		all->player.raycast.v.x = all->player.x - all->player.raycast.v.x_offset;
		all->player.raycast.v.y = all->player.y - all->player.raycast.v.y_offset;
	}
	else if (all->player.raycast.angle > M_PI && all->player.raycast.angle < (M_PI * 1.5))
	{
		all->player.raycast.v.x = all->player.x - all->player.raycast.v.x_offset;
		all->player.raycast.v.y = all->player.y + all->player.raycast.v.y_offset;
	}
	else if (all->player.raycast.angle > (M_PI * 1.5) && all->player.raycast.angle < (M_PI * 2))
	{
		all->player.raycast.v.x = all->player.x + all->player.raycast.v.x_offset;
		all->player.raycast.v.y = all->player.y + all->player.raycast.v.y_offset;
	}
}

static void set_offset(t_all *all)
{
	all->player.raycast.h.depth = 0;
	all->player.raycast.h.y_offset = 1 - delete_virgule(all->player.y);
	all->player.raycast.h.x_offset = 1 - delete_virgule(all->player.x);
	all->player.raycast.v.depth = 0;
	all->player.raycast.v.y_offset = 1 - delete_virgule(all->player.y);
	all->player.raycast.v.x_offset = 1 - delete_virgule(all->player.x);
}

void	drawray_hor(t_all *all, double cond)
{
	int		i;
	char	**map;

	i = 0;
	map = all->map.map;
	all->player.raycast.angle = all->player.angle;
	set_offset(all);
	draw_hor(all);
	all->player.raycast.h.mx = (int)all->player.raycast.h.x;
	all->player.raycast.h.my = (int)all->player.raycast.h.y;
	while (all->player.raycast.h.depth < MAX_DEPTH && all->player.raycast.v.depth < MAX_DEPTH
	&& all->player.raycast.h.my < all->map.map_height)
	{
		if (all->player.raycast.h.my < 0 || all->player.raycast.h.mx < 0 || all->player.raycast.h.my > 1500 || all->player.raycast.h.mx > 1500)
		{
			all->player.raycast.h.depth = MAX_DEPTH;
			break ;
		}
		if (map[all->player.raycast.h.my][all->player.raycast.h.mx]
			&& map[all->player.raycast.h.my][all->player.raycast.h.mx] == '1')
			all->player.raycast.h.depth = MAX_DEPTH;
		else
		{
			all->player.raycast.h.y += 1 * tan(all->player.raycast.angle);
			all->player.raycast.h.x += cond;
			all->player.raycast.h.mx = (int)all->player.raycast.h.x;
			all->player.raycast.h.my = (int)all->player.raycast.h.y;
			all->player.raycast.h.depth += 1;
		}
	}
}

void	drawray_ver(t_all *all)
{
	int		i;
	char	**map;

	i = 0;
	map = all->map.map;
	all->player.raycast.angle = all->player.angle;
	set_offset(all);
	draw_vert(all);
	all->player.raycast.v.mx = (int)all->player.raycast.v.x;
	all->player.raycast.v.my = (int)all->player.raycast.v.y;
	while (all->player.raycast.v.depth < MAX_DEPTH && all->player.raycast.v.depth < MAX_DEPTH
		&& all->player.raycast.v.my < all->map.map_height)
	{
		if (all->player.raycast.v.my < 0 || all->player.raycast.h.mx < 0 || all->player.raycast.h.my > 1500 || all->player.raycast.h.mx > 1500)
		{
			all->player.raycast.v.depth = MAX_DEPTH;
			break ;
		}
		if (map[all->player.raycast.v.my][all->player.raycast.v.mx]
			&& map[all->player.raycast.v.my][all->player.raycast.v.mx] == '1')
			all->player.raycast.v.depth = MAX_DEPTH;
		else
		{
			all->player.raycast.v.y += all->player.raycast.v.y_offset;
			all->player.raycast.v.x += 1 / tan(all->player.raycast.angle);
			all->player.raycast.v.mx = (int)all->player.raycast.v.x;
			all->player.raycast.v.my = (int)all->player.raycast.v.y;
			all->player.raycast.v.depth += 1;
		}
	}
}


// fonction pour calculer la distance du rayon
// marche en calculant l'hypotenus
// calcul rapide: hyp = racine de a^2 + b^2
// comme on a 2 poitns et qu'il peuvent etre negatif:  
//
double		cal_hyp(double a, double b, double c, double d)
{
	double	ac;
	double	bd;
	double	result;

	ac = fabs(a - c);
	bd = fabs(b - d);
	result = sqrt(pow(ac, 2) + pow(bd, 2));
	return (result);
}

void	draw_all(t_all *all)
{
	int		i;
	char	**map;

	i = 0;
	map = all->map.map;
	all->player.raycast.angle = all->player.angle;
	set_offset(all);
	draw_vert(all);
	draw_hor(all);
	all->player.raycast.h.mx = (int)all->player.raycast.h.x;
	all->player.raycast.h.my = (int)all->player.raycast.h.y;
	all->player.raycast.v.mx = (int)all->player.raycast.v.x;
	all->player.raycast.v.my = (int)all->player.raycast.v.y;
	while ((all->player.raycast.v.depth < MAX_DEPTH && all->player.raycast.v.depth < MAX_DEPTH
		&& all->player.raycast.v.my < all->map.map_height) ||
		(all->player.raycast.h.depth < MAX_DEPTH && all->player.raycast.h.depth < MAX_DEPTH
		&& all->player.raycast.h.my < all->map.map_height))
	{
		if (all->player.raycast.v.my < 0 || all->player.raycast.h.mx < 0 || all->player.raycast.h.my > 1500 || all->player.raycast.h.mx > 1500)
		{
			all->player.raycast.v.depth = MAX_DEPTH;
			all->player.raycast.h.depth = MAX_DEPTH;
			break ;
		}
		printf("%f\n", cal_hyp(all->player.y, all->player.x, all->player.raycast.v.y, all->player.raycast.v.x));
		printf("%f\n", cal_hyp(all->player.y, all->player.x, all->player.raycast.h.y, all->player.raycast.h.x));
		if ((map[all->player.raycast.v.my][all->player.raycast.v.mx]
			&& map[all->player.raycast.v.my][all->player.raycast.v.mx] == '1')
			|| (map[all->player.raycast.h.my][all->player.raycast.h.mx]
			&& map[all->player.raycast.h.my][all->player.raycast.h.mx] == '1'))
			{
				all->player.raycast.v.depth = MAX_DEPTH;
				all->player.raycast.h.depth = MAX_DEPTH;
			}
		else
		{
			all->player.raycast.v.y += 1;
			all->player.raycast.v.x += 1 / tan(all->player.raycast.angle);
			all->player.raycast.v.mx = (int)all->player.raycast.v.x;
			all->player.raycast.v.my = (int)all->player.raycast.v.y;
			all->player.raycast.h.y += 1 * tan(all->player.raycast.angle);
			all->player.raycast.h.x += 1;
			all->player.raycast.h.mx = (int)all->player.raycast.h.x;
			all->player.raycast.h.my = (int)all->player.raycast.h.y;
			all->player.raycast.v.depth += 1;
			all->player.raycast.h.depth += 1;
		}
	}
}

void	drawraw_final(t_all *all)
{
	double	hit_vert;
	double	hit_hor;
	
	hit_vert = cal_hyp(all->player.y, all->player.x, all->player.raycast.v.y, all->player.raycast.v.x);
	hit_hor = cal_hyp(all->player.y, all->player.x, all->player.raycast.h.y, all->player.raycast.h.x);
	printf("hit vertical: %f - hit horizontal: %f\n", hit_vert, hit_hor);
	if (hit_vert < hit_hor)
		printf("Vertical hit first\n");
	else
		printf("Horizontal hit first\n");
}

void	drawray(t_all *all)
{
	set_offset(all);
	if (all->player.raycast.angle > (M_PI * 1.5) || all->player.raycast.angle < (M_PI / 2))
		drawray_hor(all, 1);
	else if (all->player.raycast.angle > M_PI && all->player.raycast.angle < (M_PI * 2))
		drawray_hor(all, -1);
	//if (all->player.raycast.angle < M_PI)
		drawray_ver(all);
	//else
	//	drawray_ver(all);
	// drawraw_final(all);
	//draw_all(all);
}