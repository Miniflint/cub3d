/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nully.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:50:11 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/19 14:11:06 by sbars            ###   ########.fr       */
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
	txtr->r = NULL;
	txtr->no = NULL;
	txtr->so = NULL;
	txtr->we = NULL;
	txtr->ea = NULL;
	// txtr->no_img = NULL;
	// txtr->so_img = NULL;
	// txtr->we_img = NULL;
	// txtr->ea_img = NULL;
	i = -1;
	while (++i < 3)
	{
		txtr->f_int[i] = -1;
		txtr->c_int[i] = -1;
		if (i < 2)
			txtr->r_int[i] = -1;
	}
}

static void	map_nully(t_map *map)
{
	map->map = NULL;
	map->file = NULL;
	map->map_array = NULL;
	map->map_height = 0;
}

static void	set_movement(t_movement *moves)
{
	moves->key_w = 0;
	moves->key_a = 0;
	moves->key_s = 0;
	moves->key_d = 0;
	moves->arr_left = 0;
	moves->arr_right = 0;
}

static void ray_nully(t_raycast *ray)
{
	ray->r = 0;
	ray->mx = 0;
	ray->my = 0;
	ray->mp = 0;
	ray->depth = 0;
	ray->x = 0;
	ray->y = 0;
	ray->angle = 0;
	ray->x_offset = 0;
	ray->y_offset = 0;
}

static void	player_nully(t_player *player)
{
	player->x = -1;
	player->y = -1;
	player->dx = 0;
	player->dy = 0;
	player->angle = 0;
	player->letter = '\0';
	player->angle_per_key = 0;
	set_movement(&(player->moves));
	ray_nully(&(player->raycast));
}

void	everything_null(t_all *all)
{
	txtr_nully(&(all->txtr));
	map_nully(&(all->map));
	player_nully(&(all->player));
}
