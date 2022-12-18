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
// 		all->player.raycast.depth = 0;
// 		matan =  atan(all->player.raycast.angle);
// 		printf("%f\n", matan);
// 		if (all->player.raycast.angle > M_PI)
// 		{
// 			all->player.raycast.y = (int)all->player.y-0.000001;
// 			all->player.raycast.x = all->player.x-all->player.y * matan + all->player.x;
// 			all->player.raycast.y_offset = -1;
// 			all->player.raycast.x_offset = all->player.raycast.y_offset * matan;
// 		}
// 		if (all->player.raycast.angle < M_PI)
// 		{
// 			all->player.raycast.y = (int)all->player.y;
// 			all->player.raycast.x = (all->player.x-all->player.y)*matan+all->player.x;
// 			all->player.raycast.y_offset = -1;
// 			all->player.raycast.x_offset = all->player.raycast.y_offset * matan;
// 		}
// 		if ((all->player.raycast.angle <= 0.00001 && all->player.raycast.angle >= -0.00001)
// 			|| (all->player.raycast.angle <= M_PI + 0.00001 && all->player.raycast.angle >= M_PI - 0.00001)
// 			|| (all->player.raycast.angle <= 2 * M_PI + 0.00001 && all->player.raycast.angle >= 2 * M_PI - 0.00001))
// 		{
// 			all->player.raycast.x = all->player.x;
// 			all->player.raycast.y = all->player.y;
// 			all->player.raycast.depth = MAX_DEPTH;
// 		}
// 		printf("y: %f -x: %f -oy: %f - ox: %f\n", all->player.raycast.y, all->player.raycast.x, all->player.raycast.y_offset, all->player.raycast.x_offset);
// 		while (all->player.raycast.depth < MAX_DEPTH)
// 		{
// 			all->player.raycast.mx = (int)all->player.raycast.x;
// 			all->player.raycast.my = (int)all->player.raycast.y;
// 			if (all->map.map[all->player.raycast.my][all->player.raycast.mx]
// 				&& all->map.map[all->player.raycast.my][all->player.raycast.mx] == '1')
// 				all->player.raycast.depth = MAX_DEPTH;
// 			else
// 			{
// 				all->player.raycast.x += all->player.raycast.x_offset;
// 				all->player.raycast.y += all->player.raycast.y_offset;
// 				all->player.raycast.depth += 1;
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

void	drawray(t_all *all)
{
	int		i;
	char	**map;

	i = 0;
	map = all->map.map;
	all->player.raycast.angle = all->player.angle;
	all->player.raycast.y_offset = 1 - delete_virgule(all->player.y);
	all->player.raycast.x_offset = 1 - delete_virgule(all->player.x);
	all->player.raycast.depth = 0;
	while (i++ < 1)
	{
		if (all->player.raycast.angle > 0 && all->player.raycast.angle < (M_PI / 2))
		{
			all->player.raycast.x =  all->player.x + all->player.raycast.x_offset / tan(all->player.raycast.angle);
			all->player.raycast.y = all->player.y + all->player.raycast.y_offset;
			//printf("%f\n", all->player.raycast.x_offset / tan(all->player.raycast.angle));
			//printf("%f - %f\n", all->player.raycast.y, all->player.raycast.x);
		}
		while (all->player.raycast.depth < MAX_DEPTH)
		{
			all->player.raycast.mx = (int)all->player.raycast.x;
			all->player.raycast.my = (int)all->player.raycast.y;
			if (map[all->player.raycast.my][all->player.raycast.mx]
				&& map[all->player.raycast.my][all->player.raycast.mx] == '1')
				all->player.raycast.depth = MAX_DEPTH;
			else
			{
				all->player.raycast.my += 1;
				all->player.raycast.mx += 1;
				all->player.raycast.depth += 1;
			}
		}

	}
	print_wth_is_that(all->player.raycast);
}