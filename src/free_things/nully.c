/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nully.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:50:11 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/11 18:15:10 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* FICHIER
 * POUR
 * METTRE
 * TOUT
 * A
 * NULL
 *
 * MAIS
 *
 * GENRE
 *
 * ABOSLUMENT
 *
 * TOUT
 * (j'ai eu des problèmes au débuts quand je l'avais pas
 * j'ai pas testé de l'enlever encore j'avoue j'ai pas le courage si ça marche pas)
*/

static void	txtr_nully(t_textures *txtr)
{
	int	i;

	txtr->f = NULL;
	txtr->c = NULL;
	txtr->no = NULL;
	txtr->so = NULL;
	txtr->we = NULL;
	txtr->ea = NULL;
	i = -1;
	while (++i < 3)
	{
		txtr->f_int[i] = -1;
		txtr->c_int[i] = -1;
	}
}

static void	map_nully(t_map *map)
{
	map->map = NULL;
	map->file = NULL;
	map->map_array = NULL;
	map->map_height = 0;
}

static void	player_nully(t_player *player)
{
	player->letter = '\0';
	player->start_x = -1;
	player->start_y = -1;
	player->x = -1;
	player->y = -1;
}

void	everything_null(t_all *all)
{
	all->raycast = NULL;
	txtr_nully(&(all->txtr));
	map_nully(&(all->map));
	player_nully(&(all->player));
}
