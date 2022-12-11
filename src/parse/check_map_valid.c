/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:58:16 by tgoel             #+#    #+#             */
/*   Updated: 2022/12/11 19:01:14 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	norminette_i_hate_u(char **m, int i, int j)
{
	if (m[i][j] != FILL)
		return (0);
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