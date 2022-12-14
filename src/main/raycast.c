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

void	drawray(t_all *all)
{
	int		i;
	double	atan;

	i = 0;
	all->player.raycast.ra = all->player.angle;
	while (i++ < 1)
	{
		all->player.raycast.dof = 0;
		atan = -1 / tan(all->player.raycast.ra);
		if (all->player.raycast.ra == 0 || all->player.raycast.ra == M_PI)
		{
			all->player.raycast.rx = all->player.x;
			all->player.raycast.ry = all->player.y;
			all->player.raycast.dof = MAX_DEPTH;
		}
		if (all->player.raycast.ra > M_PI)
		{
			all->player.raycast.ry = (((int)all->player.y>>6)<<6)-0.000001;
			all->player.raycast.rx = (all->player.x-all->player.y)*atan+all->player.x;
			all->player.raycast.yo = -64;
			all->player.raycast.xo = -all->player.raycast.yo * atan;
		}
		if (all->player.raycast.ra < M_PI)
		{
			all->player.raycast.ry = (((int)all->player.y>>6)<<6)+64;
			all->player.raycast.rx = (all->player.x-all->player.y)*atan+all->player.x;
			all->player.raycast.yo = 64;
			all->player.raycast.xo = -all->player.raycast.yo * atan;
		}
		while (all->player.raycast.dof < MAX_DEPTH)
		{
			all->player.raycast.mx = (int)(all->player.raycast.rx)>>6;
			all->player.raycast.my = (int)(all->player.raycast.ry)>>6;
			if (all->map.map[all->player.raycast.my][all->player.raycast.mx]
				&& all->map.map[all->player.raycast.my][all->player.raycast.mx] == '1')
				all->player.raycast.dof = MAX_DEPTH;
			else
			{
				all->player.raycast.rx += all->player.raycast.xo;
				all->player.raycast.ry += all->player.raycast.yo;
				all->player.raycast.dof += 1;
			}
		}
		printf("I HITTED A WALL AT: x: %d - y: %d\n", all->player.raycast.rx, all->player.raycast.ry);
	}
}