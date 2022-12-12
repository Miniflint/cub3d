/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:58:16 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/12 14:13:17 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// fuck this
// i hate it
// this fonction worked the first time when i wrote it without any compiler error
// elle me clc cette fonction c'est imcompréhensible mais en gros
// ça check tout les coté (gauche|droite|haut|bas) pour voir si le char FILL
// se trouve à coté de:
// vide
// espace
// ou si c'est au bord de la map
// la fonction est pas compliquée a comprendre de principe mais chiante à écrire
static int	norminette_i_hate_u(char **m, int i, int j)
{
	if (i <= 0 || j <= 0)
		return (1);
	if (!m[i - 1] || !m[i - 1][j])
		return (2);
	if (m[i - 1][j] == ' ')
		return (2);
	if (!m[i][j - 1])
		return (3);
	if (m[i][j - 1] == ' ')
		return (3);
	if (!m[i + 1] || !m[i + 1][j])
		return (4);
	if (m[i + 1][j] == ' ')
		return (4);
	if (!m[i][j + 1])
		return (5);
	if (m[i][j + 1] == ' ')
		return (5);
	return (0);
}

// prend la map modifiée et cherche si le char FILL (voir ci dessus les conditions)
int	check_map_open(char **modified_map)
{
	int	i;
	int	j;

	i = -1;
	while (modified_map[++i])
	{
		j = -1;
		while (modified_map[i][++j])
			if (modified_map[i][j] == FILL)
				if (norminette_i_hate_u(modified_map, i, j))
					return (1);
	}
	return (0);
}
