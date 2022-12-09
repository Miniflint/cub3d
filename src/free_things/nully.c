/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nully.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:50:11 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/09 13:51:11 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	txtr_nully(t_all *all)
{
	int	i;

	all->txtr.f = NULL;
	all->txtr.c = NULL;
	all->txtr.no = NULL;
	all->txtr.so = NULL;
	all->txtr.we = NULL;
	all->txtr.ea = NULL;
	i = -1;
	while (++i < 3)
	{
		all->txtr.f_int[i] = -1;
		all->txtr.c_int[i] = -1;
	}
}

static void	map_nully(t_all *all)
{
	all->map.map = NULL;
	all->map.file = NULL;
	all->map.map_array = NULL;
}

static void	player_nully(t_all *all)
{
	all->player.x = 0;
	all->player.y = 0;
}

void	everything_null(t_all *all)
{
	all->raycast = NULL;
	txtr_nully(all);
	map_nully(all);
	player_nully(all);
}
