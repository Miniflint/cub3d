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

// void	drawray(t_all *all)
// {
// 	int		i;
// 	double	atan;

// 	i = 0;
// 	all->player.raycast.angle = all->player.angle;
// 	while (i++ < 1)
// 	{
// 		all->player.raycast.depth = 0;
// 		atan = -1 / tan(all->player.raycast.angle);
// 		printf("%f\n", tan(all->player.raycast.angle));
// 		if (all->player.raycast.angle > M_PI)
// 		{
// 			all->player.raycast.y = (int)all->player.y-0.000001;
// 			all->player.raycast.x = all->player.x-all->player.y * atan + all->player.x;
// 			all->player.raycast.y_offset = 0;
// 			all->player.raycast.x_offset = -all->player.raycast.y_offset * atan;
// 		}
// 		if (all->player.raycast.angle < M_PI)
// 		{
// 			all->player.raycast.y = (int)all->player.y;
// 			all->player.raycast.x = (all->player.x-all->player.y)*atan+all->player.x;
// 			all->player.raycast.y_offset = 0;
// 			all->player.raycast.x_offset = -all->player.raycast.y_offset * atan;
// 		}
// 		if ((all->player.raycast.angle <= 0.00001 && all->player.raycast.angle >= -0.00001)
// 			|| (all->player.raycast.angle <= M_PI + 0.00001 && all->player.raycast.angle >= M_PI - 0.00001)
// 			|| (all->player.raycast.angle <= 2 * M_PI + 0.00001 && all->player.raycast.angle >= 2 * M_PI - 0.00001))
// 		{
// 			all->player.raycast.x = all->player.x;
// 			all->player.raycast.y = all->player.y;
// 			all->player.raycast.depth = MAX_DEPTH;
// 		}
// 		while (all->player.raycast.depth < MAX_DEPTH)
// 		{
// 			// all->player.raycast.mx = (int)all->player.raycast.x;
// 			// all->player.raycast.my = (int)all->player.raycast.y;
// 			// printf("%d, %d\n", all->player.raycast.my, all->player.raycast.mx);
// 			// if (!all->map.map[all->player.raycast.my][all->player.raycast.mx])
// 			// 	break ;
// 			// if (all->map.map[all->player.raycast.my][all->player.raycast.mx]
// 			// 	&& all->map.map[all->player.raycast.my][all->player.raycast.mx] == '1')
// 			// 	all->player.raycast.depth = MAX_DEPTH;
// 			// else
// 			// {
// 			// 	all->player.raycast.x += all->player.raycast.x_offset;
// 			// 	all->player.raycast.y += all->player.raycast.y_offset;
// 			// 	all->player.raycast.depth += 1;
// 			// }
// 			all->player.raycast.depth += 1;
// 		}
// 	}
// }

void	drawray(t_all *all)
{
	(void)all;
}